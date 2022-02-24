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
#include "Service.hpp"

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

        void onSendMessageClicked();

        void on_actionLoginTriggered();
        void on_actionLogoutTriggered();

        void on_connetedToServer();
        void on_disconnetedFromServer();

        void on_logined();
        void on_login_failed();
        void on_logouted();

        void logMessage(QString _message, int);

    Q_SIGNALS:
        void send_to_log(QString message, int level);

    private:
        void applyConfig();
        void adjustUi();
        void setupLogger();
        void setupService();

    protected:
        QThread   _loggingThread;
        logger  * _log;

        QThread   _serviceThread;
        Service * _service;

        QHostAddress _serverAddress;
        quint16      _serverPort;

        QString _login;
        QString _password;

        bool _forseUseSsl = false;

        Ui::GUI * ui;
};

#endif // QT_SSL_EXAMPLE_CLIENT_GUI_H__
