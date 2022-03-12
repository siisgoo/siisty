#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

#include <QtSql>
#include <QString>
#include <QJsonObject>

#include "Database/command.hpp"
#include "General/logger.hpp"

namespace Database {

class SQLite : public QObject {
    Q_OBJECT

    public:
        SQLite(const QString& path, QObject * p = nullptr);
        virtual ~SQLite();

    Q_SIGNALS:
        void failed(Database::CmdError);
        void success(QJsonObject&);
        void logMessage(QString, int = LoggingLevel::Trace);

    public Q_SLOTS:
        void executeCommand(const QString& login, const QString& password,
                            const QJsonDocument& d);
        void executeCommand(const QString& login, const QString& password,
                            const QJsonObject& o);

        void autoCommand(const QJsonDocument& d); // for AUTO role(all permissions)
        void autoCommand(const QJsonObject& o);

    private:
        void checkTables();
        void insertDefaultsRoles();
        void insertDefaultsObjectTypes();

        QSqlDatabase _db;
};

} /* Database */

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
