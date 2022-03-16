#ifndef QT_SSL_EXAMPLE_CLIENT_Controller_H__
#define QT_SSL_EXAMPLE_CLIENT_Controller_H__

#include <QMainWindow>
#include <QWidget>
#include <QPointer>
#include <QPushButton>
#include <QTextEdit>
#include <QThread>

#include "General/ClickableLabel.hpp"
#include "General/PagesManager.hpp"
#include "General/logger.hpp"
#include "General/iiNPack.hpp"
#include "Service.hpp"

#include "Pages/Login.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Controller; }
QT_END_NAMESPACE

class userInterface : public QMainWindow {
    Q_OBJECT

    private:
        enum NavPags {
            LoginNav = -1,
        };

    public:
        userInterface(QWidget *parent = NULL);

        virtual ~userInterface();

    Q_SIGNALS:
        void send_to_log(QString message, int level);

    private Q_SLOTS:
        void changePage(QString);
        void on_pathNodeClicked();

    public Q_SLOTS:
        void recivedMessage(iiNPack::Header, QByteArray);

        void on_actionLoginTriggered();
        void on_actionLogoutTriggered();

        void on_connetedToServer();
        void on_disconnetedFromServer();

        void on_logined();
        void on_login_failed();
        void on_logouted();

        void logMessage(QString _message, int);

    private:
        void setupLogger();
        void setupService();
        void setupPages();

    protected:
        QThread _loggingThread;
        logger  _log;

        QThread _serviceThread;
        Service _service;

        QHostAddress _serverAddress;
        quint16      _serverPort;

        QString _login;
        QString _password;

        bool _forseUseSsl = false;

        Ui::Controller * ui;
};

#endif // QT_SSL_EXAMPLE_CLIENT_Controller_H__
