#include "SslServer/iiClient.hpp"

iiClient::iiClient(QSslSocket * socket, QObject * parent)
    : SslClientBase(socket, parent),
        _autorized(false)
{
}

iiClient::~iiClient()
{
}
