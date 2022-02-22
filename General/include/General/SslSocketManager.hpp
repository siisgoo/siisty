#ifndef QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_MANAGER_H__
#define QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_MANAGER_H__

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QSslSocket>

class SslSocketManager : public QObject
{
    Q_OBJECT
    public:
        SslSocketManager(QObject* _parent=NULL);
        virtual ~SslSocketManager();

        void setupSocket(QSharedPointer<QSslSocket> _socket);
        QSharedPointer<QSslSocket> getSocket() const;

    public Q_SLOTS:
        void sendIIPack(QByteArray data);

    Q_SIGNALS:
        void receivedMessage(QByteArray data);
        void logMessage(QString _message);

    protected:
        // socket
        QSharedPointer<QSslSocket> connection;

        void sendData(QByteArray header, QByteArray data);

    protected Q_SLOTS:
        virtual void dataAvailable();
        void socketStateChanged(QAbstractSocket::SocketState _state);
};

#endif //QT_SSL_EXAMPLE_COMMON_TCP_SOCKET_MANAGER_H__
