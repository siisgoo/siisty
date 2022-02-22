#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

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

#include "QLedIndicator/QLedIndicator.hpp"

#include "General/logger.hpp"
#include "General/SslSocketManager.hpp"
#include "SslServer/SslServerManager.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QMainWindow
{
    Q_OBJECT

    public:
        GUI(QWidget *parent = nullptr);

        void setup();
        void adjustUi();
        void setupServer();

        ~GUI();

    Q_SIGNALS:
        void send_to_log(QString);

    private Q_SLOTS:
        void onItemClicked(const QModelIndex&);
            // change page

        void changeLedState(bool listening);

        void logMessage(QString);

        void on_actionQuit_triggered();
        void on_actionStart_server_triggered();
        void on_actionStop_server_triggered();

    private:
        void connect_db(const QString& path);
        void apply_config(const QString& path);

        QThread             _managerThread;
        ptrSslServerManager _manager;

        QWidget * _cur_page = nullptr;

        QThread _loggingThread;
        logger  _log;

        QLedIndicator * _led;
        Ui::GUI       * ui;
};
#endif // SERVERMANAGER_H
