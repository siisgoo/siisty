#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QComboBox>
#include <QThread>
#include <QLabel>
#include <QStatusBar>
#include <QListWidget>
#include <QFileInfo>
#include <QScopedPointer>
#include <QMainWindow>
#include <QDockWidget>
#include <QVBoxLayout>

#include "Database/Database.hpp"
#include "Database/Role.hpp"

#include "PagesManager/PagesManager.hpp"
#include "Pages/WelcomePage.hpp"
#include "Pages/ControlPannel.hpp"
#include "Pages/ControlPannel/ServerInfoPage.hpp"
#include "Pages/ControlPannel/ConnectionsPage.hpp"
#include "Pages/Users.hpp"
#include "Pages/Users/RegisterUser.hpp"
#include "Pages/Users/UsersList.hpp"

#include "Widgets/QLedIndicator.hpp"
#include "Widgets/ClickableLabel.hpp"
#include "Widgets/Notifier/NotifyManager.hpp"
#include "Widgets/Notifier/NotifyProgressItemFactory.hpp"
#include "Widgets/Notifier/NotifyProgressItem.hpp"

#include "Logger/logger.hpp"
#include "iiServer/iiServer.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Controller; }
QT_END_NAMESPACE

struct Settings {
    bool useSsl = false;

    QString certPath = "./cert.pem";
    QString caPath = "./ca.pem";
    QString keyPath = "./key.pem";

    QHostAddress serveAddress = QHostAddress::AnyIPv4;
    quint16 servePort = 2142;

    QString databasePath = "./database.db";

    int logginLeve = LoggingLevel::Trace;
    QString logDir = "./log";

    QString defultPage = "Welcome";

    int maxThreads = QThread::idealThreadCount();
    int maxPendingConnections = 100;
};

class Controller : public QMainWindow
{
    Q_OBJECT

    public:
        Controller(Settings settings, QWidget *parent = nullptr);

        virtual ~Controller();

    Q_SIGNALS:
        void resized(QResizeEvent*);
        void createNotifyItem(NotifyItemFactory *, int&);
        void setNotifyItemPropery(int uid, const QByteArray& name, const QVariant& value);
        void send_to_log(QString, int);

    public Q_SLOTS:
        void changeServeAddress(QHostAddress&, quint16);
        void changeLoggingLeve(int level);

    private Q_SLOTS:
        void setupPages();
        void connectPages();
        void setupServer();

        void on_listeningStateChanged(QHostAddress, quint16, bool);
        void on_actionQuit_triggered();
        void on_actionToggle_server_triggered();

        void on_databaseError(Database::CmdError);
            // command exec error
        void on_databaseInited();
        void on_databaseInitializationFailed(QSqlError e);

        void on_pathNodeClicked();
            // draw path
        void changePage(QString);

        void changeIndicatorState(QHostAddress, quint16, bool);
        void logMessage(QString, int = LoggingLevel::Trace);

        void on_clearLogClicked();

        virtual void resizeEvent(QResizeEvent*);

    private:
        enum class NavPages {
            Main = 0,
            ControlPannel,
            Users,
            COUNT,
        };

    private:
        Settings _settings;

        QThread _databaseThread;
        QThread _loggingThread;
        QThread _serverThread;
        iiServer _server;
        logger   _log;
        Database::Driver _database;

        NotifyManager * _notifier;

        NotifyProgressItemFactory * f;
        int item_uid1;
        int item_uid2;
        int item_uid3;
        int item_uid4;

        int i1 = 0;
        int i2 = 0;
        int i3 = 0;
        int i4 = 0;

        QTimer _timer1;
        QTimer _timer2;
        QTimer _timer3;
        QTimer _timer4;

        QLedIndicator * _listenIndicator;
        Ui::Controller * ui;
};
#endif // SERVERMANAGER_H
