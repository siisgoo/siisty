#include "Pages/DatabasePage.hpp"
#include "ui_DatabasePage.h"

DatabasePage::DatabasePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabasePage)
{
    ui->setupUi(this);
}

DatabasePage::~DatabasePage()
{
    delete ui;
}
