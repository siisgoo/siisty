#include "Database/Database.hpp"
#include "Database/command.hpp"
#include "Database/tables.hpp"
#include "Database/ObjectType.hpp"
#include "Database/Role.hpp"
#include "Database/Utility.hpp"

#include <functional>
#include <QDebug>

// login pass query
    /* q.prepare("SELECT role_id FROM EmployeesAndCustomers WHERE login=:login AND password=:password"); */
    /* q.bindValue(":login", login); */
    /* q.bindValue(":password", password); */

    /* if (!q.exec()) { */
    /*     Q_EMIT failed(CmdError(CmdError::SQLError, q.lastError().text())); */
    /*     return; */
    /* } */

    /* if (!q.next()) { */
    /*     Q_EMIT failed(CmdError(CmdError::AccessDenied, "Invalid loggin or password")); */
    /*     return; */
    /* } */

    /* if (auto v = q.result()->handle(); v.isValid()) { */
    /*     role = v.toInt(); */
    /* } else { */
    /*     Q_EMIT failed(CmdError(CmdError::AccessDenied, "Cannot find Role assigned to user")); */
    /*     return; */
    /* } */

namespace Database {

#define XX(num, name, query) { Tables:: name, QUOTE(name), query },
    static struct tables_def {
        Tables id; // equal to index
        const char * name;
        const char * createQuery;
    } const tablesDefenitions[] = {
        TABLES_MAP(XX)
    };
#undef XX

#define XX(id, val, comm, mult, period) { RoleId:: val, QUOTE(val), comm, mult, period },
    static struct role_set {
        RoleId id; // equal to index
        const char * name;
        QVector<CommandId> commands;
        double payMult;
        int payPeriod;
    } Accessability[] {
        ROLE_MAP(XX)
    };
#undef XX

#define XX(id, n, exe, sandback) { CommandId:: n, QUOTE(n), exe, sandback },
    static struct command_set {
        CommandId id; // equal to index
        const char * name;
        command_exec_t executor;
        bool sendback;
    } const Commands[] {
        COMMANDS_MAP(XX)
    };
#undef XX

#define XX(id, name, price) { ObjectType:: name, QUOTE(name), price },
    static struct objectType_set {
        ObjectType id;
        const char * name;
        double price;
    } const ObjectTypes[] {
        OBJECT_TYPE_MAP(XX)
    };
#undef XX

SQLite::SQLite(const QString& path, QObject * p)
    : QObject(p),
        _db(QSqlDatabase::addDatabase("QSQLITE"))
{
    _db.setDatabaseName(path);
    if (!_db.open())
        throw _db.lastError();

    insertDefaultsRoles();
    insertDefaultsObjectTypes();
}

SQLite::~SQLite()
{
    if (_db.isOpen()) {
        _db.close();
    }
}

void
SQLite::checkTables()
{
    int i;
    QSqlQuery q;
    QStringList tables = _db.tables();
    for (i = 0; i < (int)Tables::TablesCount ; i++) {
        if (!tables.contains(tablesDefenitions[i].name)) {
            if (!q.exec(tablesDefenitions[i].createQuery)) {
                throw q.lastError();
            }
        }
    }
}

// TODO add AUTO command
void
SQLite::insertDefaultsRoles()
{
    QSqlQuery q;
    for (int i = 0; i < (int)RoleId::ROLES_COUNT; i++) {
        auto role = Accessability[i];
        q.clear();
        q.prepare("SELECT * FROM Roles WHERE id = :id and name = :name");
        q.bindValue(":id", (int)role.id);
        q.bindValue(":name", role.name);
        if (!q.exec()) {
            throw q.lastError();
        }
        if (!q.next()) { // insert
            if (!q.exec("DELETE FROM Roles")) {
                throw q.lastError();
            }
            if (!q.exec("DELETE FROM RoleCommands")) {
                throw q.lastError();
            }

            q.clear();
            q.prepare("INSERT INTO Roles (id, name, commands_id, payMultipler, payPeriod) "
                   "VALUES (:id, :name, :commands_id, :payMultipler, :payPeriod)");
            q.bindValue(":id", (int)role.id);
            q.bindValue(":name", role.name);
            q.bindValue(":commands_id", (int)role.id);
            q.bindValue(":payMultipler", role.payMult);
            q.bindValue(":payPeriod", role.payPeriod);
            if (!q.exec()) {
                throw q.lastError();
            }
        }

        q.clear();
        q.prepare("SELECT * FROM RoleCommands WHERE role_id = :role_commands_id");
        q.bindValue(":role_commands_id", (int)role.id);
        if (!q.exec()) {
            throw q.lastError();
        }

        // may be deeper check? :) no
        if (!q.next()) {
            for (int j = 0; j < role.commands.size(); j++) {
                auto command = role.commands[j];
                q.clear();
                q.prepare("INSERT INTO RoleCommands (role_id, command_id) "
                          "VALUES (:role_id, :command_id)");
                q.bindValue(":role_id", (int)role.id);
                q.bindValue(":command_id", (int)command);
                if (!q.exec()) {
                    throw q.lastError();
                }
            }
        }
    }
}

void
SQLite::insertDefaultsObjectTypes()
{
    QSqlQuery q;
    QJsonObject obj;

    // very common check, lol)
    if (!q.exec("SELECT id FROM objectType WHERE id = 0")) {
        throw q.lastError();
    }

    if (!q.next()) {
        if (!q.exec("DELETE FROM objectType")) {
            throw q.lastError();
        }

        obj["command"] = (int)CommandId::ADD_OBJECT_TYPE;
        for (int i = 0; i < (int)ObjectType::COUNT; i++) {
            obj["arg"] = QJsonObject({
                    { "name", ObjectTypes[i].name },
                    { "price", ObjectTypes[i].price }
            });
            this->autoCommand(obj);
        }
    }
}

void
SQLite::executeCommand(RoleId role, const QJsonObject& obj) {
    int command_n;
    QSqlQuery q;

    if (role != RoleId::AUTO) {
        if (role > RoleId::ROLES_COUNT || role < (RoleId)0) {
            Q_EMIT failed(CmdError(CmdError::AccessDenied, "Invalid Role ID passed"));
            return;
        }
    }

    if (auto val = obj["command"]; val.isDouble()) {
        command_n = val.toInt();
    } else {
        Q_EMIT failed(CmdError(CmdError::InvalidCommand, "No command passed"));
        return;
    }

    if (command_n > (int)CommandId::COMMANDS_COUNT || command_n < 0) {
        Q_EMIT failed(CmdError(CmdError::InvalidCommand, "Command not exists"));
        return;
    }

    if (role != RoleId::AUTO) {
        // check permission for execute command
        auto it = std::find(Accessability[(int)role].commands.begin(), Accessability[(int)role].commands.end(),
                static_cast<CommandId>(command_n));

        if (it == Accessability[(int)role].commands.end()) {
        Q_EMIT failed(CmdError(CmdError::AccessDenied, "You not have access to execute this command"));
            return;
        }
    }

    if (auto val = obj["arg"]; val.isObject()) {
        QJsonObject target = val.toObject();
        CmdError rc = Commands[command_n].executor(target);
        if (rc.Ok()) {
            Q_EMIT success(target);
        } else {
            Q_EMIT failed(rc);
        }
    } else {
        Q_EMIT failed(CmdError(CmdError::InvalidParam, "No parameters passed"));
        return;
    }
}

void
SQLite::executeCommand(RoleId role, const QJsonDocument& doc)
{
    if (!doc.isObject()) {
        Q_EMIT failed(CmdError(CmdError::InvalidCommand, "Request is empty"));
        return;
    }
    QJsonObject obj = doc.object();
    this->executeCommand(role, obj);
}

void
SQLite::autoCommand(const QJsonDocument& doc)
{
    this->executeCommand(RoleId::AUTO, doc);
}

void
SQLite::autoCommand(const QJsonObject& obj) {
    this->executeCommand(RoleId::AUTO, obj);
}

} /* Database  */ 
