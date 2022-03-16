#include "Pages/Login.hpp"
#include "ui_Login.h"

#include <QtSvgWidgets/QSvgWidget>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}
