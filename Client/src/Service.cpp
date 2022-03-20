#include "Service.hpp"

Service::Service(QObject *p)
    : SslClientBase(new QSslSocket(), p)
{
}

Service::~Service()
{
}

void
Service::login(const QString& login, const QString& password)
{
    Q_EMIT loginSuccess("asdf", 1, 1);
}

void
Service::sendCommand(QJsonObject&)
{

}
