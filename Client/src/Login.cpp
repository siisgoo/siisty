#include "Pages/Login.hpp"
#include "ui_Login.h"

#include <QtSvgWidgets/QSvgWidget>
#include <qssl.h>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    { // icon stup
        ui->icon_user->setPixmap(QIcon(":login/user").pixmap(QSize(20, 20)));
        ui->icon_password->setPixmap(QIcon(":login/password").pixmap(QSize(20, 20)));

        ui->logo->setPixmap(QIcon(":logo/big-logo").pixmap(QSize(128, 128)));
    }

    connect(ui->submit, SIGNAL(clicked()), this, SLOT(on_submit_clicked()));
    connect(ui->login, SIGNAL(textChanged(QString)), this, SLOT(on_auth_changed(QString)));
    connect(ui->port, SIGNAL(textChanged(QString)), this, SLOT(on_auth_changed(QString)));
    connect(ui->host, SIGNAL(currentTextChanged(QString)), this, SLOT(on_auth_changed(QString)));
    connect(ui->password, SIGNAL(textChanged(QString)), this, SLOT(on_auth_changed(QString)));
    ui->submit->setEnabled(false);

    ui->encryptionType->addItem("Any", QSsl::AnyProtocol);
    ui->encryptionType->addItem("Disable", QSsl::UnknownProtocol);
    ui->encryptionType->addItem("TLSv1.2", QSsl::TlsV1_2);
    ui->encryptionType->addItem("TLSv1.3", QSsl::TlsV1_3);
}

Login::~Login()
{
    delete ui;
}

void
Login::on_submit_clicked()
{
    Q_EMIT tryLogin({
            QHostAddress(ui->host->currentText()),
            (quint16)ui->port->text().toUInt(),
            ui->encryptionType->currentData().toInt(),
            ui->login->text(),
            ui->password->text(),
            ui->rememberLogin->isChecked(),
            ui->rememberPassword->isChecked()});
    accept();
}

void
Login::on_auth_changed(QString)
{
    if (ui->login->text().length() > 0 &&
            ui->password->text().length() > 7 &&
            ui->port->text().length() > 0 &&
            ui->host->currentText().length()) // TODO add normal validator
    {
        ui->submit->setEnabled(true);
    } else {
        ui->submit->setEnabled(false);
    }
}
