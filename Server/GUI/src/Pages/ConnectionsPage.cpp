#include "Pages/ControlPannel/ConnectionsPage.hpp"
#include "ui_ConnectionsPage.h"

#include <QDebug>
#include <QPushButton>

ConnectionsPage::ConnectionsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionsPage)
{
    ui->setupUi(this);

    this->setObjectName("Connections");

    ui->label_connected_clients_count->setText("0");

    /* connect(_server, SIGNAL(clientConnected(const Server::Client*)),    this, SLOT(onClientConnected(const Server::Client*))); */
    /* connect(_server, SIGNAL(clientDisconnected(const Server::Client*)), this, SLOT(onClientDisconnected(const Server::Client*))); */
}

ConnectionsPage::~ConnectionsPage()
{
    delete ui;
}

void
ConnectionsPage::onClientConnected()
{
    /* int connections_count = ui->connected_clients->rowCount(); */
    /* ui->label_connected_clients_count->setText(QString::number(connections_count+1)); */
    /* int row = connections_count; */

    /* ui->connected_clients->insertRow(row); */

    /* ui->connected_clients->setItem(row, COLUMN_ID, new QTableWidgetItem(QString::number(row))); */
    /* ui->connected_clients->setItem(row, COLUMN_IP, new QTableWidgetItem(cli->host().toString())); */
    /* ui->connected_clients->setItem(row, COLUMN_PORT, new QTableWidgetItem(QString::number(cli->port()))); */
    /* ui->connected_clients->setItem(row, COLUMN_AUTHED, new QTableWidgetItem("Not implemented")); */

    /* QPushButton * button; */
    /* button = new QPushButton("disconnect", ui->connected_clients); */
    /* ui->connected_clients->setCellWidget(row, COLUMN_DISCONNECT, button); */

    /* connect(button, SIGNAL(clicked()), this, SLOT(onDisconnectClicked())); */
}

void
ConnectionsPage::onClientDisconnected()
{
    /* int connections_count = ui->connected_clients->rowCount(); */
    /* ui->label_connected_clients_count->setText(QString::number(connections_count-1)); */

    /* int row = -1; */
    /* for (int i = 0; i < connections_count; i++) { */
    /*     if (ui->connected_clients->takeItem(i, COLUMN_IP)->text() == cli->host().toString() && */
    /*             ui->connected_clients->takeItem(i, COLUMN_PORT)->text() == QString::number(cli->port())) { */
    /*         row = i; */
    /*         break; */
    /*     } */
    /* } */

    /* if (row < 0) { */
    /*     throw "asdf ererer TODO logger"; */
    /* } */

    /* /1* for (int i = 0; i < COLUMNS; i++) { *1/ */
    /* /1*     delete ui->connected_clients->takeItem(row, i); *1/ */
    /* /1* } *1/ */

    /* ui->connected_clients->removeRow(row); */
}

void
ConnectionsPage::onDisconnectClicked()
{
    /* int row = ui->connected_clients->currentRow(); */
    /* QString ip = ui->connected_clients->item(row, COLUMN_IP)->text(); */
    /* QString port = ui->connected_clients->item(row, COLUMN_PORT)->text(); */

    /* _server->disconnectClient(QHostAddress(ip), port.toUInt()); */
}
