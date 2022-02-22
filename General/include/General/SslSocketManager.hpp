#ifndef QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_MANAGER_H__
#define QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_MANAGER_H__

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QSslSocket>

enum messageTypes { jsonMessageType = 1, binaryMessageType = 2 };

struct messageHeader {
    uint32_t length;
    uint32_t type;
};

struct jsonMessage {
    struct messageHeader header;
    uint8_t* data[];
};

struct binaryMessage {
    struct messageHeader header;
    uint8_t* data[];
};

class SslSocketManager : public QObject
{
    Q_OBJECT
    public:
        SslSocketManager(QObject* _parent=NULL);
        virtual ~SslSocketManager();

        void setupSocket(QSharedPointer<QSslSocket> _socket);
        QSharedPointer<QSslSocket> getSocket() const;

    public Q_SLOTS:
        void sendMessage(QByteArray _data);
        void sendJson(QByteArray _jsonDocument);

    Q_SIGNALS:
        void receivedMessage(QByteArray _data);
        void receivedJson(QByteArray _jsonDocument);
        void logMessage(QString _message);

    protected:
        // socket
        QSharedPointer<QSslSocket> connection;

        // receive data
        void sendData(QByteArray _messageHeader, QByteArray _data);

    protected Q_SLOTS:
        virtual void dataAvailable();
        void socketStateChanged(QAbstractSocket::SocketState _state);
};

#endif //QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_MANAGER_H__
