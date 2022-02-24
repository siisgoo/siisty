#include "GUI.hpp"

#include "./ui_GUI.h"
#include <qnamespace.h>

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI),
        _serveAddress("127.0.0.1"),
        _servePort(9000)
{
    ui->setupUi(this);

    setupLogger();
    setupServer();
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
    delete ui;
}

void
GUI::setForseUseSsl(bool use)
{
    _server->setForseUseSsl(use);
}

void
GUI::setSslCertificatesPath(QString& certPath, QString& caPath, QString& keyPath)
{
    _server->LoadCertificates(certPath, keyPath);
}

void
GUI::setServeAddress(QHostAddress& add, quint16 port)
{
    _serveAddress = add;
    _servePort = port;

    if (_server->isListening()
            && (_serveAddress != add || _servePort != port ))
    {
        Q_EMIT logMessage("Rebooting server after change Serve address and port", Debug);
        _server->ToggleStartStopListening(_serveAddress, _servePort);
        _server->ToggleStartStopListening(_serveAddress, _servePort);
    }
}

void
GUI::setLoggingLeve(int level)
{
    if (_log->loggingLevel() != level) {
        Q_EMIT logMessage("Changing logging level", Debug);
        _log->setLoggingLevel(level);
    }
}

void
GUI::setLogPath(QString& path)
{
    _log->setLogPath(path);
}

void
GUI::setDefaultPage(QString& pageName)
{
    QWidget * p = PagesManager::getPage(pageName);
    if (p) {
        _defaultPage = p;
        //TODO write to config
    } else {
        Q_EMIT logMessage(tr("Cannot set default page with name %1, thats page not exist").arg(pageName), Error);
    }
}

void
GUI::setMaxThreads(int)
{
    // TODO add thread pool
}

void
GUI::setMaxPendingConnections(int max)
{
    _server->setMaxPendingConnections(max);
}

void
GUI::adjustUi()
{
    connect(ui->pages_list, SIGNAL(clicked(const QModelIndex&)), this, SLOT(onItemClicked(const QModelIndex&)));
        // Click on docked pages Menu/List

    QWidget * l_ServerInfoPage  = new ServerInfoPage(ui->page_view),
            * l_ConnectionsPage = new ConnectionsPage(ui->page_view);

    PagesManager::addPage(l_ServerInfoPage);
    PagesManager::addPage(l_ConnectionsPage);

    ui->page_view->addWidget(l_ServerInfoPage);
    ui->page_view->addWidget(l_ConnectionsPage);

    ui->page_view->setCurrentWidget(_defaultPage ? _defaultPage : l_ServerInfoPage);
        // TODO add variant from confing

    connect(_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            l_ServerInfoPage, SLOT(onServerListningStateChanged(QHostAddress, quint16, bool)));

    connect(_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(changeIndicatorState(QHostAddress, quint16, bool)));
    connect(_server, SIGNAL(listeningStateChanged(QHostAddress, quint16, bool)),
            this, SLOT(on_listeningStateChanged(QHostAddress, quint16, bool)));

    _listenIndicator = new QLabel("Offline");
    ui->statusbar->addPermanentWidget(_listenIndicator);
    ui->statusbar->showMessage("Initializing", 1000);

    ui->actionStop_server->setEnabled(false);
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
GUI::setupServer()
{
    _server = new iiServer(nullptr);

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
        ui->actionStop_server->setEnabled(true);
        ui->actionStart_server->setEnabled(false);
    } else {
        ui->actionStop_server->setEnabled(false);
        ui->actionStart_server->setEnabled(true);
    }
}

/* Default actions */

void
GUI::on_actionQuit_triggered()
{
    QApplication::quit();
}

void
GUI::on_actionStart_server_triggered()
{
    _server->ToggleStartStopListening(_serveAddress, _servePort);
}

void GUI::on_actionStop_server_triggered()
{
    _server->ToggleStartStopListening(_serveAddress, _servePort);
}

void
GUI::logMessage(QString str, int level)
{
    ui->loggingOutput->append(str);
    Q_EMIT send_to_log(str, level);
}
