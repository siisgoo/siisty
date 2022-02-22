#include "General/SslSocketManager.hpp"
#include "iiNetworkPacket/iiNetworkPacket.hpp"

#include <QIODevice>

SslSocketManager::SslSocketManager(QObject* _parent) : QObject(_parent) {}
SslSocketManager::~SslSocketManager() {
    if (connection.isNull() == false) {
        connection.data()->close();
    }
}

void SslSocketManager::setupSocket(QSharedPointer<QSslSocket> _socket) {
    if (_socket.isNull() == false) {
        connection = _socket;
        connect(connection.data(), SIGNAL(readyRead()), this,
                SLOT(dataAvailable()));
        connect(connection.data(),
                SIGNAL(stateChanged(QAbstractSocket::SocketState)), this,
                SLOT(socketStateChanged(QAbstractSocket::SocketState)));
    }
}
QSharedPointer<QSslSocket> SslSocketManager::getSocket() const {
    return connection;
}

void SslSocketManager::socketStateChanged(QAbstractSocket::SocketState _state) {
    switch (_state) {
        case QAbstractSocket::UnconnectedState:
            Q_EMIT logMessage("Socket Disconnected");
            break;

        case QAbstractSocket::HostLookupState:
            Q_EMIT logMessage("Looking up host...");
            break;

        case QAbstractSocket::ConnectingState:
            Q_EMIT logMessage("Connecting socket...");
            break;

        case QAbstractSocket::ConnectedState:
            Q_EMIT logMessage("Socket Connected");
            break;

        case QAbstractSocket::BoundState:
            Q_EMIT logMessage("Socket Bound (Server)");
            break;

        case QAbstractSocket::ClosingState:
            Q_EMIT logMessage("Closing Socket");
            break;

        case QAbstractSocket::ListeningState:
            Q_EMIT logMessage("Socket Listening for connections...");
            break;

        default:
            Q_EMIT logMessage(QString("Unknown Socket State: %1").arg(_state));
            break;
    };
}

void SslSocketManager::sendIIPack(QByteArray data) {
    QDataStream io(&data, QIODevice::ReadOnly);

    QByteArray header;
    QByteArray load;

    io.device()->seek(0);
    io.readRawData(header.data(), iiNPack::HeaderSize);
    /* io.device()->seek( */
    /* io >> load; */
    io.readRawData(load.data(), data.size() - header.size());

    sendData(header, load);
}

void SslSocketManager::sendData(QByteArray _messageHeader, QByteArray _data) {
    if (connection.isNull() == false) {
        qint64 header_write = connection.data()->write(_messageHeader);

        if (header_write == _messageHeader.length()) {
            qint64 data_write = connection.data()->write(_data);
        } else {
            Q_EMIT logMessage(
                tr("DEBUG: Failed to write message header. Only wrote %1 bytes")
                    .arg(header_write));
        }
    }
}

void SslSocketManager::dataAvailable() {
    /*
        Peek to see if all the data is available
        If it is, read it, remove the header, and send it up the chain using the
       associated signal
     */
    if (connection.isNull() == false)
    {
        const size_t header_size = iiNPack::HeaderSize;

        if (connection.data()->bytesAvailable() > header_size)
        {
            iiNPack::Header header;
            memset(&header, 0, header_size);

            qint64 header_peek =
                connection.data()->peek((char*)&header, header_size);
            if (header_peek == header_size)
            {
                if (connection.data()->bytesAvailable() >= header.Size)
                {
                    iiNPack::Header dummyHeader;
                    memset(&header, 0, header_size);
                    qint64 header_read =
                        connection.data()->read((char*)&header, header_size);

                    if (header_read == header_size)
                    {
                        int message_size = header.Size - header_size;
                        if (message_size > 0)
                        {
                            QByteArray message(header.Size, 0);
                            qint64 message_read = connection.data()->read(
                                message.data(), header.Size);

                            Q_EMIT logMessage(
                                tr("DEBUG: Received Message"));
                            Q_EMIT receivedMessage(message);
                        }
                        else
                        {
                            Q_EMIT logMessage(tr("DEBUG: received message with "
                                                 "invalid size of %1 bytes.")
                                                  .arg(message_size));
                        }
                    }
                    else
                    {
                        Q_EMIT logMessage(tr("DEBUG: Failed to read message "
                                             "header. Only read %1 bytes")
                                              .arg(header_read));
                    }
                }
            }
        }
    }
}
