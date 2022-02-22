#include "SslServer/SslServerManager.hpp"

SslServerManager::SslServerManager(QObject* _parent)
    : QObject(_parent),
      address(QHostAddress::Any),
      port(9000),
      theSslServer(this)
{
    connect(&theSslServer, SIGNAL(newConnection()), this,
            SLOT(newConnection()));
    connect(&theSslServer, SIGNAL(logMessage(QString)), this,
            SIGNAL(logMessage(QString)));
}
SslServerManager::~SslServerManager() {}

const QHostAddress& SslServerManager::getHost() const { return address; }
qint16 SslServerManager::getPort() const { return port; }

void SslServerManager::setServerConfig(QHostAddress _address, qint16 _port)
{
    if (theSslServer.isListening() == false) {
        Q_EMIT logMessage(tr("DEBUG: Server is NOT active. Updating address "
                             "from [%1]:%2 to [%3]:%4")
                              .arg(address.toString())
                              .arg(port)
                              .arg(_address.toString())
                              .arg(_port));
        address = _address;
        port = _port;
    } else {
        Q_EMIT logMessage(tr("DEBUG: Server is active. Unable to update "
                             "address from [%1]:%2 to [%3]:%4")
                              .arg(address.toString())
                              .arg(port)
                              .arg(_address.toString())
                              .arg(_port));
    }
}
void SslServerManager::setMaxPending(int _connections) {
    theSslServer.setMaxPendingConnections(_connections);
}
void SslServerManager::setSslKey(QSslKey& _key) {
    theSslServer.setSslKey(_key);
}
void SslServerManager::setSslCertificate(QSslCertificate& _certificate) {
    theSslServer.setSslCertificate(_certificate);
}

void SslServerManager::start_service() {
    if (theSslServer.isListening() == false) {
        Q_EMIT logMessage(tr("Starting Service"));
        theSslServer.listen(address, port);
        Q_EMIT listenStateChanged(true);
    } else {
        Q_EMIT logMessage(tr("Server already listening"));
    }
}
void SslServerManager::stop_service() {
    if (theSslServer.isListening() == true) {
        Q_EMIT logMessage(tr("Stopping Service"));
        theSslServer.close();
        Q_EMIT listenStateChanged(false);
    } else {
        Q_EMIT logMessage(tr("Server already stopped"));
    }
}

void SslServerManager::acceptError(QAbstractSocket::SocketError socketError) {
    switch (socketError) {
        default:
            Q_EMIT logMessage(tr("Unknown connection acceptance error - %1")
                                  .arg(socketError));
            break;
    };
}
void SslServerManager::newConnection() {
    QTcpSocket* newTcpConnection = theSslServer.nextPendingConnection();
    if (newTcpConnection != NULL) {
        ptrTcpSocket newClient =
            theSslServer.getManagerForConnection(newTcpConnection);
    }
}
