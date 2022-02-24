#ifndef IICLIENT_HPP_JINRZSDB
#define IICLIENT_HPP_JINRZSDB

#include <QSharedPointer>
#include "General/SslClientBase.hpp"

class iiClient : public SslClientBase {
    public:
        iiClient(QSslSocket * socket, QObject* parent = nullptr);
        virtual ~iiClient();

        bool isAutorized() const;

    public Q_SLOTS:
        void performAutorization();

    Q_SIGNALS:
        void autorized(int emploeeID);
        void autorirationFailed(QString& errorMsg);

    private:
        bool    _autorized;
        QString _login;
        QString _password;
};

#endif /* end of include guard: IICLIENT_HPP_JINRZSDB */
