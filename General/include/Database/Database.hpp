#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

#include <QProgressBar>
#include <QLabel>
#include <QtSql>
#include <QString>
#include <QJsonObject>
#include <QQueue>

#include "Database/Role.hpp"
#include "Database/command.hpp"
#include "General/logger.hpp"

namespace Database {

class SQLite : public QObject {
    Q_OBJECT

    public:
        SQLite(const QString& path, QObject * p = nullptr);
        virtual ~SQLite();

        using DatabaseCmd = QPair<RoleId, QJsonObject&>;

    Q_SIGNALS:
        void Inited();
        void InitizlizationFailed(QSqlError);

        void addCommand(Database::RoleId role, QJsonObject&);

        void failed(Database::CmdError);
        void success(QJsonObject&);
        void logMessage(QString, int = LoggingLevel::Trace);

        void setProgress(int, int);

    public Q_SLOTS:
        void Run();
        void Stop();

    private Q_SLOTS:
        void worker();
            // worker ¯\_(ツ)_/¯

        void cmdLogMessage(Database::CmdError);
            // transform for simple logMessage

        void executeCommand(Database::RoleId role, QJsonObject& o);
            // all permission controll system BASED on this small role variable

    private:
        void Initialize();
        void checkTables();
        void insertDefaultsRoles();
        void insertDefaultsObjectTypes();

        QQueue<DatabaseCmd> _cmdQueue;

        bool _running;

        QString _path;
        QSqlDatabase * _db;
};

} /* Database */

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
