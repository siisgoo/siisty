#include "Pages/Users/UsersList.hpp"
#include "ui_UsersList.h"

#include <QAction>
#include <qnamespace.h>

UsersList::UsersList(const QMap<Database::RoleId, Database::Driver::role_set>& roles, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::UsersList),
        _usersWaiter(new Database::DriverAssistant),
        _userWaiter(new Database::DriverAssistant),
        _roles(roles)
{
    ui->setupUi(this);

    connect(_usersWaiter, SIGNAL(success(QJsonObject)), this, SLOT(on_usersLoaded(QJsonObject)));
    connect(_usersWaiter, SIGNAL(failed(Database::CmdError)), this, SLOT(on_usersLoadError(Database::CmdError)));

    connect(_userWaiter, SIGNAL(success(QJsonObject)), this, SLOT(on_userLoaded(QJsonObject)));
    connect(_userWaiter, SIGNAL(failed(Database::CmdError)), this, SLOT(on_userLoadError(Database::CmdError)));

    connect(ui->update_users_Btn, SIGNAL(clicked()), this, SLOT(requestUsers()));
    connect(ui->users_table, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(on_userClicked(QTableWidgetItem*)));

    QTimer::singleShot(1000, [this]() {requestUsers();});

    // TODO add sorting actions and enabling disabling columns
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
    Q_EMIT requestedUsers({Database::ROLE_AUTO,
                          QJsonObject{
                            { "command", Database::CMD_GET_USER_INFO },
                            { "arg",
                                QJsonObject{
                                    { "id", "*" }
                                }
                            }
                          },
                          _usersWaiter});
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
    clearTable();
    QJsonArray users = obj.take("users").toArray();

    int row = 0;
    for (const auto& user : users) {
        QJsonObject cur = user.toObject();
        ui->users_table->insertRow(row);
/* ->setData(0, cur["id"].toInt() */

        QTableWidgetItem * id_i = new QTableWidgetItem(QString::number(cur["id"].toInt())),
                         * name_i = new QTableWidgetItem(cur["name"].toString()),
                         * role_i = new QTableWidgetItem(_roles[(Database::RoleId)cur["role"].toInteger()].name);
        ui->users_table->setItem(row, ID,   id_i);
        ui->users_table->setItem(row, NAME, name_i);
        ui->users_table->setItem(row, ROLE, role_i);

        /* ui->users_table->itemAt(row, ROLE)->setData(Qt::DisplayRole, _roles[cur["role"].toInteger()].id); // first is AUTO => skip */
        row++;
    }
}

void UsersList::on_usersLoadError(Database::CmdError e) { Q_EMIT logMessage(e.String(), Error); }

void
UsersList::on_userClicked(QTableWidgetItem * itm)
{
    int id = this->ui->users_table->indexAt(QPoint(0, itm->row())).data().toInt();
    Q_EMIT requestedUsers({Database::ROLE_AUTO,
                          QJsonObject{
                            { "command", Database::CMD_GET_USER_INFO },
                            { "arg",
                                QJsonObject{
                                    { "id", id },
                                    { "takeImage", true }
                                }
                            }
                          },
                          _userWaiter});
}

                /* { "id", q.record().value("id").toInt() }, */
                /* { "name", q.record().value("name").toString() }, */
                /* { "role", q.record().value("role_id").toInt() }, */
                /* { "email", q.record().value("email").toString() }, */
                /* { "login", q.record().value("login").toString() }, */
                /* { "entryDate", q.record().value("entryDate").toInt() }, */
                /* { "wapon", q.record().value("wapon_id").toInt() }, */
                /* { "image", (takeImage ? extractImg(q.record().value("image")) : "") } // remove to another? use a model? */
void
UsersList::on_userLoaded(QJsonObject obj)
{
    this->ui->name->setText(obj["name"].toString());
    this->ui->role->setText(this->_roles[(Database::RoleId)obj["role"].toInt()].name);
    this->ui->entrydate->setDateTime(QDateTime::fromSecsSinceEpoch(obj["entryDate"].toInt()));
    this->ui->login->setText(obj["login"].toString());
    this->ui->password->setText("encrypted");
    this->ui->avatar->setPixmap(
            QPixmapFromQString(obj["image"].toString())
            .scaled(218, 218, Qt::AspectRatioMode::KeepAspectRatio,
                Qt::FastTransformation));
}

void
UsersList::on_userLoadError(Database::CmdError)
{

}
