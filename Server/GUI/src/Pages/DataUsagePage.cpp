#include "Pages/DataUsagePage.hpp"
#include "ui_DataUsagePage.h"

DataUsagePage::DataUsagePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataUsagePage)
{
    this->setObjectName("Data usage");

    ui->setupUi(this);
}

DataUsagePage::~DataUsagePage()
{
    delete ui;
}
