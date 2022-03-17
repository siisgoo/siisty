#include "Pages/Login.hpp"
#include "ui_Login.h"

#include <QtSvgWidgets/QSvgWidget>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QIcon * usr = new QIcon(":login/user");
    QIcon * psw = new QIcon(":login/password");
    ui->icon_user->setPixmap(usr->pixmap(QSize(20, 20)));
    ui->icon_password->setPixmap(psw->pixmap(QSize(20, 20)));

    QIcon * logo = new QIcon(":logo/big-logo");
    ui->logo->setPixmap(logo->pixmap(QSize(128, 128)));
}

Login::~Login()
{
    delete ui;
}
