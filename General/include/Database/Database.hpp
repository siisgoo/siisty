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

        QString errorToString(CommandErrno);

    Q_SIGNALS:
        void failed(CommandErrno);
        void success(QJsonObject&);
        void logMessage(QString&, int = LoggingLevel::Trace);

    public Q_SLOTS:
     void executeCommand(const QString& login, const QString& password,
                         const QJsonDocument& d);
        // authorize and execute

    private:
        QSqlDatabase _db;
};

} /* Database */

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
