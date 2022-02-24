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

int  iiServer::maxPendingConnections() const     { return _server.maxPendingConnections(); }
void iiServer::setMaxPendingConnections(int max) { _server.setMaxPendingConnections(max); }
bool iiServer::isListening() const               { return _server.isListening(); }

void
iiServer::setForseUseSsl(bool use)
{
    if (_forseUseSsl != use) {
        Q_EMIT logMessage(tr((use ? "Enabling %1" : "Disabling %1")).arg("forse use SSL"), Debug);
        _forseUseSsl = use;
        if (_server.isListening()) {
            Q_EMIT logMessage("Rebooting server", Debug);
            ToggleStartStopListening(_address, _port);
        }
    }
}

void iiServer::ToggleStartStopListening(const QHostAddress &address,
                                        quint16 port)
{
    _address = address;
    _port = port;

    if (_server.isListening()) {
        _server.close();
        Q_EMIT listeningStateChanged(address, port, false);
        return;
    }

    if (_server.listen(address, port)) {
        Q_EMIT logMessage("Start serving on: " + address.toString() + ":" + QString::number(port), Debug);
        Q_EMIT listeningStateChanged(address, port, true);
    } else {
        Q_EMIT logMessage("Could not bind " + _server.errorString(), Fatal);
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
    QSslSocket *socket =
        reinterpret_cast<QSslSocket *>(_server.nextPendingConnection());
    assert(socket);

    iiClient * client(new iiClient(socket));

    if (QSslSocket::supportsSsl() && _forseUseSsl)
    {
        connect(client, SIGNAL(encrypted()), this, SLOT(handshakeComplete()));
        client->setPrivateKey(_key);
        client->setLocalCertificate(_certificate);

        client->setPeerVerifyMode(QSslSocket::VerifyNone);
        client->startServerEncryption();
    }
    else
    {
        connect(client, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
        connect(client, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)),
                this, SLOT(recivedMessage(iiNPack::Header, QByteArray)));

        connect(client, SIGNAL(logMessage(QString, int)), this, SIGNAL(logMessage(QString, int)));

        _clients.append(client);

        Q_EMIT logMessage("Accepted connection from "
                  + client->peerAddress().toString() + ":"
                  + QString::number(client->peerPort())
                  + " .Encrypted : " + (client->isEncrypted() ? "yes" : "no"), Debug);
    }
}

// Receive notification that the SSL handshake has completed successfully
void
iiServer::handshakeComplete()
{
    iiClient * client = reinterpret_cast<iiClient *>(sender());
    assert(client);

    connect(client, SIGNAL(logMessage(QString, int)), this, SIGNAL(logMessage(QString, int)));
    connect(client, SIGNAL(disconnected()),      this, SLOT(clientDisconnected()));
    connect(client, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)),
            this, SLOT(recivedMessage(iiNPack::Header, QByteArray)));

    Q_EMIT logMessage("Accepted connection from "
              + client->peerAddress().toString() + ":"
              + QString::number(client->peerPort())
              + " .Encrypted : " + (client->isEncrypted() ? "yes" : "no"), Debug);

    _clients.append(client);
}

void
iiServer::recivedMessage(iiNPack::Header header, QByteArray msg)
{
    iiClient * client = dynamic_cast<iiClient *>(sender());
    assert(client);

    Q_EMIT logMessage("Recived message " + msg, Debug);

    if (header.Size <= iiNPack::HeaderSize) {
        Q_EMIT logMessage("Skipping header only package...", Debug);
        return;
    }

    //check send stamp?
    //add experation time?

    using PacketType = iiNPack::PacketType;
    using PacketLoadType = iiNPack::PacketLoadType;

    switch (header.PacketType) {
        case (quint8)PacketType::AUTORIZATION_REQUEST:
            /* if (client->) */
            break;
        case (quint8)PacketType::ERROR_MESSAGE:
            break;
        case (quint8)PacketType::GET_REQUEST:
            break;
        case (quint8)PacketType::PUT_REQUEST:
            break;
        case (quint8)PacketType::RESPONSE:
            break;
    }

    /* QByteArray pack = iiNPack::pack("Heelooo", iiNPack::PacketType::RESPONSE); */
    /* client->sendMessage(pack); */
}

void
iiServer::clientDisconnected()
{
    iiClient *client = dynamic_cast<iiClient *>(sender());
    assert(client);

    Q_EMIT logMessage("Client disconnect: " + client->peerAddress().toString(), Debug);
    _clients.removeOne(client); //mem lack?
}
