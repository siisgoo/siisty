#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QWidget>
#include "Database/Database.hpp"

namespace Ui {
  class RegisterUser;
}

class RegisterUser : public QWidget {
    Q_OBJECT

    public:
     explicit RegisterUser(QWidget *parent = nullptr);
     virtual ~RegisterUser();

    void setRoles(QVector<Database::SQLite::role_set> roles);
    void setWapons(QJsonObject wapons);

    Q_SIGNALS:
        void registrateUser(Database::RoleId, QJsonObject, Database::SQLiteWaiter*);
        void requestWaponDetails();

    private Q_SLOTS:
        void on_register_buttons_accepted();
        void on_register_buttons_rejected();

        void on_saveSuccess(QJsonObject);
        void on_saveFailed(Database::CmdError);

    private:
        QJsonObject _request;

        Database::SQLiteWaiter * _dbWaiter;

        Ui::RegisterUser *ui;
};

#endif // REGISTERUSER_H
