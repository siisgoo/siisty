#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

#include <QProgressBar>
#include <QLabel>
#include <QtSql>
#include <QString>
#include <QJsonObject>

#include "Database/Role.hpp"
#include "Database/command.hpp"
#include "General/logger.hpp"

namespace Database {

class SQLite : public QObject {
    Q_OBJECT

    public:
        SQLite(const QString& path, QObject * p = nullptr);
        virtual ~SQLite();

    Q_SIGNALS:
        void Inited();
        void failed(Database::CmdError);
        void success(QJsonObject&);
        void logMessage(QString, int = LoggingLevel::Trace);

        void setProgress(int, int);

    public Q_SLOTS:
        void Initialize();

        void executeCommand(RoleId role, const QJsonDocument& d);
        void executeCommand(RoleId role, const QJsonObject& o);
            // all permission controll system BASED on this small role variable

        void autoCommand(const QJsonDocument& d); // for AUTO role(all permissions)
        void autoCommand(const QJsonObject& o);

    private Q_SLOTS:
        void cmdLogMessage(Database::CmdError);
            // transform for simple logMessage

    private:
        void checkAdmin();
        void checkTables();
        void insertDefaultsRoles();
        void insertDefaultsObjectTypes();

        QSqlDatabase * _db;
        QString _path;
};

} /* Database */

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
