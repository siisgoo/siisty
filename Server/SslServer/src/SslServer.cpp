#include <QSslSocket>
#include "SslServer/SslServer.hpp"

void SslServer::incomingConnection(int socketDescriptor)
{
    QSslSocket *serverSocket = new QSslSocket();
    if (serverSocket->setSocketDescriptor(socketDescriptor)) {
        addPendingConnection(serverSocket);
    } else {
        delete serverSocket;
    }
}
