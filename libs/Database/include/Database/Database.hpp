#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

#include <QtSql>
#include <QString>
#include <QJsonObject>
#include <QQueue>

#include "Database/tables.hpp"
#include "Database/Role.hpp"
#include "Database/command.hpp"
#include "Database/CmdError.hpp"

#include "Logger/logger.hpp"
#include "Widgets/Notifier/NotifyProgressItemFactory.hpp"

namespace Database {

class DriverAssistant : public QObject {
    Q_OBJECT

    public:
        DriverAssistant(QObject *p = nullptr);
        /* DriverAssistant(bool deleteOnSuccess = false, QObject *p = nullptr); */
        virtual ~DriverAssistant();

    public Q_SLOTS:
        // Driver use it interface to emit this->success()/failed() chain
        void Success(QJsonObject obj);
        void Failed(Database::CmdError);

    Q_SIGNALS:
        void success(QJsonObject obj);
        void failed(Database::CmdError);

    private:
        /* bool _delete_on_success; */
};

struct DatabaseCmd {
    int executorRole;
    QJsonObject data;
    DriverAssistant * waiter;
};

// own thread-oriented sqlite driver
class Driver : public QObject {
    Q_OBJECT

    public:
        struct table_def {
            int id;
            const char * name;
            const char * createQuery;
        };

        struct role_set {
            int id; // equal to index
            const char * name;
            QVector<CommandId> commands;
        };

        struct command_set {
            int id; // equal to index
            const char * name;
            command_exec_t executor;
            bool sendback;
        };

    public:
        Driver(const QString& path, QObject * p = nullptr);
        virtual ~Driver();

        const QMap<RoleId, role_set>& avalibleRoles() const;

    Q_SIGNALS:
        void Inited();
        void InitizlizationFailed(QSqlError);

        void logMessage(QString, int = LoggingLevel::Trace);

        void setNotifyItemPropery(int, const QByteArray &, const QVariant &);
        void createNotifyItem(NotifyItemFactory *, int& uid);

    public Q_SLOTS:
        void Run();
        void Stop();

    private Q_SLOTS:
        void worker();
            // worker ¯\_(ツ)_/¯

        void addCommand(Database::DatabaseCmd);

        void executeCommand(Database::RoleId role, QJsonObject o, DriverAssistant*);
            // all permission controll system BASED on this small role variable
        bool autoExecCommand(QJsonObject o);
            // no callable outside, only for serve
            // return true/false on success/failed
            // TODO change return val to CmdError

    private:
        void Initialize();
        void checkTables();
        void insertDefaultsRoles();

        QMap<RoleId, role_set> _roles;
        QVector<table_def>     _tables;
        QVector<command_set>   _commands;

        QMutex _queueMtx;
        QQueue<DatabaseCmd> _cmdQueue;

        NotifyProgressItemFactory * _pf;
        int _p_uid;
        int _p_uid_main;
        int _p_uid_sub;

        bool _running;
        QString _path;
        QSqlDatabase * _db;
};


} /* Database */

Q_DECLARE_METATYPE(Database::DatabaseCmd)

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
