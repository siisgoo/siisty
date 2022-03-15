#include "Pages/Users/RegisterUser.hpp"
#include "ui_RegisterUser.h"

#include "Database/Database.hpp"

RegisterUser::RegisterUser(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::RegisterUser),
      _dbWaiter(new Database::SQLiteWaiter())
{
    ui->setupUi(this);

    connect(_dbWaiter, SIGNAL(success(QJsonObject)), this, SLOT(on_saveSuccess(QJsonObject)));
    connect(_dbWaiter, SIGNAL(failed(Database::CmdError)), this, SLOT(on_saveFailed(Database::CmdError)));

    Q_EMIT requestWaponDetails();
}

RegisterUser::~RegisterUser()
{
    delete _dbWaiter;
    delete ui;
}

void
RegisterUser::setWapons(QJsonObject obj)
{
    ui->wapon_cb->clear();
    auto wapons = obj.take("wapons").toArray();

    for ()
}

void
RegisterUser::setRoles(QVector<Database::SQLite::role_set> roles)
{
    for (auto role : roles) {
        if ((int)role.id > 0)
            ui->role_cb->addItem(role.name, (int)role.id);
    }
}

void
RegisterUser::on_saveFailed(Database::CmdError err)
{
    qDebug() << "Failed!!!" << err.String();
}

void
RegisterUser::on_saveSuccess(QJsonObject obj)
{
    qDebug() << "Success!!" << obj;
    this->on_register_buttons_rejected();
        //clear
}

void
RegisterUser::on_register_buttons_accepted()
{
    QJsonObject data = QJsonObject{
        { "command", (int)Database::CommandId::REGISTER_EMPLOYEE },
        { "arg",
            QJsonObject{
                { "login", ui->login_edit->text() },
                { "password", ui->password_edit->text() },
                { "name", ui->password_edit->text() },
                { "entryDate", ui->entryDate_edit->timeSpec() },
                { "wapon", ui->wapon_cb->currentText().toInt() },
                { "role", ui->role_cb->currentData().toInt() },
                { "email", ui->email_edit->text() },
                { "image", "" } // TODO
            }
        }
    };

    Q_EMIT registrateUser(Database::RoleId::AUTO, data, _dbWaiter);
}


void
RegisterUser::on_register_buttons_rejected()
{
    ui->email_edit->clear();
    ui->login_edit->clear();
    ui->entryDate_edit->clear();
    ui->password_edit->clear();
    ui->image_path_edit->clear();
}
