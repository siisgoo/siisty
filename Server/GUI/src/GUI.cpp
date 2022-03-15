#include "GUI.hpp"

#include <QException>

#include "./ui_GUI.h"
#include <qnamespace.h>

#include "Database/Database.hpp"

GUI::GUI(Settings settings, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI),
        _settings(settings)
{
    ui->setupUi(this);

    ui->actionToggle_server->setEnabled(false);
        // enabled after successfully inited db

    setupLogger();
    setupServer();
    setupDatabase();
    adjustUi();

    _databaseThread.start();
    _loggingThread.start();
    _serverThread.start();

}

GUI::~GUI()
{
    _loggingThread.quit();
    _serverThread.quit();

    _loggingThread.wait();
    _serverThread.wait();

    if (_database) {
        _database->Stop();
        _databaseThread.quit();
        _databaseThread.wait();
        delete _database;
    }
    delete _server;
    delete _log;
    delete _listenIndicator;
    delete ui;
}

void
GUI::changeServeAddress(QHostAddress& add, quint16 port)
{
    if (_settings.serveAddress != add || _settings.servePort != port ) {
        _settings.serveAddress = add;
        _settings.servePort = port;

        if (_server->isListening()) {

            Q_EMIT logMessage("Rebooting server after change Serve address and port", Debug);
            _server->ToggleStartStopListening(add, port);
            _server->ToggleStartStopListening(add, port);
        }
    }
}

void
GUI::changeLoggingLeve(int level)
{
    if (_log->loggingLevel() != level) {
        Q_EMIT logMessage("Logging level changed to: " + QString::number(level), Fatal);
        _log->setLoggingLevel(level);
    }
}

