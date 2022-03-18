#include "Controller.hpp"

#include <QException>

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

    { // debug only
        _loggingThread.setObjectName("Logging thread");
        _serverThread.setObjectName("Service thread");
        _databaseThread.setObjectName("Database driver thread");
    }

    ui->actionToggle_server->setEnabled(false);

    _listenIndicator = new QLabel("Offline");
    ui->statusbar->addPermanentWidget(_listenIndicator);

    ui->page_path_layout->setAlignment(Qt::AlignLeft);

    ui->actionToggle_server->setText("Start");

    connect(ui->clearLogButton, SIGNAL(clicked()), this, SLOT(on_clearLogClicked()));
    ui->logLevel_cb->setCurrentIndex(_settings.logginLeve);
    connect(ui->logLevel_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(changeLoggingLeve(int)));

    _pBars = new pSetProgress(this, QMargins(0, 0, 2, ui->statusbar->size().height() + 2));
    connect(this, SIGNAL(setProgress(int, int, QString, int)), _pBars, SIGNAL(setProgress(int, int, QString, int)));
    connect(this, SIGNAL(resized(QResizeEvent*)), _pBars, SIGNAL(windowResized(QResizeEvent*)));

    QTimer::singleShot(1000, [this]() {

        connect(&_timer1, &QTimer::timeout, [this]() { if (i1 >= im1) _timer1.stop(); Q_EMIT setProgress(++i1, im1, "Worker 1", 4);});
        connect(&_timer2, &QTimer::timeout, [this]() { if (i2 >= im2) _timer2.stop(); Q_EMIT setProgress(++i2, im2, "Worker 2", 9);});
        connect(&_timer3, &QTimer::timeout, [this]() { if (i3 >= im3) _timer3.stop(); Q_EMIT setProgress(++i3, im3, "Worker 3", 3);});
        connect(&_timer4, &QTimer::timeout, [this]() { if (i4 >= im4) _timer4.stop(); Q_EMIT setProgress(++i4, im4, "Worker 4", 5);});

        _timer1.start(100);
        _timer2.start(600);
        _timer3.start(200);
        _timer4.start(300);

    });

    setupLogger();
    setupDatabase();

    _loggingThread.start();
    _serverThread.start();
    _databaseThread.start();

}

Controller::~Controller()
{
    _database.Stop();

    _loggingThread.quit();
    _serverThread.quit();
    _databaseThread.quit();

    _loggingThread.wait();
    _serverThread.wait();
    _databaseThread.wait();

    delete _listenIndicator;
    delete ui;
}

void
Controller::setupPages()
{
    QWidget * main          = new WelcomePage(ui->page_view),
            * controlPannel = new ControlPannel(ui->page_view),
            * service       = new ServerInfoPage(ui->page_view),
            * connections   = new ConnectionsPage(ui->page_view),
            * users         = new Users(ui->page_view),
            * registerUser  = new RegisterUser(_database.avalibleRoles(), ui->page_view),
            * usersList     = new UsersList(_database.avalibleRoles(), ui->page_view);

    // can i automize creation? may be

    PagesManager::addRoot("Main",           main,          (int)NavPages::Main,          {"Control Pannel", "Load", "Settings", "Help"});
    PagesManager::addPage("Control Pannel", controlPannel, (int)NavPages::ControlPannel, {"Service", "Connections", "Users"});
    PagesManager::addPage("Service",        service,       (int)NavPages::ControlPannel);
    PagesManager::addPage("Connections",    connections,   (int)NavPages::ControlPannel);
    PagesManager::addPage("Users",          users,         (int)NavPages::Users,         {"Register user", "Users list"});
    PagesManager::addPage("Users list",     usersList,     (int)NavPages::Users);
    PagesManager::addPage("Register user",  registerUser,  (int)NavPages::Users);
    ui->page_view->addWidget(main);
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

    changePage(_settings.defultPage.length() ? _settings.defultPage : "Main");

    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            service, SLOT(onServerListningStateChanged(QHostAddress, quint16, bool)));

    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(changeIndicatorState(QHostAddress, quint16, bool)));
    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(on_listeningStateChanged(QHostAddress, quint16, bool)));

    connect(registerUser, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)));
    connect(registerUser, SIGNAL(registrateUser(Database::RoleId, QJsonObject, Database::DriverAssistant*)),
            &_database,    SIGNAL(addCommand(Database::RoleId, QJsonObject, Database::DriverAssistant*)), Qt::DirectConnection);
    connect(registerUser, SIGNAL(requestedWaponDetails(Database::RoleId, QJsonObject, Database::DriverAssistant*)),
            &_database,    SIGNAL(addCommand(Database::RoleId, QJsonObject, Database::DriverAssistant*)), Qt::DirectConnection);

    connect(usersList, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)));
    connect(usersList, SIGNAL(requestedUsers(Database::RoleId, QJsonObject, Database::DriverAssistant*)),
            &_database, SIGNAL(addCommand(Database::RoleId, QJsonObject, Database::DriverAssistant*)), Qt::DirectConnection);
}

void
Controller::setupLogger()
{
    connect(this, SIGNAL(send_to_log(QString, int)), &_log, SLOT(logMessage(QString, int)), Qt::DirectConnection);
    _log.moveToThread(&_loggingThread);
}

void
Controller::setupDatabase()
{
    connect(&_database, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)), Qt::DirectConnection);

    // inited -> setup service -> setup pages
    connect(&_database, SIGNAL(Inited()),
            this, SLOT(on_databaseInited()), Qt::DirectConnection);
    connect(&_database, SIGNAL(Inited()),
            this, SLOT(setupServer()));
    connect(&_database, SIGNAL(Inited()),
            this, SLOT(setupPages()));
    connect(&_database, SIGNAL(InitizlizationFailed(QSqlError)),
            this, SLOT(on_databaseInitializationFailed(QSqlError)), Qt::DirectConnection);

    connect(&_database, SIGNAL(setProgress(int, int, QString, int)), this, SIGNAL(setProgress(int, int, QString, int)), Qt::DirectConnection);

    connect(&_databaseThread, SIGNAL(started()), &_database, SLOT(Run()), Qt::DirectConnection);
    _database.moveToThread(&_databaseThread);
}

void
Controller::setupServer()
{
    _server.setForseUseSsl(_settings.useSsl);
    _server.LoadCertificates(_settings.certPath, _settings.keyPath);

    connect(&_server, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)), Qt::DirectConnection);

    _server.moveToThread(&_serverThread);
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
Controller::changePage(QString page)
{
    // todo
    // clear current path
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
        clbl->setFont(QFont("Sans", 9));
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
        static_cast<QLabel*>(_listenIndicator)->setText(tr("Listening"));
    } else {
        static_cast<QLabel*>(_listenIndicator)->setText(tr("Offline"));
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

void
Controller::on_actionQuit_triggered()
{
    QApplication::quit();
}

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
    if (level >= _settings.logginLeve) {
        ui->loggingOutput->append(str);
    }
        /* // ignore setted logging level, its need? */
    Q_EMIT send_to_log(str, level);
}

void
Controller::on_clearLogClicked()
{
    ui->loggingOutput->clear();
}
