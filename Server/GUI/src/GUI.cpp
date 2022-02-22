#include "GUI.hpp"

#include "./ui_GUI.h"
#include <qnamespace.h>

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI),
        _manager(new SslServerManager()),
        _log("siisty", nullptr)
{
    ui->setupUi(this);

    connect(this, SIGNAL(send_to_log(QString)), &_log, SLOT(logMessage(QString)));
    _log.moveToThread(&_loggingThread);
    _loggingThread.start();

    apply_config("");
    connect_db("");
    adjustUi();
    setupServer();
}

GUI::~GUI()
{
    _loggingThread.quit();
    _loggingThread.wait();

    delete _manager;
    delete _led;
    delete ui;
}

void
GUI::setup()
{
}
    //remove it

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

    connect(_manager, SIGNAL(listenStateChanged(bool)), l_ServerInfoPage, SLOT(onServerListningStateChanged(bool)));

    connect(_manager, SIGNAL(listenStateChanged(bool)), this, SLOT(changeLedState(bool)));

    _led = new QLedIndicator("", QLedIndicator::LabelPosition::Hide);
    _led->setLedSize(10);
    _led->setText("");
    _led->setLedState(QLedIndicator::LedState::Inactive);
    ui->statusbar->setMinimumSize(QSize(0, 20));
    ui->statusbar->addPermanentWidget(_led);
    ui->statusbar->showMessage("Initializing", 1000);
    _led->setStyleSheet(""); //erase

    ui->actionStop_server->setEnabled(false);
}

void
GUI::setupServer()
{
    connect(_manager, SIGNAL(logMessage(QString)), this, SLOT(logMessage(QString)));
    /* connect(_server, SIGNAL(clientConnected(const Server::Client*)),    this,                SLOT(onClientConnected(const Server::Client*))); */
    /* connect(_server, SIGNAL(clientDisconnected(const Server::Client*)), this,                SLOT(onClientDisconnected(const Server::Client*))); */
    /* connect(_server, SIGNAL(requestRecived(const Server::Client*,       const QByteArray&)), this, SLOT(on_requestRecived(const Server::Client*, const QByteArray&))); */

    /* connect(_server, SIGNAL(clientSocketError(const Server::Client*, const QAbstractSocket::SocketError&)), this, SLOT(on_clientSocketError(const Server::Client*, const QAbstractSocket::SocketError&))); */
    /* connect(_server, SIGNAL(clientSslError(const Server::Client*, const QSslError&)),                this, SLOT(on_clientSslError(const Server::Client*, const QSslError&))); */
    /* connect(_server, SIGNAL(clientSslError(const Server::Client*, const QList<QSslError>&)),         this, SLOT(on_clientSslError(const Server::Client*, const QList<QSslError>&))); */
        // Errors
}

void
GUI::connect_db(const QString& path)
{
    if (QFileInfo::exists(path)) {

    } else {

    }
}

void
GUI::apply_config(const QString& path)
{
    /* _server->setHost(QHostAddress("127.0.0.1")); */
    /* _server->setPort(8080); */
    /* _server->setSslLocalCertificate("red_local.pem"); */
    /* _server->setSslPrivateKey("red_local.key"); */
    /* _server->setSslProtocol(QSsl::TlsV1_2); */
        // TLS setup
}

void
GUI::onItemClicked(const QModelIndex& model)
{
    ui->page_view->setCurrentWidget(PagesManager::getPage(model.data().toString()));
}

void
GUI::changeLedState(bool listening)
{
    if (listening) {
        _led->setLedState(QLedIndicator::LedState::Active);
    } else {
        _led->setLedState(QLedIndicator::LedState::Inactive);
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
    ui->actionStop_server->setEnabled(true);
    ui->actionStart_server->setEnabled(false);
    _manager->start_service();
}

void GUI::on_actionStop_server_triggered()
{
    ui->actionStop_server->setEnabled(false);
    ui->actionStart_server->setEnabled(true);
    _manager->stop_service();
}

void
GUI::logMessage(QString str)
{
    /* if () */

    Q_EMIT send_to_log(str);
}
