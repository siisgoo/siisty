#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QThread>
#include <QLabel>
#include <QStatusBar>
#include <QListWidget>
#include <QFileInfo>
#include <QScopedPointer>
#include <QMainWindow>

#include "Database/Database.hpp"

#include "PagesManager.hpp"
#include "Pages/WelcomePage.hpp"
#include "Pages/ServerInfoPage.hpp"
#include "Pages/ConnectionsPage.hpp"
#include "Pages/DataUsagePage.hpp"
#include "Pages/SystemLoadPage.hpp"
#include "Pages/DatabasePage.hpp"

#include "General/logger.hpp"
#include "SslServer/iiServer.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
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
    QString logFile = "./log";

    QString defultPage = "Server Info";

    int maxThreads = QThread::idealThreadCount();
    int maxPendingConnections = 100;
};

class GUI : public QMainWindow
{
    Q_OBJECT

    public:
        GUI(Settings settings, QWidget *parent = nullptr);

        void changeServeAddress(QHostAddress&, quint16);
        void changeLoggingLeve(int level);

        virtual ~GUI();

    Q_SIGNALS:
        void send_to_log(QString, int);

    private Q_SLOTS:
        void onItemClicked(const QModelIndex&);
            // change page

        void on_listeningStateChanged(QHostAddress, quint16, bool);
        void on_actionQuit_triggered();
        void on_actionToggle_server_triggered();

        void on_databaseError(Database::CmdError);
        void on_databaseInited();

        void changeIndicatorState(QHostAddress, quint16, bool);
        void logMessage(QString, int = LoggingLevel::Trace);

        void endProgress();
        void setProgress(int, int);

        void on_clearLogClicked();

    private:
        void adjustUi();
        void setupLogger();
        void setupDatabase();
        void setupServer();

        Settings _settings;

        QThread    _serverThread;
        iiServer * _server;

        QThread            _databaseThread;
        Database::SQLite * _database;

        QThread   _loggingThread;
        logger  * _log;

        QProgressBar * _progress;

        QWidget * _defaultPage = nullptr;
        QWidget * _cur_page = nullptr;
        QLabel  * _listenIndicator;
        Ui::GUI * ui;
};
#endif // SERVERMANAGER_H
