#ifndef QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_H__
#define QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_H__

#include <QHostAddress>
#include <QSslSocket>
#include <QSslKey>
#include <QSslCertificate>
#include <QPointer>
#include <QThread>
#include <QList>
#include <cstdint>

#include "General/SslSocketManager.hpp"

// Purpose: to read/write to sockets in dedicated threads
class SslSocket : public QObject
{
    Q_OBJECT
    public:
        SslSocket(QObject* _parent=NULL, bool is_server_socket=false);
        virtual ~SslSocket();

        void create(QHostAddress _address, qint16 _port);
        void destroy();

        void setSocketDescriptor(qintptr socketDescriptor);
        QSharedPointer<QSslSocket> getSocket() const;

        // required for SSL Server
        const QSslKey& privateKey() const;
        void setPrivateKey(const QSslKey& key);

        // required for SSL Server
        const QSslCertificate& localCertificate() const;
        void setLocalCertificate(const QSslCertificate& certificate);

        bool isServerSocket() const;

    Q_SIGNALS:
        void close();
        void sendMessage(QByteArray _data);
        void sendJson(QByteArray _jsonDocument);
        void receivedMessage(QByteArray _data);
        void receiveJson(QByteArray _jsonDocument);
        void logMessage(QString _message);

    private:
        // thread for the socket
        QThread thread;

        // object for read/writing to the thread
        SslSocketManager socketManager;
        bool server_side_socket;

        // For Encryption support
        QSslKey sslKey;
        QSslCertificate sslCertificate;

    private Q_SLOTS:
        void encrypted();
        void onSocketError(QAbstractSocket::SocketError _error);
        void onSslErrors(const QList<QSslError>& errors);
};

typedef QSharedPointer<SslSocket> ptrTcpSocket;
typedef QList<ptrTcpSocket> listSslSocket;

#endif //QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_H__
