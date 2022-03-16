#include "Controller.hpp"
#include "./ui_Controller.h"

userInterface::userInterface(QWidget* _parent)
    : QMainWindow(_parent),
    ui(new Ui::Controller),
        _serverAddress(QHostAddress("127.0.0.1")),
        _serverPort(9000)
{
    ui->setupUi(this);

    applyConfig();
    setupLogger();
    setupService();
    adjustUi();
}

userInterface::~userInterface()
{
    _serviceThread.quit();
    _loggingThread.quit();

    _serviceThread.wait();
    _loggingThread.wait();

    delete _service;
    delete _log;
}

void
userInterface::applyConfig()
{

}

void
userInterface::adjustUi()
{
    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(onSendMessageClicked()));

    connect(ui->actionLogin,  SIGNAL(triggered()), this, SLOT(on_actionLoginTriggered()));
    connect(ui->actionLogout, SIGNAL(triggered()), this, SLOT(on_actionLogoutTriggered()));
}

void
userInterface::setupLogger()
{
    _log = new logger(Trace, "siisty-Client", nullptr);

    connect(this, SIGNAL(send_to_log(QString, int)), _log, SLOT(logMessage(QString, int)));

    _log->moveToThread(&_loggingThread);
    _loggingThread.start();
}

void
userInterface::setupService()
{
    _service = new Service();

    connect(_service, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)));

    connect(_service, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)), this, SLOT(recivedMessage(iiNPack::Header, QByteArray)));

    if (_forseUseSsl) {
        connect(_service, SIGNAL(encrypted()), this, SLOT(on_connetedToServer()));
    } else {
        connect(_service, SIGNAL(connected()), this, SLOT(on_connetedToServer()));
    }

    connect(_service, SIGNAL(disconnected()), this, SLOT(on_disconnetedFromServer()));

    /* _manager.moveToThread(&_serviceThread); */
    /* _serviceThread.start(); */
}

void
userInterface::recivedMessage(iiNPack::Header header, QByteArray data)
{
    Q_EMIT logMessage("Paint recived message", Trace);
    ui->recived_message->insertPlainText(data);
}

void
userInterface::onSendMessageClicked()
{
    QByteArray load = ui->sending_message->toPlainText().toUtf8();
    Q_EMIT logMessage("Sending message" + load, Trace);
    QByteArray packet = iiNPack::pack(load, iiNPack::PacketType::GET_REQUEST);
    _service->sendMessage(packet);
}

void
userInterface::on_connetedToServer()
{
    Q_EMIT logMessage("Connected to server", Debug);

    QByteArray packet = iiNPack::pack("Hello", iiNPack::PacketType::AUTORIZATION_REQUEST);
    _service->sendMessage(packet);
        // do login

    //....

    Q_EMIT on_logined();
}

void
userInterface::on_disconnetedFromServer()
{
    Q_EMIT on_logouted();
}

void
userInterface::on_logined()
{
    ui->actionLogin->setEnabled(false);
    ui->actionLogout->setEnabled(true);
}

void
userInterface::on_login_failed()
{
    ui->actionLogin->setEnabled(true);
    ui->actionLogout->setEnabled(false);
}

void
userInterface::on_logouted()
{
    ui->actionLogin->setEnabled(true);
    ui->actionLogout->setEnabled(false);
}

void
userInterface::on_actionLoginTriggered()
{
    if (QSslSocket::supportsSsl() && _forseUseSsl) {
        _service->connectToHostEncrypted(_serverAddress.toString(), _serverPort);
    } else {
        _service->connectToHost(_serverAddress, _serverPort);
    }
}

void
userInterface::on_actionLogoutTriggered()
{
    _service->disconnectFromHost();
    // update ui
}

void
userInterface::logMessage(QString _message, int level)
{
    qDebug() << _message;

    Q_EMIT send_to_log(_message, level);
}
