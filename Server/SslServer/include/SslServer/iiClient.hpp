#ifndef IICLIENT_HPP_JINRZSDB
#define IICLIENT_HPP_JINRZSDB

#include <QSharedPointer>
#include "General/SslClientBase.hpp"

class iiClient : public SslClientBase {
    public:
        iiClient(QSslSocket*);
        virtual ~iiClient();

    private:
        bool    _autorized;
        QString _login;
        QString _password;
};

using ptrClient = QPointer<iiClient>;

#endif /* end of include guard: IICLIENT_HPP_JINRZSDB */
