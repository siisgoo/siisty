#include "Database/Database.hpp"
#include "Database/command.hpp"
#include "Database/tables.hpp"
#include "Database/ObjectType.hpp"
#include "Database/Role.hpp"
#include "Database/Utility.hpp"

#include <functional>
#include <QDebug>

namespace Database {

SQLiteWaiter::SQLiteWaiter(QObject * p)
    : QObject(p)
{ }
SQLiteWaiter::~SQLiteWaiter() { }
void SQLiteWaiter::Success(QJsonObject o) { Q_EMIT success(o); }
void SQLiteWaiter::Failed(CmdError err) { Q_EMIT failed(err); }

SQLite::SQLite(const QString& path, QObject * p)
    : QObject(p),
        _path(path)
{
    #define XX(num, name, query) { Tables:: name, QUOTE(name), query },
    _tables = {
        TABLES_MAP(XX)
    };
    #undef XX

    #define XX(id, val, comm, mult, period) { RoleId:: val, QUOTE(val), comm, mult, period },
    _roles = {
        ROLE_MAP(XX)
    };
    #undef XX

    #define XX(id, n, exe) { CommandId:: n, QUOTE(n), exe },
    _commands = {
        COMMANDS_MAP(XX)
    };
    #undef XX

    #define XX(id, name, price) { ObjectType:: name, QUOTE(name), price },
    _objectTypes = {
        OBJECT_TYPE_MAP(XX)
    };
    #undef XX

}

//TODO add check if inited
void
SQLite::Initialize()
{
    Q_EMIT setProgress(0, 3);
    connect(this, SIGNAL(addCommand(Database::RoleId, QJsonObject, Database::SQLiteWaiter*)), this, SLOT(on_addCommand(Database::RoleId, QJsonObject, Database::SQLiteWaiter*)));
    connect(this, SIGNAL(addCommand(Database::SQLite::DatabaseCmd)), this, SLOT(on_addCommand(Database::SQLite::DatabaseCmd)));
    _db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    _db->setDatabaseName(_path);
    if (!_db->open())
        throw _db->lastError();

    checkTables();
    Q_EMIT setProgress(1, 3);
    insertDefaultsRoles();
    Q_EMIT setProgress(2, 3);
    insertDefaultsObjectTypes();
    Q_EMIT setProgress(3, 3);

    Q_EMIT Inited();
}

SQLite::~SQLite()
{
    if (_db && _db->isOpen()) {
        _db->close();
        delete _db;
    }
}

void
SQLite::Run()
{
    try {
        this->Initialize();
    } catch (QSqlError e) {
        Q_EMIT InitizlizationFailed(e);
    }

    _running=true;
    this->worker();
}

void
SQLite::Stop()
{
    _running = false;
}

void
SQLite::worker()
{
    if (_cmdQueue.length()) {
        DatabaseCmd cmd = _cmdQueue.dequeue();
        this->executeCommand((RoleId)cmd.executorRole, cmd.data, cmd.waiter);
    }

    if (_running) {
        QTimer::singleShot(100, this, SLOT(worker()));
    }
}

void
SQLite::checkTables()
{
    int i;
    QStringList tables = _db->tables();
    for (i = 0; i < (int)Tables::TablesCount ; i++) {
        if (!tables.contains(_tables[i].name)) {
            QJsonObject cmd{
                    {"command", (int)CommandId::CREATE_TABLE},
                    {"arg",
                        QJsonObject{ { "query", _tables[i].createQuery } }
                    }
            };
            if (!autoExecCommand(cmd)) {
                throw _db->lastError();
            }
        }
    }
}

// TODO add AUTO command
void
SQLite::insertDefaultsRoles()
{
    QSqlQuery q;
    bool deleted = false;
    for (int i = 0; i < (int)RoleId::ROLES_COUNT; i++) {
        auto role = _roles[i];
        q.clear();
        q.prepare("SELECT * FROM Roles WHERE id = :id and name = :name");
        q.bindValue(":id", (int)role.id);
        q.bindValue(":name", role.name);
        if (!q.exec()) {
            throw q.lastError();
        }
        if (!q.next()) { // insert
            if (!deleted) {
                if (!q.exec("DELETE FROM Roles")) {
                    throw q.lastError();
                }
                if (!q.exec("DELETE FROM RoleCommands")) {
                    throw q.lastError();
                }
                deleted = true;
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
                    { "name", _objectTypes[i].name },
                    { "price", _objectTypes[i].price }
            });
            if (!autoExecCommand(obj)) {
                throw _db->lastError();
            }
        }
    }
}

const QVector<SQLite::role_set>& SQLite::avalibleRoles() const { return _roles; }

void SQLite::on_addCommand(Database::RoleId r, QJsonObject o, Database::SQLiteWaiter* w) { _cmdQueue.append({(int)r, o, w}); }
void SQLite::on_addCommand(Database::SQLite::DatabaseCmd cmd) { _cmdQueue.append(cmd); }

void
SQLite::executeCommand(Database::RoleId role, QJsonObject obj, SQLiteWaiter* waiter) {
    QElapsedTimer timer;
    timer.start();
    int command_n;
    QSqlQuery q;

    if (!waiter) {
        throw "Null waiter passed!";
    }

    if (role != RoleId::AUTO) {
        if (role > RoleId::ROLES_COUNT || role < (RoleId)0) {
            waiter->Failed(CmdError(AccessDenied, "Invalid Role ID passed"));
            return;
        }
    }

    if (auto val = obj["command"]; val.isDouble()) {
        command_n = val.toInt();
    } else {
        waiter->Failed(CmdError(InvalidCommand, "No command passed"));
        return;
    }

    if (command_n > (int)CommandId::COMMANDS_COUNT || command_n < 0) {
        waiter->Failed(CmdError(InvalidCommand, "Command not exists"));
        return;
    }

    if (role != RoleId::AUTO) {
        // check permission for execute command
        auto it = std::find(_roles[(int)role].commands.begin(), _roles[(int)role].commands.end(),
                static_cast<CommandId>(command_n));

        if (it == _roles[(int)role].commands.end()) {
        waiter->Failed(CmdError(AccessDenied, "You not have access to execute this command"));
            return;
        }
    }

    if (auto val = obj["arg"]; val.isObject()) {
        QJsonObject target = val.toObject();
        if (role != RoleId::AUTO) {
            target.take("acceptJoin"); //remove
        } else {
            target["acceptJoin"] = true;
        }
        CmdError rc = _commands[command_n].executor(target);
        if (rc.Ok()) {
            waiter->Success(target);
        } else {
            waiter->Failed(rc);
        }
    } else {
        waiter->Failed(CmdError(InvalidParam, "No parameters passed"));
        return;
    }
    qDebug() << timer.elapsed() << "\t" << timer.nsecsElapsed();
}

bool
SQLite::autoExecCommand(QJsonObject cmd)
{
    int command_n = cmd["command"].toInt();

    QJsonObject target = cmd["arg"].toObject();
    CmdError rc = _commands[command_n].executor(target);
    if (rc.Ok()) {
        return true;
    } else {
        return false;
    }
}

} /* Database  */ 
