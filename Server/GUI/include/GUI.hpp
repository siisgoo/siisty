#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QGenericMatrix>
#include <QThread>
#include <QLabel>
#include <QStatusBar>
#include <QListWidget>
#include <QFileInfo>
#include <QScopedPointer>
#include <QMainWindow>

#include <initializer_list>

#include "Database/Database.hpp"

#include "Database/Role.hpp"
#include "PagesManager.hpp"
#include "Pages/WelcomePage.hpp"
#include "Pages/ControlPannel/ServerInfoPage.hpp"
#include "Pages/ControlPannel/ConnectionsPage.hpp"

#include "General/Matrix.hpp"
#include "General/logger.hpp"
#include "SslServer/iiServer.hpp"

class PagesPath {
    public:
        // { PageName, { Neightbor1, Neightbor2 }, ... }
        PagesPath(int v) { }
        ~PagesPath() { }

        void addEdge(const QString& src, const QString& dst) {
            _pagesNodes[src].push_back(dst);
        }

        QVector<QString> pathFor(const QString& page) {
            QVector<QString> path;

            for (auto it : _pagesNodes) {
                auto i = std::find_if(it.begin(), it.end(), [](QString) { return true; });
                if (i != it.end()) {
                }
            }

            return path;
        }

    private:

        QVector<QVector<QString>> _pagesNodes;
};

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

    QString defultPage = "Welcome";

    int maxThreads = QThread::idealThreadCount();
    int maxPendingConnections = 100;
};

class GUI : public QMainWindow
{
    Q_OBJECT

    public:
        GUI(Settings settings, QWidget *parent = nullptr);

        virtual ~GUI();

    Q_SIGNALS:
        void send_to_log(QString, int);

        void addCommand(Database::RoleId, QJsonObject&);

    public Q_SLOTS:
        void changeServeAddress(QHostAddress&, quint16);
        void changeLoggingLeve(int level);

    private Q_SLOTS:
        void onOpenPageBtnClicked();
            // change page

        void on_listeningStateChanged(QHostAddress, quint16, bool);
        void on_actionQuit_triggered();
        void on_actionToggle_server_triggered();

        void on_databaseError(Database::CmdError);
            // command exec error
        void on_databaseInited();
        void on_databaseInitializationFailed(QSqlError e);

        void changeIndicatorState(QHostAddress, quint16, bool);
        void logMessage(QString, int = LoggingLevel::Trace);

        void endProgress();
        void setProgress(int, int);

        void on_clearLogClicked();

    private:
        enum NavPages {
            Main = 0,
            ControlPanel = 1,
        };

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
            // page handler + form

        PagesPath * _pagesPath;

        QLabel  * _listenIndicator;
        Ui::GUI * ui;
};
#endif // SERVERMANAGER_H
