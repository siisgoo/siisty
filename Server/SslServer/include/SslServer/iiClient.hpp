#ifndef IICLIENT_HPP_JINRZSDB
#define IICLIENT_HPP_JINRZSDB

#include <QSharedPointer>
#include "General/SslClientBase.hpp"

class iiClient : public SslClientBase {
    public:
        iiClient(QSslSocket * socket, QObject* parent = nullptr);
        virtual ~iiClient();

        bool isAuth() const;

    public Q_SLOTS:
        void performAuthentification();

    Q_SIGNALS:
        void authentificated(int emploeeID);
        void authentificationFailed(QString& errorMsg);

    private:
        bool    _autorized;
        QString _login;
        QString _password;
};

#endif /* end of include guard: IICLIENT_HPP_JINRZSDB */
