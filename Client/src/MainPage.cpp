#include "MainPage.hpp"
#include "ui_MainPage.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    QPixmap customerLP = QPixmap(":login/cusomerLogin");
    QPixmap employeeLP = QPixmap(":login/employeeLogin");
    customerLP.scaled(300, 218);
    ui->customerLogin->setIcon(QIcon(customerLP));
    ui->employeeLogin->setIcon(QIcon(employeeLP));

    connect(ui->customerLogin, SIGNAL(clicked()), this, SIGNAL(customerLoginClicked()));
    connect(ui->employeeLogin, SIGNAL(clicked()), this, SIGNAL(employeeLoginClicked()));
}

MainPage::~MainPage()
{
    delete ui;
}
