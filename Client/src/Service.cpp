#include "Service.hpp"

Service::Service(QObject *p)
    : SslClientBase(new QSslSocket(), p)
{
}

Service::~Service()
{
}

void
Service::login()
{

}

void
Service::sendCommand(QJsonObject&)
{

}
