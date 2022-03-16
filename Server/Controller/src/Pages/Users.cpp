#include "Pages/Users.hpp"
#include "ui_Users.h"

Users::Users(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Users)
{
  ui->setupUi(this);
}

Users::~Users()
{
  delete ui;
}
