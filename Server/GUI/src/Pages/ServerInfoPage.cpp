#include "Pages/ServerInfoPage.hpp"
#include "ui_ServerInfoPage.h"

#include "SslServer/SslServerManager.hpp"

#include <QTimer>
#include <QDateTime>

ServerInfoPage::ServerInfoPage(QWidget *parent) :
    QWidget(parent),
        ui(new Ui::ServerInfoPage),
        _timer(new QTimer(this))
{
    this->setObjectName("Server info");

    connect(_timer, SIGNAL(timeout()), this, SLOT(updateOnlineTime()));

    ui->setupUi(this);
}

ServerInfoPage::~ServerInfoPage()
{
    delete _timer;
    delete ui;
}

void
ServerInfoPage::updateOnlineTime()
{
    QTime cur = QTime::currentTime();
    QTime elapced;
    elapced.setHMS(cur.hour()-_startTime.hour(),
                   cur.minute()-_startTime.minute(),
                   cur.second()-_startTime.second());
    ui->label_online_time->setText(elapced.toString("h : m : s"));
}

void
ServerInfoPage::onServerListningStateChanged(bool listening)
{
    SslServerManager * manager = (SslServerManager*)sender();
    if (listening) {
        _startTime = QTime::currentTime();
        _timer->start(1000);
        ui->server_port_edit->setText(QString::number(manager->getPort()));
        ui->label_server_status->setText("Listening");
    } else {
        _timer->stop();
        ui->server_port_edit->setText(QString::number(manager->getPort()));
        ui->label_server_status->setText("Offline");
        ui->label_online_time->setText("h : m : s");
    }
}
