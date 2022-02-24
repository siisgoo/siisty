#ifndef SSLCLIENTBASE_HPP_NQAPT2TY
#define SSLCLIENTBASE_HPP_NQAPT2TY

#include "General/iiNPack.hpp"
#include <QSslKey>
#include <QSslSocket>
#include <QSharedPointer>
#include <QPointer>

class SslClientBase : public QObject {
    Q_OBJECT

    public:
        SslClientBase();
        SslClientBase(QSslSocket *);
        virtual ~SslClientBase();

        void setSocket(QSslSocket *);
        QSslSocket * socket();

        const QSslKey& privateKey() const;
        void setPrivateKey(const QSslKey& key);

        const QSslCertificate& localCertificate() const;
        void setLocalCertificate(const QSslCertificate& certificate);

    Q_SIGNALS:
        void recivedMessage(iiNPack::Header, QByteArray _data);
        void logMessage(QString, int);

        void disconnected();

    public Q_SLOTS:
        virtual void sendMessage(QByteArray);
        void close();

    protected Q_SLOTS:
        virtual void dataAvailable();
        void socketStateChanged(QAbstractSocket::SocketState);

    private Q_SLOTS:
        void onSocketError(QAbstractSocket::SocketError);
        void onSslErrors(const QList<QSslError>&);

    protected:
        QSslSocket *    _socket;
        QSslKey         _sslKey;
        QSslCertificate _sslCertificate;

        virtual void sendData(const QByteArray& header, const QByteArray& load);
};

#endif /* end of include guard: SSLCLIENTBASE_HPP_NQAPT2TY */
