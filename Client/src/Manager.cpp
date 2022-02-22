#include "Manager.hpp"

Manager::Manager(QObject* _parent)
    : QObject(_parent),
        address(QHostAddress("127.0.0.1")),
        port(9000)
{
    connect(&control, SIGNAL(logMessage(QString)), this, SIGNAL(logMessage(QString)));

    connect(this,     SIGNAL(sendMessage(QByteArray)), &control, SIGNAL(sendIIPack(QByteArray)));
    connect(&control, SIGNAL(receivedMessage(QByteArray)), this, SIGNAL(receivedMessage(QByteArray)));
}

Manager::~Manager()
{
}

void Manager::start_control()
{
    control.create(address, port);
}
void Manager::stop_control()
{
    control.destroy();
}
