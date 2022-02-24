#ifndef IISERVER_HPP_NWEKXGWA
#define IISERVER_HPP_NWEKXGWA

#include <QList>
#include <QSslSocket>
#include "SslServer/SslServer.hpp"
#include "SslServer/iiClient.hpp"

enum ServerState {

};

class iiServer : public QObject {
    Q_OBJECT

    public:
        explicit iiServer(QObject * p = nullptr);
        ~iiServer();

        // Slots to receive signals from UI
        void ToggleStartStopListening(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);
        void LoadCertificates(const QString& certPath, const QString& keyPath);

    Q_SIGNALS:
        void logMessage(QString, int);
        void listeningStateChanged(QHostAddress, quint16, bool);

    protected Q_SLOTS:

        // Slots to receive signals from sockets
        void acceptConnection();
        void handshakeComplete();

        void clientDisconnected();
        void recivedMessage(iiNPack::Header, QByteArray);
            // message from client

        /* void pauseListening(); */

        private:
        QString            _key;
        QString            _certificate;
        SslServer          _server;
        QList<iiClient *> _clients;

        bool _forseUseSsl = false;
};

#endif /* end of include guard: IISERVER_HPP_NWEKXGWA */
