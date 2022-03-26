#ifndef SERVICE_HPP_CBPTLJJQ
#define SERVICE_HPP_CBPTLJJQ

#include <QString>
#include <QHostAddress>

#include "Network/SslClientBase.hpp"
#include "Database/Database.hpp"

/* class ResponseWaiter : public QObject { */
/*     public: */
/*         ResponseWaiter(); */
/*         virtual ~ResponseWaiter(); */
/* }; */

class Service : public SslClientBase {
    Q_OBJECT

    public:
        Service(QObject * p = nullptr);
        virtual ~Service();

    Q_SIGNALS:
        void loginSuccess(QString, int, int); // name, role, id
        void loginFailed(int, QString);

        void commandSuccess(QJsonObject);
        void commandFailed(int, QString details);

    public Q_SLOTS:
        void login(const QString& login, const QString& password);

        void sendCommand(QJsonObject&);

    private Q_SLOTS:
        void parseResonce(iiNPack::Header, QByteArray);

        void parseLoginResponce(QJsonObject);

        void on_sslError(const QList<QSslError>&);
        void on_networkError(QAbstractSocket::SocketError);

    private:
};

#endif /* end of include guard: SERVICE_HPP_CBPTLJJQ */
