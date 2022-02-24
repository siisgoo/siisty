#ifndef QT_SSL_EXAMPLE_CLIENT_GUI_H__
#define QT_SSL_EXAMPLE_CLIENT_GUI_H__

#include <QMainWindow>
#include <QWidget>
#include <QPointer>
#include <QPushButton>
#include <QTextEdit>
#include <QThread>

#include "General/logger.hpp"
#include "General/iiNPack.hpp"
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
        void recivedMessage(iiNPack::Header, QByteArray);

        void startService();
        void stopService();
        void logMessage(QString _message);

        void onSendMessageClicked();

        void on_actionLoginTriggered();
        void on_actionLogoutTriggered();

        void on_connetedToServer();
        void on_disconnetedFromServer();
            // on socket connected/encrypted

        void on_logined();
        void on_login_failed();
        void on_logouted();

    Q_SIGNALS:
        void start_service();
        void stop_service();
        void send_to_log(QString _message);

    private:
        void applyConfig();
        void setupLogger();
        void setupService();

    protected:
        QThread   _loggingThread;
        logger  * _log;

        QThread   _serviceThread;
        Service * _service;

        QString _login;
        QString _password;

        Ui::GUI * ui;
};

#endif // QT_SSL_EXAMPLE_CLIENT_GUI_H__
