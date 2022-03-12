#include "Database/Database.hpp"
#include "Database/command.hpp"
#include "Database/tables.hpp"
#include "Database/ObjectType.hpp"
#include "Database/Role.hpp"
#include "Database/Utility.hpp"

#include <functional>

namespace Database {

#define XX(num, name, query) { Tables:: name, QUOTE(name), query },
    static struct tables_def {
        Tables number;
        const char * name;
        const char * createQuery;
    } const tablesDefenitions[] = {
        TABLES_MAP(XX)
    };
#undef XX

#define XX(id, val, comm, mult, period) { RoleId:: val, QUOTE(val), comm, mult, period },
    static struct role_set {
        RoleId id;
        const char * name;
        QVector<CommandId> commands;
        float payMult;
        int payPeriod;
    } Accessability[] {
        ROLE_MAP(XX)
    };
#undef XX

#define XX(id, n, exe, sandback) { CommandId:: n, QUOTE(n), exe, sandback },
    static struct command_set {
        CommandId id;
        const char * name;
        command_exec_t executor;
        bool sendback;
    } const Commands[] {
        COMMANDS_MAP(XX)
    };
#undef XX

#define XX(id, name, desc) { CommandErrno:: name, QUOTE(name), QUOTE(desc) },
    static struct CommandErrorDesc_t {
        CommandErrno id;
        const char * name;
        const char * desc;
    } const CommandErrorDesc[] {
        COMMANDS_ERRNO_MAP(XX)
    };
#undef XX

SQLite::SQLite(const QString& path, QObject * p)
    : QObject(p),
        _db(QSqlDatabase::addDatabase("QSQLITE"))
{
    _db.setDatabaseName(path);

    if (!_db.open())
        throw _db.lastError();

    int i;
    QStringList tables = _db.tables();
    for (i = 0; i < (int)Tables::TablesCount
            && tables.contains(tablesDefenitions[i].name); i++)
        ;

    if (i == (int)Tables::TablesCount) {
        throw QSqlError();
    }

    QSqlQuery q;
    for (i = 0; i < (int)Tables::TablesCount; i++) {
        if (!q.exec(tablesDefenitions[i].createQuery)) {
            throw q.lastError();
        }
    }

    //create defults
}

SQLite::~SQLite()
{
    if (_db.isOpen()) {
        _db.close();
    }
}

void
SQLite::executeCommand(const QString& login, const QString& password,
                       const QJsonDocument& d) {
    // authorize
    QSqlQuery q;
    q.prepare("SELECT role_id FROM EmployeesAndCustomers WHERE login=:login AND password=:password");
    q.bindValue(":login", login);
    q.bindValue(":password", password);
    if (!q.exec()) {
        Q_EMIT failed(CommandErrno::AccessDenied);
        return;
    }

    int role;
    if (auto r = q.result(); r) {
        role = r->handle().toInt();
    } else {
        Q_EMIT failed(CommandErrno::AccessDenied);
        return;
    }

    if (role > (int)RoleId::ROLES_COUNT || role < 0) {
        Q_EMIT failed(CommandErrno::AccessDenied);
        return;
    }

    // try execute
    if (!d.isObject()) {
        Q_EMIT failed(CommandErrno::InvalidCommand);
        return;
    }

    int command_n;
    QJsonObject obj = d.object();

    if (auto val = obj["command"]; val.isDouble()) {
        command_n = val.toInt();
    } else {
        Q_EMIT failed(CommandErrno::InvalidCommand);
        return;
    }

    if (command_n > (int)CommandId::COMMANDS_COUNT || command_n < 0) {
        Q_EMIT failed(CommandErrno::InvalidCommand);
        return;
    }

    // check permission for execute command
    auto it = std::find(Accessability[role].commands.begin(), Accessability[role].commands.end(),
            static_cast<CommandId>(command_n));

    if (it == Accessability[role].commands.end()) {
        Q_EMIT failed(CommandErrno::AccessDenied);
        return;
    }

    if (auto val = obj["arg"]; val.isObject()) {
        QJsonObject target = val.toObject();
        int rc = Commands[command_n].executor(target);
        if (rc == (int)CommandErrno::OK) {
            Q_EMIT success(target);
        } else {
            Q_EMIT failed((CommandErrno)rc);
        }
    } else {
        Q_EMIT failed(CommandErrno::InvalidParam);
        return;
    }
}

QString
SQLite::errorToString(CommandErrno n)
{
    return CommandErrorDesc[static_cast<int>(n)].desc;
}

} /* Database  */ 
