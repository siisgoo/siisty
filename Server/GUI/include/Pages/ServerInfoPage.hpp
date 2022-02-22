#ifndef SERVER_INFO_H
#define SERVER_INFO_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>

namespace Ui { class ServerInfoPage; }

class ServerInfoPage : public QWidget {
    Q_OBJECT

    public:
        ServerInfoPage(QWidget *parent = nullptr);
        ~ServerInfoPage();

    private slots:
        void updateOnlineTime();
        void onServerListningStateChanged(bool);


private:
    QTime    _startTime;
    QTimer * _timer;
    Ui::ServerInfoPage *ui;
};

#endif // ServerInfoPage_H
