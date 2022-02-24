#ifndef MANAGER_HPP_GITUCPY2
#define MANAGER_HPP_GITUCPY2

#include <QObject>
#include <QString>
#include <QHostAddress>

#include "General/SslClientBase.hpp"

class Service : public QObject {
    Q_OBJECT

    public:
        Service(QObject * p = nullptr);
        virtual ~Service();

        SslClientBase * control();

        void setServerAddress(const QHostAddress& add, quint16 port);
        QAbstractSocket::SocketState SocketState();

    Q_SIGNALS:
        void connected();
        void disconnected();
        void recivedMessage(iiNPack::Header, QByteArray);
        void sendMessage(QByteArray);

        void logMessage(QString);

    public Q_SLOTS:
        void connectToServer();
        void disconnectFromServer();

        void sslErrors(const QList<QSslError>&);
        void socketError(QAbstractSocket::SocketError);

    private:
        QHostAddress _serverAddress;
        qint16       _serverPort;

        SslClientBase * _control;

        bool _forseUseSsl = false;
};

#endif /* end of include guard: MANAGER_HPP_GITUCPY2 */
