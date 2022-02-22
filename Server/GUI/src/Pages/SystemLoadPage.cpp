#include "Pages/SystemLoadPage.hpp"
#include "ui_SystemLoadPage.h"

SystemLoadPage::SystemLoadPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemLoadPage)
{
    this->setObjectName("System load");

    ui->setupUi(this);
}

SystemLoadPage::~SystemLoadPage()
{
    delete ui;
}
