#ifndef IICLIENT_HPP_JINRZSDB
#define IICLIENT_HPP_JINRZSDB

#include <QSharedPointer>
#include "General/SslClientBase.hpp"

class iiClient : public SslClientBase {
    public:
        iiClient(QSslSocket * socket, QObject* parent = nullptr);
        virtual ~iiClient();

        bool identified() const;

    public Q_SLOTS:
        void identify();

    Q_SIGNALS:
        void identified(int emploeeID);
        void identificationFailed(QString& errorMsg);

    private:
        bool    _identified = false;
        QString _login;
        QString _password;
            // in advance to security managment
            // this value drops after succeccfuly identification
};

#endif /* end of include guard: IICLIENT_HPP_JINRZSDB */
