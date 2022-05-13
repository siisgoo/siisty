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
        void doregister(QJsonObject);
        void identify(QString login, QString password);
        void processRequest(QJsonObject, qint64);

    Q_SIGNALS:
        void identified(QJsonObject);
        void identificationFailed(Database::CmdError);

        void registred(QJsonObject);
        void registerFailed(Database::CmdError);

        void addCommand(Database::DatabaseCmd);

    private Q_SLOTS:
        void on_identified(QJsonObject);
        void on_identificationFailed(Database::CmdError err);

        void on_registred(QJsonObject);
        void on_registerFailed(Database::CmdError err);

        void on_requestSuccess(QJsonObject);
        void on_requestFailed(Database::CmdError);

    private:
        Database::DriverAssistant * _dbAssistant;

        QMutex  _mtx;
        qint64  _curStamp;

        int     _max_tries = 10;
        int     _ident_tries = 0;
        bool    _identified = false;

        int _role = -1000; //invalid role
        QString _login;
        QString _password;
            // in advance to security managment
            // this value drops after succeccfuly identification
};

#endif /* end of include guard: IICLIENT_HPP_JINRZSDB */
