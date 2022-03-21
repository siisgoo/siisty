#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

#include <QtSql>
#include <QString>
#include <QJsonObject>
#include <QQueue>

#include "Widgets/FloatNotifier.hpp"
#include "Database/ObjectType.hpp"
#include "Database/Role.hpp"
#include "Database/command.hpp"
#include "Database/CmdError.hpp"
#include "General/logger.hpp"

#include "Widgets/NotifyProgressItem.hpp"
#include "Widgets/NotifyProgressItemFactory.hpp"

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
            Tables id;
            const char * name;
            const char * createQuery;
        };

        struct role_set {
            RoleId id; // equal to index
            const char * name;
            QVector<CommandId> commands;
            double payMult;
            int payPeriod;
        };

        struct command_set {
            CommandId id; // equal to index
            const char * name;
            command_exec_t executor;
            bool sendback;
        };

        struct objectType_set {
            ObjectType id;
            const char * name;
            double price;
        };

    public:
        Driver(const QString& path, QObject * p = nullptr);
        virtual ~Driver();

        const QVector<role_set>& avalibleRoles() const;

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

        void addCommand(Database::Driver::DatabaseCmd);
        void addCommand(Database::RoleId, QJsonObject, Database::DriverAssistant*);

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
        void insertDefaultsObjectTypes();

        QVector<role_set>       _roles;
        QVector<table_def>      _tables;
        QVector<command_set>    _commands;
        QVector<objectType_set> _objectTypes;

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


Q_DECLARE_METATYPE(Database::Driver::DatabaseCmd)

} /* Database */

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
