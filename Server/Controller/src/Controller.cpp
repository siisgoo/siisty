#include "Controller.hpp"

#include <QException>
#include "Widgets/QLedIndicator.hpp"

#include "./ui_Controller.h"
#include <qnamespace.h>

#include <QErrorMessage>

#include "Database/Database.hpp"

Controller::Controller(Settings settings, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Controller),
        _settings(settings),
        _log(_settings.logginLeve, "siisty-server", nullptr),
        _server(nullptr),
        _database(_settings.databasePath)
{
    ui->setupUi(this);

    {
        ui->actionToggle_server->setEnabled(false);
        ui->actionToggle_server->setText("Start");

        ui->statusbar->setFixedHeight(22);
        _listenIndicator = new QLedIndicator(ui->statusbar);
        ui->statusbar->layout()->setAlignment(Qt::AlignCenter);
        _listenIndicator->setLedSize(14);
        ui->statusbar->addPermanentWidget(_listenIndicator);

        ui->page_path_layout->setAlignment(Qt::AlignLeft);

        connect(ui->clearLogButton, SIGNAL(clicked()), this, SLOT(on_clearLogClicked()));
        ui->logLevel_cb->setCurrentIndex(_settings.logginLeve);
        connect(ui->logLevel_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(changeLoggingLeve(int)));
    }

    {
        _notifier = new FloatNotifier(
                this,
                QMargins(0, 0, 2, ui->statusbar->size().height() + 2),
                {120, 40},
                10,
                3000,
                FloatNotifier::StackAbove);
        connect(this, SIGNAL(resized(QResizeEvent*)), _notifier, SIGNAL(windowResized(QResizeEvent*)));
        connect(this,
                SIGNAL(createNotifyItem(NotifyItemFactory*, int&)),
                _notifier,
                SLOT(createNotifyItem(NotifyItemFactory*, int&)));
        connect(this,
                SIGNAL(setNotifyItemPropery(int, const QByteArray &, const QVariant &)),
                _notifier,
                SLOT(setItemPropery(int, const QByteArray &, const QVariant &)));
    }

    NotifyProgressItemFactory * fa = new NotifyProgressItemFactory();
    /* fa->setTitle("Dummy"); */
    /* fa->setNotifyLevel(NotifyItem::NotififyNormal); */
    /* fa->setMaximum(100); */
    /* fa->setExitOnCompleted(true); */
    /* Q_EMIT createNotifyItem(fa, item_uid1); */
    /* fa->setTitle("Dummy 1"); */
    /* Q_EMIT createNotifyItem(fa, item_uid2); */
    /* fa->setTitle("Dummy 2"); */
    /* Q_EMIT createNotifyItem(fa, item_uid3); */
    /* fa->setTitle("Dummy 3"); */
    /* Q_EMIT createNotifyItem(fa, item_uid4); */

    /* QTimer * timer1 = new QTimer; */
    /* QTimer * timer2 = new QTimer; */
    /* QTimer * timer3 = new QTimer; */
    /* QTimer * timer4 = new QTimer; */

    /* connect(timer1, &QTimer::timeout, [this](){ Q_EMIT setNotifyItemPropery(item_uid1, "progress", i1++); Q_EMIT setNotifyItemPropery(item_uid1, "title", "DUmmy " + QString::number(i1)); }); */
    /* connect(timer2, &QTimer::timeout, [this](){ Q_EMIT setNotifyItemPropery(item_uid2, "progress", i2++); Q_EMIT setNotifyItemPropery(item_uid2, "title", "DUmmy " + QString::number(i2)); }); */
    /* connect(timer3, &QTimer::timeout, [this](){ Q_EMIT setNotifyItemPropery(item_uid3, "progress", i3++); Q_EMIT setNotifyItemPropery(item_uid3, "title", "DUmmy " + QString::number(i3)); }); */
    /* connect(timer4, &QTimer::timeout, [this](){ Q_EMIT setNotifyItemPropery(item_uid4, "progress", i4++); Q_EMIT setNotifyItemPropery(item_uid4, "title", "DUmmy " + QString::number(i4)); }); */

    /* timer1->start(100); */
    /* timer2->start(250); */
    /* timer3->start(130); */
    /* timer4->start(310); */

    {
        connect(this, SIGNAL(send_to_log(QString, int)), &_log, SLOT(logMessage(QString, int)), Qt::DirectConnection);
        _log.moveToThread(&_loggingThread);
    }

    {
        connect(&_database, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)), Qt::DirectConnection);

        // inited -> setup service -> setup pages
        connect(&_database, SIGNAL(Inited()),
                this, SLOT(on_databaseInited()), Qt::QueuedConnection);
        connect(&_database, SIGNAL(Inited()),
                this, SLOT(setupServer()), Qt::QueuedConnection);
        connect(&_database, SIGNAL(Inited()),
                this, SLOT(connectPages()));
        connect(&_database, SIGNAL(InitizlizationFailed(QSqlError)),
                this, SLOT(on_databaseInitializationFailed(QSqlError)));

        connect(&_database,
                SIGNAL(createNotifyItem(NotifyItemFactory *, int&)),
                _notifier,
                SLOT(createNotifyItem(NotifyItemFactory *, int&)),
                Qt::BlockingQueuedConnection);
        connect(&_database,
                SIGNAL(setNotifyItemPropery(int, const QByteArray &, const QVariant &)),
                _notifier,
                SLOT(setItemPropery(int, const QByteArray &, const QVariant &)),
                Qt::BlockingQueuedConnection);

        connect(&_databaseThread, SIGNAL(started()), &_database, SLOT(Run()), Qt::DirectConnection);
        _database.moveToThread(&_databaseThread);
    }

    setupPages();

    _loggingThread.start();
    _databaseThread.start();

    _loggingThread.setObjectName("Logging thread");
    _serverThread.setObjectName("Service thread");
    _databaseThread.setObjectName("Database driver thread");
}

