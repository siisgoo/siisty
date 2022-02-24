#include "SslServer/iiClient.hpp"

iiClient::iiClient(QSslSocket* socket)
    : SslClientBase(socket),
        _autorized(false)
{
}

iiClient::~iiClient()
{
}
