#ifndef QT_SSL_EXAMPLE_CLIENT_Controller_H__
#define QT_SSL_EXAMPLE_CLIENT_Controller_H__

#include <QMainWindow>
#include <QWidget>
#include <QPointer>
#include <QPushButton>
#include <QTextEdit>
#include <QThread>

#include "Widgets/FloatNotifier.hpp"
#include "General/ClickableLabel.hpp"
#include "General/PagesManager.hpp"
#include "General/logger.hpp"
#include "General/iiNPack.hpp"
#include "Service.hpp"

#include "Pages/Login.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Controller; }
QT_END_NAMESPACE

struct Settings {
    bool useSsl = false;

    QHostAddress _serverAddress = QHostAddress::LocalHost;
    quint16      _serverPort = 2142;

    QHostAddress serveAddress = QHostAddress::AnyIPv4;
    quint16 servePort = 2142;

    QString _login;
    QString _password;

    QString certPath = "./cert.pem";
    QString caPath = "./ca.pem";
    QString keyPath = "./key.pem";

    int logginLeve = LoggingLevel::Trace;
    QString logDir = "./";

    int maxThreads = QThread::idealThreadCount();
};

class userInterface : public QMainWindow {
    Q_OBJECT

    private:
        enum NavPags {
            Empty, // hide nav
        };

    public:
        userInterface(const Settings&, QWidget *parent = NULL);

        virtual ~userInterface();

    Q_SIGNALS:
        void send_to_log(QString message, int level);
        /* void setProgress(int, int, QString, int); */
        void resized(QResizeEvent*);

    public Q_SLOTS:
        void recivedMessage(iiNPack::Header, QByteArray);

        void on_actionLogoutTriggered();

        void tryLogin(QString, QString);

        void on_logined();
        void on_login_failed();
        void on_logouted();

    private Q_SLOTS:
        void changePage(QString);
        void on_pathNodeClicked();
        void showLogin();

        void logMessage(QString _message, int);

        void resizeEvent(QResizeEvent *);

    private:
        void setupLogger();
        void setupService();
        void setupPages();

    protected:
        QThread _loggingThread;
        QThread _serviceThread;
        logger  _log;
        Service _service;

        Settings _settings;

        FloatNotifier * _notifier;

        Ui::Controller * ui;
};

#endif // QT_SSL_EXAMPLE_CLIENT_Controller_H__
