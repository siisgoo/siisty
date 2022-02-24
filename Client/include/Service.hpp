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

    private:
        bool _forseUseSsl = false;
};

#endif /* end of include guard: SERVICE_HPP_CBPTLJJQ */
