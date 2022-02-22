#include "GUI.hpp"
#include "./ui_GUI.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

userInterface::userInterface(QWidget* _parent)
    : QMainWindow(_parent)
    , ui(new Ui::GUI),
        log(QString("Client"), NULL),
        _serverPort(9000),
        _serverAddress("127.0.0.1")
{
    ui->setupUi(this);

    connect(this, SIGNAL(send_to_log(QString)), &log, SLOT(logMessage(QString)));
    log.moveToThread(&loggingThread);
    loggingThread.start();

    connect(&_manager, SIGNAL(logMessage(QString)), this, SLOT(logMessage(QString)));
    connect(&_manager, SIGNAL(receivedMessage(QByteArray)), this, SLOT(receivedMessage(QByteArray)));

    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(onSendMessageClicked()));

    _manager.moveToThread(&serviceThread);
    serviceThread.start();
}

userInterface::~userInterface()
{
    serviceThread.quit();
    loggingThread.quit();

    serviceThread.wait();
    loggingThread.wait();
}

void
userInterface::receivedMessage(QByteArray data)
{
    ui->recived_message->insertPlainText(data);
}

void
userInterface::onSendMessageClicked()
{
    QByteArray load = ui->sending_message->toPlainText().toUtf8();
    QByteArray packet = iiNPack::pack(load, iiNPack::PacketType::RESPONSE);
    Q_EMIT _manager.sendMessage(packet);
}

void userInterface::startService()
{
    ui->actionLogin->setEnabled(false);
    ui->actionLogout->setEnabled(true);
    _manager.start_control();
}
void userInterface::stopService()
{
    ui->actionLogin->setEnabled(true);
    ui->actionLogout->setEnabled(false);
    _manager.stop_control();
}

void userInterface::logMessage(QString _message)
{
    /* if (textDisplay.isNull() == false) */
    /* { */
        /* textDisplay->append(_message); */
    /* } */
    Q_EMIT send_to_log(_message);
}

void
userInterface::connectToServer()
{
}

void
userInterface::on_actionLoginTriggered()
{
}

void
userInterface::on_actionLogoutTriggered()
{
    Q_EMIT startService();
}
