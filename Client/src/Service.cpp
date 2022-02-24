#include "Service.hpp"

Service::Service(QObject* _parent)
    : QObject(_parent),
        _serverAddress(QHostAddress("127.0.0.1")),
        _serverPort(9000),
        _control(new SslClientBase(new QSslSocket(nullptr)))
{
}

Service::~Service()
{
    disconnectFromServer();
}

SslClientBase *
Service::control()
{
    return _control;
}

void
Service::setServerAddress(const QHostAddress& add, quint16 port)
{
    _serverAddress = add;
    _serverPort = port;
}

QAbstractSocket::SocketState
Service::SocketState()
{
    return _control->socket()->state();
}

void
Service::connectToServer()
{
    Q_EMIT logMessage("Connecting to server");

    connect(_control, SIGNAL(logMessage(QString)), this, SIGNAL(logMessage(QString)));

    connect(this,     SIGNAL(sendMessage(QByteArray)),    _control, SLOT(sendMessage(QByteArray)));
    connect(_control, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)), this,     SIGNAL(recivedMessage(iiNPack::Header, QByteArray)));

    connect(_control->socket(), SIGNAL(sslErrors(const QList<QSslError>&)),        this, SLOT(sslErrors(const QList<QSslError>&)));
    connect(_control->socket(), SIGNAL(errorOcurred(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));

    connect(_control->socket(), SIGNAL(disconnected()), this, SIGNAL(disconnected()));

    if (_forseUseSsl) {
        connect(_control->socket(), SIGNAL(encrypted()), this, SIGNAL(connected()));
        _control->socket()->connectToHostEncrypted(_serverAddress.toString(), _serverPort);
    } else {
        connect(_control->socket(), SIGNAL(connected()), this, SIGNAL(connected()));
        _control->socket()->connectToHost(_serverAddress.toString(), _serverPort);
    }
}

void
Service::disconnectFromServer()
{
    if (_control) {
        _control->close();
        Q_EMIT logMessage("Disconnecting from server");
        Q_EMIT disconnected();
    }
}

void
Service::sslErrors(const QList<QSslError>&)
{
    Q_EMIT logMessage("Cannot connect to server...");
    disconnect();
}

void
Service::socketError(QAbstractSocket::SocketError)
{
    Q_EMIT logMessage("Cannot conntect to server...");
    disconnect();
}
