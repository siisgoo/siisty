#ifndef SSLSERVERMANAGER_HPP_KEBPCMOM
#define SSLSERVERMANAGER_HPP_KEBPCMOM

#include <QObject>
#include <QString>
#include <QPointer>
#include <QHostAddress>
#include <QSslKey>
#include <QSslCertificate>

#include "SslServer/SslServer.hpp"

class SslServerManager: public QObject
{
    Q_OBJECT
    public:
        SslServerManager(QObject* _parent=NULL);
        virtual ~SslServerManager();

        const QHostAddress& getHost() const;
        qint16 getPort() const;

    public Q_SLOTS:
        void start_service();
        void stop_service();

        void setServerConfig(QHostAddress _address, qint16 _port);
        void setMaxPending(int _connections);
        void setSslKey(QSslKey& _key);
        void setSslCertificate(QSslCertificate& _certificate);

    Q_SIGNALS:
        void logMessage(QString _message);
        void listenStateChanged(bool listening);

    protected:
        QHostAddress address;
        qint16 port;

        SslServer theSslServer;

    protected Q_SLOTS:
        virtual void newConnection();
        void acceptError(QAbstractSocket::SocketError socketError);
};
typedef QPointer<SslServerManager> ptrSslServerManager;

#endif /* end of include guard: SSLSERVERMANAGER_HPP_KEBPCMOM */
