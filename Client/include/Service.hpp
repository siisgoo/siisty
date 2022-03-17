#ifndef SERVICE_HPP_CBPTLJJQ
#define SERVICE_HPP_CBPTLJJQ

#include <QObject>
#include <QString>
#include <QHostAddress>

#include "General/SslClientBase.hpp"

class Service : public SslClientBase {
    Q_OBJECT

    public:
        Service(QObject * p = nullptr);
        virtual ~Service();

    Q_SIGNALS:
        void loginSuccess(QString name, int role, int id);
        void loginFailed(int err, QString msg);

        void commandSendSuccess();
        void commandSendFailed();

        void commandResponceSuccess();
        void commandResponceFailed();

    public Q_SLOTS:
        void login();

        void sendCommand(QJsonObject&);

    private:
        bool _forseUseSsl = false;
};

#endif /* end of include guard: SERVICE_HPP_CBPTLJJQ */
