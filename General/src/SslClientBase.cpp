#include "General/SslClientBase.hpp"
#include "General/iiNPack.hpp"
#include "General/logger.hpp"

SslClientBase::SslClientBase(QSslSocket * socket)
    : _socket(socket)
{
    connect(_socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(dataAvailable()));
    connect(_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
    connect(_socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(_socket, SIGNAL(sslErrors(const QList<QSslError>&)), this,
            SLOT(onSslErrors(const QList<QSslError>&)));
}

SslClientBase::SslClientBase()
    : _socket(nullptr)
{
}

void
SslClientBase::close()
{
    if (_socket) {
        _socket->close();
    }
}

//TODO
void
SslClientBase::setSocket(QSslSocket* socket)
{
    _socket = socket;
    connect(_socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(dataAvailable()));
    connect(_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
    connect(_socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(_socket, SIGNAL(sslErrors(const QList<QSslError>&)), this,
            SLOT(onSslErrors(const QList<QSslError>&)));
}

SslClientBase::~SslClientBase()
{
    if (_socket) {
        delete _socket;
    }
}

void
SslClientBase::sendMessage(QByteArray data)
{
    QDataStream io(&data, QIODevice::ReadOnly);

    QByteArray header(iiNPack::HeaderSize, 0);
    QByteArray load(data.size() - header.size(), 0);

    io.device()->seek(0);
    io.readRawData(header.data(), iiNPack::HeaderSize);
    io.device()->seek(header.size());
    io.readRawData(load.data(), data.size() - header.size());

    sendData(header, load);
}

void
SslClientBase::sendData(const QByteArray& _messageHeader, const QByteArray& _data)
{
    if (_socket) {
        qint64 header_write = _socket->write(_messageHeader);

        if (header_write == _messageHeader.length()) {
            qint64 data_write = _socket->write(_data);

        } else {
            Q_EMIT logMessage(
                tr("DEBUG: Failed to write message header. Only wrote %1 bytes")
                    .arg(header_write), Debug);
        }
    }
}

void
SslClientBase::dataAvailable()
{
    if (_socket) {
        const size_t header_size = iiNPack::HeaderSize;
        QDataStream io(_socket);

        if (_socket->bytesAvailable() > header_size)
        {
            iiNPack::Header header;
            io >> header.Size >>
                header.SendStamp >>
                header.PacketType >>
                header.PacketLoadType;
            if ((quint32)_socket->bytesAvailable() >= header.Size-iiNPack::HeaderSize)
            {
                QByteArray message(header.Size-iiNPack::HeaderSize, 0);
                io.readRawData(message.data(), message.size());

                Q_EMIT logMessage(tr("DEBUG: Recived Message"), Debug);
                Q_EMIT recivedMessage(header, message);
            }
            else
            {
                Q_EMIT logMessage(tr("DEBUG: Failed to read message "
                             "header. Only read %1 bytes").arg(header.Size-iiNPack::HeaderSize), Debug);
            }
        }
        else
        {
            Q_EMIT logMessage(tr("DEBUG: Recived unhendled data packet"), Debug);
        }
    }
}

QSslSocket *
SslClientBase::socket()
{
    return _socket;
}

const QSslKey&
SslClientBase::privateKey() const
{
    return _sslKey;
}

void
SslClientBase::setPrivateKey(const QSslKey& key)
{
    _sslKey = key;
}

const QSslCertificate&
SslClientBase::localCertificate() const
{
    return _sslCertificate;
}

void
SslClientBase::setLocalCertificate(const QSslCertificate& certificate)
{
    _sslCertificate = certificate;
}

void
SslClientBase::socketStateChanged(QAbstractSocket::SocketState _state)
{
    switch (_state) {
        case QAbstractSocket::UnconnectedState:
            Q_EMIT logMessage("Socket Disconnected", Debug);
            break;

        case QAbstractSocket::HostLookupState:
            Q_EMIT logMessage("Looking up host...", Debug);
            break;

        case QAbstractSocket::ConnectingState:
            Q_EMIT logMessage("Connecting socket...", Debug);
            break;

        case QAbstractSocket::ConnectedState:
            Q_EMIT logMessage("Socket Connected", Debug);
            break;

        case QAbstractSocket::BoundState:
            Q_EMIT logMessage("Socket Bound (Server)", Debug);
            break;

        case QAbstractSocket::ClosingState:
            Q_EMIT logMessage("Closing Socket", Debug);
            break;

        case QAbstractSocket::ListeningState:
            Q_EMIT logMessage("Socket Listening for sockets...", Debug);
            break;

        default:
            Q_EMIT logMessage(QString("Unknown Socket State: %1").arg(_state), Debug);
            break;
    };
}

void
SslClientBase::onSslErrors(const QList<QSslError>& errors)
{
    for (auto iter = errors.begin(); iter != errors.end(); ++iter) {
        Q_EMIT logMessage(QString("SSL ERROR: %1").arg(iter->errorString()), Error);
    }
}

void
SslClientBase::onSocketError(QAbstractSocket::SocketError _error)
{
    switch (_error) {
        case QAbstractSocket::ConnectionRefusedError:
            Q_EMIT logMessage(
                "ERROR: _socket Refused by peer or time-out occurred", Error);
            break;
        case QAbstractSocket::RemoteHostClosedError:
            Q_EMIT logMessage("ERROR: Remote Host closed the _socket", Error);
            break;
        case QAbstractSocket::HostNotFoundError:
            Q_EMIT logMessage("ERROR: Remote Host Not Found", Error);
            break;
        case QAbstractSocket::SocketAccessError:
            Q_EMIT logMessage(
                "ERROR: Socket Operation because application lacked "
                "priviledges", Error);
            break;
        case QAbstractSocket::SocketResourceError:
            Q_EMIT logMessage("ERROR: Local system is out of resources", Error);
            break;
        case QAbstractSocket::SocketTimeoutError:
            Q_EMIT logMessage("ERROR: Socket Timed out", Error);
            break;
        case QAbstractSocket::DatagramTooLargeError:
            Q_EMIT logMessage(
                "ERROR: Datagram was larger than the system allowed", Error);
            break;
        case QAbstractSocket::NetworkError:
            Q_EMIT logMessage(
                "ERROR: Network Error occurred. Cable plugged in?", Error);
            break;
        case QAbstractSocket::AddressInUseError:
            Q_EMIT logMessage("ERROR: Address Already In Use", Error);
            break;
        case QAbstractSocket::SocketAddressNotAvailableError:
            Q_EMIT logMessage(
                "ERROR: Specified Address does not belong to the host", Error);
            break;
        case QAbstractSocket::UnsupportedSocketOperationError:
            Q_EMIT logMessage(
                "ERROR: Socket operation not supported by host system", Error);
            break;
        case QAbstractSocket::ProxyAuthenticationRequiredError:
            Q_EMIT logMessage(
                "ERROR: Intermediate Proxy requires authentication", Error);
            break;
        case QAbstractSocket::SslHandshakeFailedError:
            Q_EMIT logMessage("ERROR: SSL/TLS handshake failed.", Error);
            break;
        case QAbstractSocket::UnfinishedSocketOperationError:
            Q_EMIT logMessage(
                "ERROR: Last operation in progress has not yet completed", Error);
            break;
        case QAbstractSocket::ProxyConnectionRefusedError:
            Q_EMIT logMessage(
                "ERROR: Could not contact the intermediate Proxy Server", Error);
            break;
        case QAbstractSocket::ProxyConnectionClosedError:
            Q_EMIT logMessage(
                "ERROR: Proxy _socket was unexpectedly closed", Error);
            break;
        case QAbstractSocket::ProxyConnectionTimeoutError:
            Q_EMIT logMessage("ERROR: Proxy _socket timed-out", Error);
            break;
        case QAbstractSocket::ProxyNotFoundError:
            Q_EMIT logMessage("ERROR: Proxy address was not found", Error);
            break;
        case QAbstractSocket::ProxyProtocolError:
            Q_EMIT logMessage(
                "ERROR: Message from intermediate Proxy Server could not be "
                "understood", Error);
            break;
        case QAbstractSocket::OperationError:
            Q_EMIT logMessage(
                "ERROR: Operation attempted while not in a valid state for "
                "that operation", Error);
            break;
        case QAbstractSocket::SslInternalError:
            Q_EMIT logMessage(
                "ERROR: SSL library reported an internal error. Check SSL "
                "library installation.", Error);
            break;
        case QAbstractSocket::SslInvalidUserDataError:
            Q_EMIT logMessage(
                "ERROR: Invalid data provided to SSL library that resulted in "
                "an error. Check configuration.", Error);
            break;
        case QAbstractSocket::TemporaryError:
            Q_EMIT logMessage(
                "ERROR: Temporary Error Occurred. Please try again", Error);
            break;
        case QAbstractSocket::UnknownSocketError:
            Q_EMIT logMessage("ERROR: Unknown Socket Error occurred", Error);
            break;
        default:
            Q_EMIT logMessage(
                QString("ERROR: Unknown Error (%1) occurred").arg(_error), Error);
            break;
    };
}
