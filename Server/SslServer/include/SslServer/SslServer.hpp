#ifndef QT_SSL_EXAMPLE_TCP_SERVER_H__
#define QT_SSL_EXAMPLE_TCP_SERVER_H__

#include <QTcpServer>
#include <QSslKey>
#include <QSslCertificate>
#include <QPointer>

#include "General/SslSocket.hpp"

class SslServer : public QTcpServer
{
    Q_OBJECT
    public:
        SslServer(QObject* _parent=NULL);
        virtual ~SslServer();

        ptrTcpSocket getManagerForConnection(QTcpSocket* _socket);

        void setSslKey(QSslKey& _key);
        void setSslCertificate(QSslCertificate& _certificate);

    Q_SIGNALS:
        // new client connections that live in their own threads
        // the parameter should only be used to establish signals/slot
        // connections
        void newConnection(QSharedPointer<QTcpSocket> _new_tcp_socket);
        void logMessage(QString _message);

    protected:
        virtual void incomingConnection(qintptr socketDescriptor);

    private:
        listSslSocket clients;
        QSslKey sslKey;
        QSslCertificate sslCertificate;
};

typedef QPointer<SslServer> ptrSslServer;

#endif //QT_SSL_EXAMPLE_TCP_SERVER_H__
