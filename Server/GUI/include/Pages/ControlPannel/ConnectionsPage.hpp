#ifndef CONNECTIONS_INFO_HPP
#define CONNECTIONS_INFO_HPP

#include <QWidget>

namespace Ui {
class ConnectionsPage;
}

class ConnectionsPage : public QWidget {
    Q_OBJECT

    enum ConnectionsColumns {
        COLUMN_ID,
        COLUMN_IP,
        COLUMN_PORT,
        COLUMN_AUTHED,
        COLUMN_DISCONNECT,
        COLUMNS,
    };

    public:
        ConnectionsPage(QWidget *parent = nullptr);
        ~ConnectionsPage();

    private slots:
        void onClientConnected();
        void onClientDisconnected();
        void onDisconnectClicked();

    private:
        Ui::ConnectionsPage *ui;
};

#endif // ConnectionsPage_HPP
