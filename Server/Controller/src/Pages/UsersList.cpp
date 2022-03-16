#include "Pages/Users/UsersList.hpp"
#include "ui_UsersList.h"

#include <QAction>

UsersList::UsersList(const QVector<Database::SQLite::role_set>& roles, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::UsersList),
        _usersWaiter(new Database::SQLiteWaiter),
        _roles(roles)
{
    ui->setupUi(this);

    connect(_usersWaiter, SIGNAL(success(QJsonObject)), this, SLOT(on_usersLoaded(QJsonObject)));
    connect(_usersWaiter, SIGNAL(failed(Database::CmdError)), this, SLOT(on_usersLoadError(Database::CmdError)));

    connect(ui->update_users_Btn, SIGNAL(clicked()), this, SLOT(requestUsers()));
    connect(ui->users_table, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(on_userClicked(QTableWidgetItem*)));

    requestUsers();

    /* ui->users_table->addActions({ */
    /*     new QAction("bla"), */
    /* }); */
}

UsersList::~UsersList()
{
    clearTable();
    delete _usersWaiter;
    delete ui;
}

void
UsersList::requestUsers()
{
    Q_EMIT requestedUsers(Database::RoleId::AUTO,
                          QJsonObject{
                            { "command", (int)Database::CommandId::GET_EMPLOYEE_ENTRY },
                            { "arg",
                                QJsonObject{
                                    { "employee", "*" }
                                }
                            }
                          },
                          _usersWaiter);
}

void
UsersList::clearTable()
{
    for (int row = ui->users_table->rowCount(); row >= 0; row--) {
        for (int i = 0; i < COLUMNS; i++) {
            delete ui->users_table->takeItem(row, i);
            ui->users_table->removeRow(row);
        }
    }
}

void
UsersList::on_usersLoaded(QJsonObject obj)
{
    QJsonArray users = obj.take("employees").toArray();

    int row = 0;
    for (const auto& user : users) {
        QJsonObject cur = user.toObject();
        ui->users_table->insertRow(row);

        ui->users_table->setItem(row, ID,   new QTableWidgetItem(QString::number(cur["id"].toInteger())));
        ui->users_table->setItem(row, NAME, new QTableWidgetItem(cur["name"].toString()));
        ui->users_table->setItem(row, ROLE, new QTableWidgetItem(_roles[cur["role"].toInteger()].name));
    }
}

void UsersList::on_usersLoadError(Database::CmdError e) { Q_EMIT logMessage(e.String(), Error); }

void
UsersList::on_userClicked(QTableWidgetItem * itm)
{
}
