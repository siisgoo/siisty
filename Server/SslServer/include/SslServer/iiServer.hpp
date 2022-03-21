#ifndef IISERVER_HPP_NWEKXGWA
#define IISERVER_HPP_NWEKXGWA

#include <QList>
#include <QSslSocket>
#include "Database/Database.hpp"
#include "SslServer/SslServer.hpp"
#include "SslServer/iiClient.hpp"

#include "General/logger.hpp"

enum ServerState {

};

class iiServer : public QObject {
    Q_OBJECT

    public:
        explicit iiServer(QObject * p = nullptr);
        ~iiServer();

        bool isListening() const;

        // Slots to receive signals from UI
        void ToggleStartStopListening(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);
        void LoadCertificates(const QString& certPath, const QString& keyPath);

        int maxPendingConnections() const;
        void setMaxPendingConnections(int);
        void setForseUseSsl(bool);

    Q_SIGNALS:
        void logMessage(QString, int = LoggingLevel::Trace);
        void listeningStateChanged(QHostAddress, quint16, bool);

        void addCommand(Database::Driver::DatabaseCmd);

    protected Q_SLOTS:

        // Slots to receive signals from sockets
        void acceptConnection();
        void handshakeComplete();

        void clientDisconnected();
        void recivedMessage(iiNPack::Header, QByteArray);
            // message from client

        /* void pauseListening(); */

    private:
        QHostAddress _address;
        quint16 _port;

        QString          _key;
        QString          _certificate;
        SslServer        _server;
        QList<iiClient *> _clients;

        bool _forseUseSsl = false;
};

#endif /* end of include guard: IISERVER_HPP_NWEKXGWA */
