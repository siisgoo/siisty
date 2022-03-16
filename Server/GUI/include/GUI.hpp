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
#include "Pages/ControlPannel.hpp"
#include "Pages/ControlPannel/ServerInfoPage.hpp"
#include "Pages/ControlPannel/ConnectionsPage.hpp"
#include "Pages/Users.hpp"
#include "Pages/Users/RegisterUser.hpp"
#include "Pages/Users/UsersList.hpp"

#include "General/Matrix.hpp"
#include "General/logger.hpp"
#include "SslServer/iiServer.hpp"

class ClickableLabel : public QLabel {
    Q_OBJECT

   public:
        explicit ClickableLabel(QString txt, QWidget *p = nullptr,
                Qt::WindowFlags f = Qt::WindowFlags())
        : QLabel(txt) { this->setParent(p); }
        virtual ~ClickableLabel() { }

   signals:
        void clicked();

   protected:
        virtual void mousePressEvent(QMouseEvent* event) {
            Q_EMIT clicked();
        }
};

class PagesPath {
    public:
        PagesPath() { }
        ~PagesPath() { }

        void setRoot(const QString& root) {
            _root = root;
        }

        void addEdge(const QString& src, const QString& dst) {
            _pagesNodes[src].push_back(dst);
        }

        void addEdge(const QString& src, const QVector<QString>& dst) {
            _pagesNodes[src] = dst;
        }

        // add checks
        // redo with recuse?
        //
        // may be pre-create all avalible pathes?
        //
        // problem: unique names not supported!
        QVector<QString> pathFor(const QString& page) const {
            QVector<QString> path { page };
            QString search = page;
            bool done = false, inn_done = false;

            while (!done) {
                QMap<QString, QVector<QString>>::const_iterator i = _pagesNodes.constBegin();
                inn_done = false;
                while (i != _pagesNodes.constEnd() && !done && !inn_done) {
                    if (search == _root) { //found
                        done=true;
                    }
                    for (auto node : i.value()) {
                        if (node == search) {
                            search = i.key();
                            path.push_front(search);
                            inn_done = true;
                            break;
                        }
                    }
                    i++;
                }
            }

            return path;
        }

        void print() {
            qDebug() << _pagesNodes;
        }

    private:
        QString _root;
        QMap<QString, QVector<QString>> _pagesNodes;
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

    public Q_SLOTS:
        void changeServeAddress(QHostAddress&, quint16);
        void changeLoggingLeve(int level);

    private Q_SLOTS:
        void setupPages();
        void setupLogger();
        void setupDatabase();
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

        void endProgress();
        void setProgress(int, int);

        void on_clearLogClicked();

    private:
        enum class NavPages {
            Main = 0,
            ControlPannel,
            Users,
            COUNT,
        };

    private:
        Settings _settings;

        QThread    _serverThread;
        iiServer * _server;

        QThread            _databaseThread;
        Database::SQLite * _database;

        QThread   _loggingThread;
        logger  * _log;

        QProgressBar * _progress;

        QString _defaultPage;

        PagesPath _pagesPath;

        QWidget * _listenIndicator;
        Ui::GUI * ui;
};
#endif // SERVERMANAGER_H
