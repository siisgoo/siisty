#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QCompleter>
#include <QWidget>
#include <QFileDialog>
#include "Database/Database.hpp"

namespace Ui {
  class RegisterUser;
}

class RegisterUser : public QWidget {
    Q_OBJECT

    public:
     explicit RegisterUser(const QVector<Database::SQLite::role_set> &,
                           QWidget *parent = nullptr);
     virtual ~RegisterUser();

    Q_SIGNALS:
        void registrateUser(Database::RoleId, QJsonObject, Database::SQLiteWaiter*);
        void requestedWaponDetails(Database::RoleId, QJsonObject, Database::SQLiteWaiter*);
        void requestedUserDetails(Database::RoleId, QJsonObject, Database::SQLiteWaiter*);

        void imgFileNotValid();
        void imgFileValid();

        void logMessage(QString, int = LoggingLevel::Trace);

    public Q_SLOTS:
        void on_dbWaponsChanged();
            // listen

    private Q_SLOTS:
        void on_waponsFetched(QJsonObject wapons);
        void on_waponsFetchFailed(Database::CmdError);

        void requestWaponDetails();

        void on_register_buttons_accepted();
        void on_register_buttons_rejected();

        void on_saveSuccess(QJsonObject);
        void on_saveFailed(Database::CmdError);

        void openImgFileChooer();

        void on_imgFilePathValid();
        void on_imgFilePathNotValid();

        void validateImgFilePath(QString file);

    private:
        Database::SQLiteWaiter * _dbRWaiter;
            // register waiter
        Database::SQLiteWaiter * _dbWWaiter;
            // wapons details waiter

        QCompleter * _filePathCompleter;
        QFileDialog * _fileChooser;
        Ui::RegisterUser *ui;
};

#endif // REGISTERUSER_H
