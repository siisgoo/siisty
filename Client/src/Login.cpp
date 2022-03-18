#include "Pages/Login.hpp"
#include "ui_Login.h"

#include <QtSvgWidgets/QSvgWidget>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    { // icon stup
        ui->icon_user->setPixmap(QIcon(":login/user").pixmap(QSize(20, 20)));
        ui->icon_password->setPixmap(QIcon(":login/password").pixmap(QSize(20, 20)));

        ui->logo->setPixmap(QIcon(":logo/big-logo").pixmap(QSize(128, 128)));
    }

    connect(ui->submit, SIGNAL(clicked()), this, SLOT(on_submit_clicked()));
    connect(ui->login, SIGNAL(textChanged(QString)), this, SLOT(on_auth_changed(QString)));
    connect(ui->password, SIGNAL(textChanged(QString)), this, SLOT(on_auth_changed(QString)));
    ui->submit->setEnabled(false);
}

Login::~Login()
{
    delete ui;
}

void
Login::on_submit_clicked()
{
    Q_EMIT tryLogin(ui->login->text(), ui->password->text());
    accept();
}

void
Login::on_auth_changed(QString)
{
    if (ui->login->text().length() > 0 && ui->password->text().length() > 7) {
        ui->submit->setEnabled(true);
    } else {
        ui->submit->setEnabled(false);
    }
}
