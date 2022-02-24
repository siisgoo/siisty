#include "GUI.hpp"
#include "./ui_GUI.h"

userInterface::userInterface(QWidget* _parent)
    : QMainWindow(_parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);

    connect(this, SIGNAL(send_to_log(QString)), _log, SLOT(logMessage(QString)));
    _log.moveToThread(&_loggingThread);
    _loggingThread.start();

    connect(&_manager, SIGNAL(logMessage(QString)),        this, SLOT(logMessage(QString)));
    connect(&_manager, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)), this, SLOT(recivedMessage(iiNPack::Header, QByteArray)));

    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(onSendMessageClicked()));

    connect(ui->actionLogin,  SIGNAL(triggered()), this, SLOT(on_actionLoginTriggered()));
    connect(ui->actionLogout, SIGNAL(triggered()), this, SLOT(on_actionLogoutTriggered()));

    /* connect(&_manager, SIGNAL(disconnected()), this, SLOT(())); */

    connect(&_manager, SIGNAL(connected()),    this, SLOT(on_connetedToServer()));
    connect(&_manager, SIGNAL(disconnected()), this, SLOT(on_disconnetedFromServer()));

    /* _manager.moveToThread(&_serviceThread); */
    /* _serviceThread.start(); */
}

userInterface::~userInterface()
{
    _serviceThread.quit();
    _loggingThread.quit();

    _serviceThread.wait();
    _loggingThread.wait();
}

void
userInterface::recivedMessage(iiNPack::Header header, QByteArray data)
{
    Q_EMIT logMessage("Paint recived message");
    ui->recived_message->insertPlainText(data);
}

void
userInterface::onSendMessageClicked()
{
    QByteArray load = ui->sending_message->toPlainText().toUtf8();
    Q_EMIT logMessage("Sending message" + load);
    QByteArray packet = iiNPack::pack(load, iiNPack::PacketType::GET_REQUEST);
    Q_EMIT _manager.sendMessage(packet);
}

void
userInterface::startService()
{
    _manager.connectToServer();
}

void
userInterface::stopService()
{
    _manager.disconnectFromServer();
}

void
userInterface::on_connetedToServer()
{
    QByteArray packet = iiNPack::pack("Hello", iiNPack::PacketType::AUTORIZATION_REQUEST);
    _manager.sendMessage(packet);
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
    startService();
}

void
userInterface::on_actionLogoutTriggered()
{
    stopService();
}

void
userInterface::logMessage(QString _message)
{
    qDebug() << _message;

    Q_EMIT send_to_log(_message);
}
