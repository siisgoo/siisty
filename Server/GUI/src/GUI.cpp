#include "GUI.hpp"

#include "./ui_GUI.h"
#include <qnamespace.h>

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI),
        _serveAddress("127.0.0.1"),
        _serverPort(9000)
{
    ui->setupUi(this);

    applyConfig("");
    adjustUi();
    setupServer();
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

    ui->page_view->setCurrentWidget(l_ServerInfoPage);
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
    /* connect(_server, SIGNAL(clientConnected(const Server::Client*)),    this,                SLOT(onClientConnected(const Server::Client*))); */
    /* connect(_server, SIGNAL(clientDisconnected(const Server::Client*)), this,                SLOT(onClientDisconnected(const Server::Client*))); */
    /* connect(_server, SIGNAL(requestRecived(const Server::Client*,       const QByteArray&)), this, SLOT(on_requestRecived(const Server::Client*, const QByteArray&))); */

    /* connect(_server, SIGNAL(clientSocketError(const Server::Client*, const QAbstractSocket::SocketError&)), this, SLOT(on_clientSocketError(const Server::Client*, const QAbstractSocket::SocketError&))); */
    /* connect(_server, SIGNAL(clientSslError(const Server::Client*, const QSslError&)),                this, SLOT(on_clientSslError(const Server::Client*, const QSslError&))); */
    /* connect(_server, SIGNAL(clientSslError(const Server::Client*, const QList<QSslError>&)),         this, SLOT(on_clientSslError(const Server::Client*, const QList<QSslError>&))); */
        // Errors
    _server->moveToThread(&_serverThread);
    _serverThread.start();
}

void
GUI::applyConfig(const QString& path)
{
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
    _server->ToggleStartStopListening(_serveAddress, _serverPort);
}

void GUI::on_actionStop_server_triggered()
{
    _server->ToggleStartStopListening(_serveAddress, _serverPort);
}

void
GUI::logMessage(QString str, int level)
{
    ui->loggingOutput->append(str);
    Q_EMIT send_to_log(str, level);
}
