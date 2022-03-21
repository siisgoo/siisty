#ifndef IICLIENT_HPP_JINRZSDB
#define IICLIENT_HPP_JINRZSDB

#include "Database/Database.hpp"
#include "Network/SslClientBase.hpp"

class iiClient : public SslClientBase {
    Q_OBJECT

    public:
        iiClient(QSslSocket * socket, QObject* parent = nullptr);
        virtual ~iiClient();

        bool identified() const;

    public Q_SLOTS:
        void identify(QString login, QString password);
        void processRequest(QJsonObject);
        void processResponce(QJsonObject);

    Q_SIGNALS:
        void identified(QJsonObject);
        void identificationFailed(Database::CmdError);

        void requestSuccess(QJsonObject);
        void requestFailed(Database::CmdError);

        void addCommand(Database::DatabaseCmd);

    private Q_SLOTS:
        void on_identified(QJsonObject);
        void on_identificationFailed(Database::CmdError err);

    private:
        Database::DriverAssistant * _dbAssistant;

        int     _max_tries = 10;
        int     _ident_tries = 0;
        bool    _identified = false;
        QString _login;
        QString _password;
            // in advance to security managment
            // this value drops after succeccfuly identification
};

#endif /* end of include guard: IICLIENT_HPP_JINRZSDB */
