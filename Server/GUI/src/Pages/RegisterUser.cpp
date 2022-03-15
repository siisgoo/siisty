#include "Pages/Users/RegisterUser.hpp"
#include "ui_RegisterUser.h"

RegisterUser::RegisterUser(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RegisterUser)
{
  ui->setupUi(this);
}

RegisterUser::~RegisterUser()
{
  delete ui;
}
