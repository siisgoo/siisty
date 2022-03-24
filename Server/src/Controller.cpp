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
        _log(_settings.logginLeve, "siisty-server", _settings.logDir, nullptr),
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

        connect(ui->clearLogButton, SIGNAL(clicked()), this, SLOT(on_clearLogClicked()));
        ui->logLevel_cb->setCurrentIndex(_settings.logginLeve);
        connect(ui->logLevel_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(changeLoggingLeve(int)));
    }

    {
        _notifier = new NotifyManager(
                this,
                QMargins(0, 0, 2, ui->statusbar->size().height() + 2),
                {120, 40},
                10,
                NotifyManager::StackAbove);
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

    {
        _pageman = new PagesManager(this);
        this->centralWidget()->layout()->addWidget(_pageman);
    }

    {
        connect(this, SIGNAL(send_to_log(QString, int)), &_log, SLOT(logMessage(QString, int)), Qt::DirectConnection);
        _log.moveToThread(&_loggingThread);
    }

    {
        connect(&_database, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)), Qt::DirectConnection);

        connect(&_database, SIGNAL(Inited()),
                this, SLOT(on_databaseInited()), Qt::QueuedConnection);
        connect(&_database, SIGNAL(Inited()),
                this, SLOT(setupServer()), Qt::QueuedConnection);
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

    {
        QWidget * welcome       = new WelcomePage(),
                * controlPannel = new ControlPannel(),
                * service       = new ServerInfoPage(),
                * connections   = new ConnectionsPage(),
                * users         = new Users(),
                * registerUser  = new RegisterUser(_database.avalibleRoles()),
                * usersList     = new UsersList(_database.avalibleRoles());

        QWidget * TMPmain = new QWidget();

        _pageman->addRoot("Main",           TMPmain,       { "Welcome",       "Control Pannel", "Load", "Settings", "Help"});
        _pageman->addPage("Welcome",        welcome);
        _pageman->addPage("Control Pannel", controlPannel, { "Service",       "Connections",    "Users"});
        _pageman->addPage("Service",        service);
        _pageman->addPage("Connections",    connections);
        _pageman->addPage("Users",          users,         { "Register user", "Users list"});
        _pageman->addPage("Users list",     usersList);
        _pageman->addPage("Register user",  registerUser);

        _pageman->finalize();

        /* // do connections */
        /* connect(&_database, &Database::Driver::Inited, */
        /*         [this, service, registerUser, usersList] { */
                    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
                            service, SLOT(onServerListningStateChanged(QHostAddress, quint16, bool)));

                    connect(registerUser, SIGNAL(logMessage(QString, int)),
                            this, SLOT(logMessage(QString, int)));
                    connect(registerUser,
                            SIGNAL(registrateUser(Database::DatabaseCmd)),
                            &_database,
                            SLOT(addCommand(Database::DatabaseCmd)),
                            Qt::DirectConnection);
                    connect(registerUser,
                            SIGNAL(requestedWaponDetails(Database::DatabaseCmd)),
                            &_database,
                            SLOT(addCommand(Database::DatabaseCmd)),
                            Qt::DirectConnection);

                    connect(usersList, SIGNAL(logMessage(QString, int)),
                            this, SLOT(logMessage(QString, int)));
                    connect(usersList,
                            SIGNAL(requestedUsers(Database::DatabaseCmd)),
                            &_database,
                            SLOT(addCommand(Database::DatabaseCmd)),
                            Qt::DirectConnection);
                /* }); */
    }

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
    /* _serverThread.quit(); */

    _databaseThread.wait();
    _loggingThread.wait();
    /* _serverThread.wait(); */

    delete _notifier;
    delete _listenIndicator;
    delete ui;
}

void
Controller::setupServer()
{
    _server.setForseUseSsl(_settings.useSsl);
    _server.LoadCertificates(_settings.certPath, _settings.keyPath);

    connect(&_server, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)), Qt::DirectConnection);

    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(changeIndicatorState(QHostAddress, quint16, bool)));
    connect(&_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(on_listeningStateChanged(QHostAddress, quint16, bool)));

    int cmd = qRegisterMetaType<Database::DatabaseCmd>();
    connect(&_server, SIGNAL(addCommand(Database::DatabaseCmd)),
            &_database, SLOT(addCommand(Database::DatabaseCmd)), Qt::QueuedConnection);
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

void Controller::on_clearLogClicked() { ui->loggingOutput->clear(); }