Controller::~Controller()
{
    _database.Stop();

    _databaseThread.quit();
    _loggingThread.quit();
    _serverThread.quit();

    _databaseThread.wait();
    _loggingThread.wait();
    _serverThread.wait();

    delete _notifier;
    delete _listenIndicator;
    delete ui;
}

void
Controller::setupServer()
{
    _server.moveToThread(&_serverThread);

    _server.setForseUseSsl(_settings.useSsl);
    _server.LoadCertificates(_settings.certPath, _settings.keyPath);

    connect(&_server, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)), Qt::DirectConnection);

    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(changeIndicatorState(QHostAddress, quint16, bool)));
    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(on_listeningStateChanged(QHostAddress, quint16, bool)));

    connect(&_server, SIGNAL(addCommand(Database::Driver::DatabaseCmd)),
            &_database, SLOT(addCommand(Database::Driver::DatabaseCmd)), Qt::QueuedConnection);

    _serverThread.start();
}

void
Controller::setupPages()
{
    QWidget * welcome       = new WelcomePage(ui->page_view),
            * controlPannel = new ControlPannel(ui->page_view),
            * service       = new ServerInfoPage(ui->page_view),
            * connections   = new ConnectionsPage(ui->page_view),
            * users         = new Users(ui->page_view),
            * registerUser  = new RegisterUser(_database.avalibleRoles(), ui->page_view),
            * usersList     = new UsersList(_database.avalibleRoles(), ui->page_view);

    // can i automize creation? may be

    QWidget * TMPmain = new QWidget(ui->page_view);

    PagesManager::addRoot("Main",           TMPmain,       (int)NavPages::Main,          { "Welcome", "Control Pannel", "Load", "Settings", "Help"});
    PagesManager::addPage("Welcome",        welcome,       (int)NavPages::Main);
    PagesManager::addPage("Control Pannel", controlPannel, (int)NavPages::ControlPannel, { "Service", "Connections", "Users"});
    PagesManager::addPage("Service",        service,       (int)NavPages::ControlPannel);
    PagesManager::addPage("Connections",    connections,   (int)NavPages::ControlPannel);
    PagesManager::addPage("Users",          users,         (int)NavPages::Users,         { "Register user", "Users list"});
    PagesManager::addPage("Users list",     usersList,     (int)NavPages::Users);
    PagesManager::addPage("Register user",  registerUser,  (int)NavPages::Users);
    ui->page_view->addWidget(TMPmain);
    ui->page_view->addWidget(welcome);
    ui->page_view->addWidget(controlPannel);
    ui->page_view->addWidget(service);
    ui->page_view->addWidget(connections);
    ui->page_view->addWidget(users);
    ui->page_view->addWidget(usersList);
    ui->page_view->addWidget(registerUser);

    // TODO avoid duplicating page names in diff pathes
    connect(ui->open_ControlPannelBtn,   &QPushButton::clicked, [this]() { changePage("Control Pannel"); });
    connect(ui->open_LoadBtn,            &QPushButton::clicked, [this]() { changePage("Load"); });
    connect(ui->open_SettingsBtn,        &QPushButton::clicked, [this]() { changePage("Settings"); });
    connect(ui->open_HelpBtn,            &QPushButton::clicked, [this]() { changePage("Help"); });

    connect(ui->open_ServiceBtn,         &QPushButton::clicked, [this]() { changePage("Service"); });
    connect(ui->open_ConneectionsBtn,    &QPushButton::clicked, [this]() { changePage("Connections"); });
    connect(ui->open_Users,              &QPushButton::clicked, [this]() { changePage("Users"); });
    connect(ui->open_Main,               &QPushButton::clicked, [this]() { changePage("Main"); });

    connect(ui->open_RegisterUserBtn,    &QPushButton::clicked, [this]() { changePage("Register user"); });
    connect(ui->open_UsersListBtn,       &QPushButton::clicked, [this]() { changePage("Users list"); });
    connect(ui->open_ControlPannelBtn_2, &QPushButton::clicked, [this]() { changePage("Control Pannel"); });

    QTimer::singleShot(100, [this]() { changePage(PagesManager::getPage(_settings.defultPage) ? _settings.defultPage : "Welcome"); });
}

