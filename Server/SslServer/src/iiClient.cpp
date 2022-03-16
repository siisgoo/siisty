#include "SslServer/iiClient.hpp"

iiClient::iiClient(QSslSocket * socket, QObject * parent)
    : SslClientBase(socket, parent),
        _identified(false)
{
}

iiClient::~iiClient()
{
}
