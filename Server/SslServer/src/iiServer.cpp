#include <cassert>
#include <QDateTime>
#include <QFileInfo>

#include "General/logger.hpp"
#include "General/iiNPack.hpp"
#include "SslServer/iiServer.hpp"

iiServer::iiServer(QObject * parent)
    : QObject(parent)
{
    if (!QSslSocket::supportsSsl() && _forseUseSsl) {
        Q_EMIT logMessage("Missing SSL. Please install it.", Fatal);
        throw "Missing SSL.";
    }

    connect(&_server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

iiServer::~iiServer()
{
    if (_server.isListening()) {
        _server.close();
    }

    _clients.clear();
}

void iiServer::ToggleStartStopListening(const QHostAddress &address,
                                        quint16 port)
{
    if (_server.isListening()) {
        _server.close();
        Q_EMIT listeningStateChanged(address, port, false);
        return;
    }

    if (_server.listen(address, port)) {
        Q_EMIT listeningStateChanged(address, port, true);
        Q_EMIT logMessage("Start serving on: " + address.toString() + ":" + QString::number(port), Debug);
    } else {
        Q_EMIT logMessage("Could not bind", Fatal);
    }
}

void iiServer::LoadCertificates(const QString& certPath, const QString& keyPath)
{
    _key = keyPath;
    _certificate = certPath;

    QFileInfo keyInfo(keyPath);
    QFileInfo certificateInfo(certPath);

    if (keyInfo.exists() == false) {
        Q_EMIT logMessage("Key file does not exist " + keyPath, Error);
        return;
    }
    if (keyInfo.isReadable() == false) {
        Q_EMIT logMessage("Key file is not readable " + keyPath, Error);
        return;
    }
    if (certificateInfo.exists() == false) {
        Q_EMIT logMessage("certificate file does not exist " + certPath, Error);
        return;
    }
    if (certificateInfo.isReadable() == false) {
        Q_EMIT logMessage("certificate file is not readable " + certPath, Error);
        return;
    }
}

// Accept connection from server and initiate the SSL handshake
void iiServer::acceptConnection()
{
    if (_clients.empty() == false) {
        Q_EMIT logMessage("iiServer is mad efor 1 connection also. Need to update "
                "to handle multiple connections", Fatal);
        return;
    }

    QSslSocket *socket =
        reinterpret_cast<QSslSocket *>(_server.nextPendingConnection());
    assert(socket);

    // QSslSocket emits the encrypted() signal after the encrypted connection is
    // established
    if (QSslSocket::supportsSsl() && _forseUseSsl)
    {
        connect(socket, SIGNAL(encrypted()), this, SLOT(handshakeComplete()));
        socket->setPrivateKey(_key);
        socket->setLocalCertificate(_certificate);

        socket->setPeerVerifyMode(QSslSocket::VerifyNone);
        socket->startServerEncryption();
    }
    else
    {
        ptrClient client(new iiClient(socket));

        connect(client.data(), SIGNAL(logMessage(QString)),        this, SIGNAL(logMessage(QString)));
        connect(client.data(), SIGNAL(recivedMessage(iiNPack::Header, QByteArray)), this, SLOT(recivedMessage(iiNPack::Header, QByteArray)));
        connect(client.data(), SIGNAL(disconnected()),             this, SLOT(clientDisconnected()));
//        connect(client.data(), SIGNAL(reciveMessage()),            this, SLOT(receivedMessage()));
        _clients.append(client);

        Q_EMIT logMessage("Accepted connection from "
                  + socket->peerAddress().toString() + ":"
                  + QString::number(socket->peerPort())
                  + " .Encrypted : " + (socket->isEncrypted() ? "yes" : "no"), Debug);
    }
}

// Receive notification that the SSL handshake has completed successfully
void
iiServer::handshakeComplete()
{
    QSslSocket *socket = dynamic_cast<QSslSocket *>(sender());
    assert(socket);
    ptrClient client(new iiClient(socket));

    connect(client.data(), SIGNAL(logMessage(QString)),         this, SIGNAL(logMessage(QString)));
    connect(client.data(), SIGNAL(recivedMessage(iiNPack::Header, QByteArray)), this, SLOT(recivedMessage(iiNPack::Header, QByteArray)));
    connect(client.data(), SIGNAL(disconnected()),              this, SLOT(clientDisconnected()));
    connect(client.data(), SIGNAL(receiveMessage()),            this, SLOT(receivedMessage()));

    Q_EMIT logMessage("Accepted connection from "
              + socket->peerAddress().toString() + ":"
              + QString::number(socket->peerPort())
              + " .Encrypted : " + (socket->isEncrypted() ? "yes" : "no"), Debug);

    _clients.append(client);
}

void
iiServer::recivedMessage(iiNPack::Header header, QByteArray msg)
{
    iiClient * client = dynamic_cast<iiClient *>(sender());
    assert(client);

    Q_EMIT logMessage("Recived message" + msg, Debug);

    QByteArray pack = iiNPack::pack("Heelooo", iiNPack::PacketType::RESPONSE);
    client->sendMessage(pack);
}

void
iiServer::clientDisconnected()
{
    iiClient * client = dynamic_cast<iiClient *>(sender());
    assert(client);

    Q_EMIT logMessage("Client disconnect: " + client->socket()->peerAddress().toString(), Debug);
    _clients.removeOne(client);
    delete client;
}
