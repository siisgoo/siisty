#include "MainPage.hpp"
#include "ui_MainPage.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    QPixmap userLP = QPixmap(":login/cusomerLogin");
    userLP.scaled(300, 218);
    ui->userLogin->setIcon(QIcon(userLP));
    /* ui->employeeLogin->setIcon(QIcon(employeeLP)); */

    connect(ui->userLogin, SIGNAL(clicked()), this, SIGNAL(loginClicked()));
    connect(ui->singup, SIGNAL(clicked()), this, SIGNAL(registrationClicked()));
}

MainPage::~MainPage()
{
    delete ui;
}