void
Controller::connectPages()
{
    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            PagesManager::getPage("Service"), SLOT(onServerListningStateChanged(QHostAddress, quint16, bool)));

    connect(PagesManager::getPage("Register user"),
            SIGNAL(logMessage(QString, int)), this,
            SLOT(logMessage(QString, int)));
    connect(PagesManager::getPage("Register user"),
            SIGNAL(registrateUser(Database::RoleId, QJsonObject,
                                  Database::DriverAssistant *)),
            &_database,
            SLOT(addCommand(Database::RoleId, QJsonObject,
                            Database::DriverAssistant *)),
            Qt::DirectConnection);
    connect(PagesManager::getPage("Register user"),
            SIGNAL(requestedWaponDetails(Database::RoleId, QJsonObject,
                                         Database::DriverAssistant *)),
            &_database,
            SLOT(addCommand(Database::RoleId, QJsonObject,
                            Database::DriverAssistant *)),
            Qt::DirectConnection);

    connect(PagesManager::getPage("Users list"),
            SIGNAL(logMessage(QString, int)), this,
            SLOT(logMessage(QString, int)));
    connect(PagesManager::getPage("Users list"),
            SIGNAL(requestedUsers(Database::RoleId, QJsonObject,
                                  Database::DriverAssistant *)),
            &_database,
            SLOT(addCommand(Database::RoleId, QJsonObject,
                            Database::DriverAssistant *)),
            Qt::DirectConnection);
}

