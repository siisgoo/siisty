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
    QVector<QWidget*> l_pages({
            new WelcomePage(ui->page_view),
            new ServerInfoPage(ui->page_view),
            new ConnectionsPage(ui->page_view),
    });

    for (auto l_page : l_pages) {
        PagesManager::addPage(l_page);
        ui->page_view->addWidget(l_page);
    }

    // can i automize creation? may be
    _pagesPath = new PagesPath();

    _pagesPath->addEdge("Main", "Control Panel");
    _pagesPath->addEdge("Main", "Load");
    _pagesPath->addEdge("Main", "Settings");
    _pagesPath->addEdge("Main", "Help");
    _pagesPath->addEdge("Control Panel", "Service");
    _pagesPath->addEdge("Control Panel", "Connections");

    for (auto i : _pagesPath->pathFor("Connections")) {
        qDebug() << "Path: " << i;
    }

    // avoiding duplicating page names in diff pathes
    connect(ui->open_ControlPannelBtn, &QPushButton::clicked, [this]() { this->ui->NavPages->setCurrentIndex(NavPages::ControlPanel); });
    connect(ui->open_HelpBtn,          &QPushButton::clicked, [this]() {  });
    connect(ui->open_LoadBtn,          &QPushButton::clicked, [this]() {  });
    connect(ui->open_ServiceBtn,       &QPushButton::clicked, [this]() { this->ui->page_view->setCurrentWidget(PagesManager::getPage("Service")); });
    connect(ui->open_ConneectionsBtn,  &QPushButton::clicked, [this]() { this->ui->page_view->setCurrentWidget(PagesManager::getPage("Connections")); });
    connect(ui->open_SettingsBtn,      &QPushButton::clicked, [this]() {  });

    ui->page_view->setCurrentWidget(_defaultPage ? _defaultPage : l_pages[0]);

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
GUI::onOpenPageBtnClicked()
{
    QPushButton * btn = dynamic_cast<QPushButton*>(sender());
    ui->page_view->setCurrentWidget(PagesManager::getPage(btn->text()));
}

void
GUI::changeIndicatorState(QHostAddress address, quint16 port, bool listening)
{
    if (listening) {
        _listenIndicator->setText(tr("Listening"));
    } else {
        _listenIndicator->setText(tr("Offline"));
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
