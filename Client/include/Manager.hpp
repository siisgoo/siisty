#ifndef MANAGER_HPP_GITUCPY2
#define MANAGER_HPP_GITUCPY2

#include <QObject>
#include <QString>
#include <QHostAddress>

#include "General/SslSocket.hpp"

class Manager : public QObject {
    Q_OBJECT

    public:
        Manager(QObject * p = nullptr);
        virtual ~Manager();

    Q_SIGNALS:
        void connected();
        void encrypted();
        void receivedMessage(QByteArray);
        void sendMessage(QByteArray);
        void logMessage(QString _message);

    public Q_SLOTS:
        void start_control();
        void stop_control();

    private:
        QHostAddress address;
        qint16 port;

        SslSocket control;
};

#endif /* end of include guard: MANAGER_HPP_GITUCPY2 */