void
Controller::changePage(QString page)
{
    QLayoutItem * itm;
    while ((itm = ui->page_path_layout->takeAt(0)) != nullptr) {
        delete itm->widget();
        delete itm;
    }

    QVector<QString> path = PagesManager::getPagePath(page);
    for (auto node : path) {
        QWidget * lbl = new QLabel("->", ui->page_path_frame);
        lbl->setFont(QFont("Iosevka", 9));
        lbl->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        ui->page_path_layout->addWidget(lbl);
        ClickableLabel * clbl = new ClickableLabel(node, ui->page_path_frame);
        clbl->setFont(QFont("Monaco", 9));
        clbl->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        clbl->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        clbl->setStyleSheet("color: #b78620");
        connect(clbl, SIGNAL(clicked()), this, SLOT(on_pathNodeClicked()));
        ui->page_path_layout->addWidget(clbl);
    }

    ui->page_view->setCurrentWidget(PagesManager::getPage(page));
    ui->NavPages->setCurrentIndex(PagesManager::getPageNav(page));
}

void
Controller::changeServeAddress(QHostAddress& add, quint16 port)
{
    if (_settings.serveAddress != add || _settings.servePort != port ) {
        _settings.serveAddress = add;
        _settings.servePort = port;

        if (_server.isListening()) {

            Q_EMIT logMessage("Rebooting server after change Serve address and port", Debug);
            _server.ToggleStartStopListening(add, port);
            _server.ToggleStartStopListening(add, port);
        }
    }
}

void
Controller::changeLoggingLeve(int level)
{
    if (_log.loggingLevel() != level) {
        Q_EMIT logMessage("Logging level changed to: " + QString::number(level), Fatal);
        _log.setLoggingLevel(level);
    }
}

void
Controller::on_pathNodeClicked()
{
    ClickableLabel * lbl = dynamic_cast<ClickableLabel*>(sender());
    QString txt = lbl->text();
    changePage(txt);
}

void
Controller::changeIndicatorState(QHostAddress address, quint16 port, bool listening)
{
    if (listening) {
        _listenIndicator->setLedState(QLedIndicator::LedState::Active);
    } else {
        _listenIndicator->setLedState(QLedIndicator::LedState::Inactive);
    }
}

void
Controller::resizeEvent(QResizeEvent * e)
{
    e->accept();
    Q_EMIT resized(e);
}

void
Controller::on_listeningStateChanged(QHostAddress dummy, quint16 dummy1, bool listening)
{
    if (listening) {
        ui->actionToggle_server->setText("Stop");
    } else {
        ui->actionToggle_server->setText("Start");
    }
}

void Controller::on_actionQuit_triggered() { QApplication::quit(); }

void Controller::on_actionToggle_server_triggered()
{
    _server.ToggleStartStopListening(_settings.serveAddress, _settings.servePort);
}

void
Controller::on_databaseError(Database::CmdError err)
{
    Q_EMIT logMessage(err.String(), LoggingLevel::Error);
}

void
Controller::on_databaseInited()
{
    ui->actionToggle_server->setEnabled(true);
    ui->statusbar->clearMessage();
}

void
Controller::on_databaseInitializationFailed(QSqlError e)
{
    ui->statusbar->showMessage("Database initialization error", 5*1000);
    QString error = "Database initialization error: " + e.text() +
                    "\nDriver reason: " + e.driverText();
    logMessage(error, LoggingLevel::Fatal);
    QErrorMessage msg = QErrorMessage();
    msg.showMessage("Cannot initialize database!\nTerminating");
    this->on_actionQuit_triggered();
}

void
Controller::logMessage(QString str, int level)
{
    /* if (level >= _settings.logginLeve) { */
        ui->loggingOutput->append(str);
    /* } */
        /* // ignore setted logging level, its need? */
    Q_EMIT send_to_log(str, level);
}

void
Controller::on_clearLogClicked()
{
    ui->loggingOutput->clear();
}
