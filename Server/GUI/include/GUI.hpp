#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QThread>
#include <QLabel>
#include <QStatusBar>
#include <QListWidget>
#include <QFileInfo>
#include <QScopedPointer>
#include <QMainWindow>

#include "PagesManager.hpp"
#include "Pages/ServerInfoPage.hpp"
#include "Pages/ConnectionsPage.hpp"
#include "Pages/DataUsagePage.hpp"
#include "Pages/SystemLoadPage.hpp"

#include "General/logger.hpp"
#include "SslServer/iiServer.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QMainWindow
{
    Q_OBJECT

    public:
        GUI(QWidget *parent = nullptr);

        void adjustUi();
        void setupLogger();
        void setupServer();

        ~GUI();

    Q_SIGNALS:
        void send_to_log(QString, int);

    private Q_SLOTS:
        void onItemClicked(const QModelIndex&);
            // change page

        void on_listeningStateChanged(QHostAddress, quint16, bool);
        void on_actionQuit_triggered();
        void on_actionStart_server_triggered();
        void on_actionStop_server_triggered();

        void changeIndicatorState(QHostAddress, quint16, bool);
        void logMessage(QString, int);

    private:
        void applyConfig(const QString& path);

        QHostAddress _serveAddress;
        quint16      _serverPort;

        QThread    _serverThread;
        iiServer * _server;

        QThread   _loggingThread;
        logger  * _log;

        QWidget * _cur_page = nullptr;
        QLabel  * _listenIndicator;
        Ui::GUI * ui;
};
#endif // SERVERMANAGER_H