void
GUI::adjustUi()
{
    QWidget * main          = new WelcomePage(ui->page_view),
            * controlPannel = new ControlPannel(ui->page_view),
            * service       = new ServerInfoPage(ui->page_view),
            * connections   = new ConnectionsPage(ui->page_view),
            * users         = new Users(ui->page_view),
            * registerUser  = new RegisterUser(ui->page_view),
            * usersList     = new UsersList(ui->page_view);

    // can i automize creation? may be
    _pagesPath.setRoot("Main");
    _pagesPath.addEdge("Main", {"Control Pannel", "Load", "Settings", "Help"});
    _pagesPath.addEdge("Control Pannel", {"Service", "Connections", "Users"});
    _pagesPath.addEdge("Users", {"Register user", "Users list"});

    PagesManager::addPage("Main",           main,          (int)NavPages::Main);
    PagesManager::addPage("Control Pannel", controlPannel, (int)NavPages::ControlPannel);
    PagesManager::addPage("Service",        service,       (int)NavPages::ControlPannel);
    PagesManager::addPage("Connections",    connections,   (int)NavPages::ControlPannel);
    PagesManager::addPage("Users",          users,         (int)NavPages::Users);
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
    connect(ui->open_ControlPannelBtn,   &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Control Pannel"); });
    connect(ui->open_LoadBtn,            &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Load"); });
    connect(ui->open_SettingsBtn,        &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Settings"); });
    connect(ui->open_HelpBtn,            &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Help"); });

    connect(ui->open_ServiceBtn,         &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Service"); });
    connect(ui->open_ConneectionsBtn,    &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Connections"); });
    connect(ui->open_Users,              &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Users"); });
    connect(ui->open_Main,               &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Main"); });

    connect(ui->open_RegisterUserBtn,    &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Register user"); });
    connect(ui->open_UsersListBtn,       &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Users list"); });
    connect(ui->open_ControlPannelBtn_2, &QPushButton::clicked, [this]() { Q_EMIT pageChanged("Control Pannel"); });

    connect(this, SIGNAL(pageChanged(QString)), this, SLOT(on_pageChanged(QString)));

    Q_EMIT pageChanged(_defaultPage.length() ? _defaultPage : "Main");

    connect(_server,
            SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            PagesManager::getPage("Service"),
            SLOT(onServerListningStateChanged(QHostAddress, quint16, bool)));

    connect(_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(changeIndicatorState(QHostAddress, quint16, bool)));
    connect(_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(on_listeningStateChanged(QHostAddress, quint16, bool)));

    _listenIndicator = new QLabel("Offline");
    ui->statusbar->addPermanentWidget(_listenIndicator);

    _progress = new QProgressBar(ui->statusbar);
    _progress->setMaximumHeight(ui->statusbar->size().height() * 0.4);
    _progress->setMaximumWidth(this->size().width() * 0.3);
    _progress->setFormat("");
    _progress->hide();

    ui->statusbar->addWidget(_progress);

    ui->actionToggle_server->setText("Start");

    connect(ui->clearLogButton, SIGNAL(clicked()), this, SLOT(on_clearLogClicked()));

    ui->logLevel_cb->setCurrentIndex(_settings.logginLeve);
    connect(ui->logLevel_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(changeLoggingLeve(int)));

    Q_EMIT pageChanged("Main");
}

void
GUI::setupLogger()
{
    _log = new logger(Trace, "sIIsTy-Server", nullptr);
    connect(this, SIGNAL(send_to_log(QString, int)), _log, SLOT(logMessage(QString, int)), Qt::DirectConnection);
    _log->moveToThread(&_loggingThread);
}

void
GUI::setupDatabase()
{
    _database = new Database::SQLite(_settings.databasePath, nullptr);
    connect(_database, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)), Qt::DirectConnection);
    connect(_database, SIGNAL(failed(Database::CmdError)), this, SLOT(on_databaseError(Database::CmdError)), Qt::DirectConnection);

    connect(_database, SIGNAL(Inited()), this, SLOT(on_databaseInited()), Qt::DirectConnection);
    connect(_database, SIGNAL(InitizlizationFailed(QSqlError)), this, SLOT(on_databaseInitializationFailed(QSqlError)), Qt::DirectConnection);

    connect(_database, SIGNAL(setProgress(int, int)), this, SLOT(setProgress(int, int)), Qt::DirectConnection);

    connect(this, SIGNAL(addCommand(Database::RoleId, QJsonObject&)), _database, SIGNAL(addCommand(Database::RoleId, QJsonObject&)), Qt::DirectConnection);

    connect(&_databaseThread, SIGNAL(started()), _database, SLOT(Run()), Qt::DirectConnection);
    _database->moveToThread(&_databaseThread);
}

void
GUI::setupServer()
{
    _server = new iiServer(nullptr);
    _server->setForseUseSsl(_settings.useSsl);
    _server->LoadCertificates(_settings.certPath, _settings.keyPath);

    connect(_server, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)), Qt::DirectConnection);

    _server->moveToThread(&_serverThread);
}

void
GUI::on_pageChanged(QString page)
{
    QVector<QString> path = _pagesPath.pathFor(page);

    // todo
    // clear current path
    QLayoutItem * itm;
    while ((itm = ui->page_path_layout->takeAt(0)) != nullptr) {
        delete itm->widget();
        delete itm;
    }

    ui->page_path_layout->setAlignment(Qt::AlignLeft);
    for (auto node : path) {
        QWidget * lbl = new QLabel("->");
        lbl->setFont(QFont("Iosevka", 9));
        lbl->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        ui->page_path_layout->addWidget(lbl);
        ClickableLabel * clbl = new ClickableLabel(node);
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
GUI::on_pathNodeClicked()
{
    ClickableLabel * lbl = dynamic_cast<ClickableLabel*>(sender());
    QString txt = lbl->text();
    Q_EMIT pageChanged(txt);
}

void
GUI::changeIndicatorState(QHostAddress address, quint16 port, bool listening)
{
    if (listening) {
        static_cast<QLabel*>(_listenIndicator)->setText(tr("Listening"));
    } else {
        static_cast<QLabel*>(_listenIndicator)->setText(tr("Offline"));
    }
}

void
GUI::on_listeningStateChanged(QHostAddress dummy, quint16 dummy1, bool listening)
{
    if (listening) {
        ui->actionToggle_server->setText("Stop");
    } else {
        ui->actionToggle_server->setText("Start");
    }
}

/* Default actions */

void
GUI::on_actionQuit_triggered()
{
    QApplication::quit();
}

void GUI::on_actionToggle_server_triggered()
{
    _server->ToggleStartStopListening(_settings.serveAddress, _settings.servePort);
}

void
GUI::on_databaseError(Database::CmdError err)
{
    Q_EMIT logMessage(err.String(), LoggingLevel::Error);
}

void
GUI::on_databaseInited()
{
    ui->actionToggle_server->setEnabled(true);
    ui->statusbar->clearMessage();
    Q_EMIT endProgress(); //may be connet directly?
}

void
GUI::on_databaseInitializationFailed(QSqlError e)
{
    ui->statusbar->showMessage("Database initialization error", 5*1000);
    Q_EMIT endProgress(); //may be connet directly?
    QString error = "Database initialization error: " + e.text() +
                    "\nDriver reason: " + e.driverText();
    logMessage(error, LoggingLevel::Fatal);
    _databaseThread.quit();
    _databaseThread.wait();
    delete _database;
    _database = nullptr;
}

void
GUI::logMessage(QString str, int level)
{
    ui->loggingOutput->append(str);
        // ignore setted logging level, its need?
    Q_EMIT send_to_log(str, level);
}

void
GUI::setProgress(int cur, int max)
{
    if (_progress->isHidden()) {
        _progress->show();
    }

    _progress->setRange(0, max);
    _progress->setValue(cur);
}

void
GUI::endProgress()
{
    _progress->hide();
}

void
GUI::on_clearLogClicked()
{
    ui->loggingOutput->clear();
}
