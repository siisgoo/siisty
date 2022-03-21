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

#include "Widgets/NotifyProgressItem.hpp"
#include "Widgets/NotifyProgressItemFactory.hpp"
#include "Widgets/NotifyMsgItem.hpp"
#include "Widgets/NotifyMsgItemFactory.hpp"

#include "Pages/Login.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Controller; }
QT_END_NAMESPACE

struct Settings {
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
        void createNotifyItem(NotifyItemFactory*, int&);
        void setNotifyItemPropery(int, const QByteArray&, const QVariant&);
        void resized(QResizeEvent*);

    public Q_SLOTS:
        void on_actionLogoutTriggered();

        void tryLogin(ConnectSettings);

        void saveAuth();
        void readAuth();

    private Q_SLOTS:
        void changePage(QString);
        void on_pathNodeClicked();

        void showLogin();

        void on_conneted();
        void on_disconnetWhenLogin();
        void on_logined(QString name, int role, int id);
        void on_login_failed(int, QString);
        void on_logouted();

        void logMessage(QString _message, int);

        void resizeEvent(QResizeEvent *);

    private:
        void setupPages();

    protected:
        QThread _loggingThread;
        QThread _serviceThread;
        logger  _log;
        Service _service;

        Settings _settings;

        NotifyProgressItemFactory * _npf;
        NotifyMsgItemFactory * _nmf;
        FloatNotifier * _notifier;

        ConnectSettings _conn_s;
        int _login_puid;

        Ui::Controller * ui;
};

#endif // QT_SSL_EXAMPLE_CLIENT_Controller_H__
