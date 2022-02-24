#include "Service.hpp"

Service::Service(QObject *p)
    : SslClientBase(new QSslSocket(), p)
{
}

Service::~Service()
{
}
