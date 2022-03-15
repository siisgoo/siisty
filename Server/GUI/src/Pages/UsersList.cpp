#include "Pages/Users/UsersList.hpp"
#include "ui_UsersList.h"

UsersList::UsersList(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::UsersList)
{
  ui->setupUi(this);
}

UsersList::~UsersList()
{
  delete ui;
}
