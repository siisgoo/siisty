#ifndef USERSLIST_H
#define USERSLIST_H

#include <QWidget>
#include <QTableWidgetItem>
#include "Database/Database.hpp"
#include "General/logger.hpp"

namespace Ui {
  class UsersList;
}

class UsersList : public QWidget {
    Q_OBJECT

    private:
        enum Columns {
            ID = 0,
            NAME,
            ROLE,
            COLUMNS
        };

    public:
     explicit UsersList(const QVector<Database::SQLite::role_set>& roles,
                        QWidget *parent = nullptr);
     ~UsersList();

    Q_SIGNALS:
        void requestedUsers(Database::RoleId, QJsonObject, Database::SQLiteWaiter*);

        void logMessage(QString, int = LoggingLevel::Trace);

    public Q_SLOTS:

    private Q_SLOTS:
        void requestUsers();

        void clearTable();

        void on_usersLoaded(QJsonObject);
        void on_usersLoadError(Database::CmdError);

        void on_userClicked(QTableWidgetItem*);

    private:
        Database::SQLiteWaiter * _usersWaiter;

        const QVector<Database::SQLite::role_set>& _roles;

        Ui::UsersList *ui;
};

#endif // USERSLIST_H
