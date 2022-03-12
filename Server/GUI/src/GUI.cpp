#include "GUI.hpp"

#include <QException>

#include "./ui_GUI.h"
#include <qnamespace.h>

GUI::GUI(Settings settings, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI),
        _settings(settings)
{
    ui->setupUi(this);

    setupLogger();
    setupServer();
    setupDatabase();
    adjustUi();
}

GUI::~GUI()
{
    _loggingThread.quit();
    _serverThread.quit();

    _loggingThread.wait();
    _serverThread.wait();

    delete _server;
    delete _log;
    delete _listenIndicator;
    if (_database) {
        delete _database;
    }
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
        Q_EMIT logMessage("Changing logging level", Debug);
        _log->setLoggingLevel(level);
    }
}

void
GUI::adjustUi()
{
    connect(ui->pages_list, SIGNAL(clicked(const QModelIndex&)), this, SLOT(onItemClicked(const QModelIndex&)));
        // Click on docked pages Menu/List

    QVector<QWidget*> l_pages({
            new WelcomePage(ui->page_view),
            new ServerInfoPage(ui->page_view),
            new ConnectionsPage(ui->page_view),
            new SystemLoadPage(ui->page_view),
            new DatabasePage(ui->page_view),
    });

    for (auto l_page : l_pages) {
        PagesManager::addPage(l_page);
        ui->page_view->addWidget(l_page);
    }

    ui->page_view->setCurrentWidget(_defaultPage ? _defaultPage : l_pages[0]);

    connect(_server,
            SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            std::find_if(l_pages.begin(), l_pages.end(),
                [](QObject* o) {return o->objectName() == "Server info";} )[0],
            SLOT(onServerListningStateChanged(QHostAddress, quint16, bool)));

    connect(_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(changeIndicatorState(QHostAddress, quint16, bool)));
    connect(_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(on_listeningStateChanged(QHostAddress, quint16, bool)));

    _listenIndicator = new QLabel("Offline");
    ui->statusbar->addPermanentWidget(_listenIndicator);
    ui->statusbar->showMessage("Initializing", 1000);

    ui->actionToggle_server->setText("Start");
}

void
GUI::setupLogger()
{
    _log = new logger(Trace, "sIIsTy-Server", nullptr);
    connect(this, SIGNAL(send_to_log(QString, int)), _log, SLOT(logMessage(QString, int)));
    _log->moveToThread(&_loggingThread);
    _loggingThread.start();
}

void
GUI::setupDatabase()
{
    try {
        _database = new Database::SQLite(_settings.databasePath, nullptr);
        connect(_database, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)));
        connect(_database, SIGNAL(failed(Database::CmdError)), this, SLOT(on_databaseError(Database::CmdError)));
    } catch (QSqlError e) {
        QString error = "Error in statment: " + e.databaseText() +
            "\nError type: " + QString::number(e.type()) +
            "\nReason: " + e.text() +
            "\nDriver: " + e.driverText();
        logMessage(error, LoggingLevel::Fatal);
        _database = nullptr;
    }
}

void
GUI::setupServer()
{
    _server = new iiServer(nullptr);
    _server->setForseUseSsl(_settings.useSsl);
    _server->LoadCertificates(_settings.certPath, _settings.keyPath);

    connect(_server, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)));

    _server->moveToThread(&_serverThread);
    _serverThread.start();
}

void
GUI::onItemClicked(const QModelIndex& model)
{
    ui->page_view->setCurrentWidget(PagesManager::getPage(model.data().toString()));
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
GUI::logMessage(QString str, int level)
{
    ui->loggingOutput->append(str);
    Q_EMIT send_to_log(str, level);
}
