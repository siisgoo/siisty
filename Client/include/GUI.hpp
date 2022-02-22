#ifndef QT_SSL_EXAMPLE_CLIENT_GUI_H__
#define QT_SSL_EXAMPLE_CLIENT_GUI_H__

#include <QMainWindow>
#include <QWidget>
#include <QPointer>
#include <QPushButton>
#include <QTextEdit>
#include <QThread>

#include "iiNetworkPacket/iiNetworkPacket.hpp"
#include "General/logger.hpp"
#include "Manager.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class userInterface : public QMainWindow
{
    Q_OBJECT

    public:
        userInterface(QWidget *parent = NULL);
        virtual ~userInterface();

    public Q_SLOTS:
        void receivedMessage(QByteArray);

        void startService();
        void stopService();
        void logMessage(QString _message);

        void onSendMessageClicked();

        void on_actionLoginTriggered();
        void on_actionLogoutTriggered();

    Q_SIGNALS:
        void start_service();
        void stop_service();
        void send_to_log(QString _message);

    protected:
        void connectToServer();

        QThread loggingThread;
        logger log;

        QThread serviceThread;
        Manager _manager;

        QHostAddress _serverAddress;
        quint16 _serverPort;

        Ui::GUI * ui;
};

#endif // QT_SSL_EXAMPLE_CLIENT_GUI_H__
