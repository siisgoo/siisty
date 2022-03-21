#include "Database/Database.hpp"
#include "Database/command.hpp"
#include "Database/tables.hpp"
#include "Database/ObjectType.hpp"
#include "Database/Role.hpp"
#include "Database/Utility.hpp"

#include <QMutexLocker>
#include <functional>
#include <QDebug>

namespace Database {

DriverAssistant::DriverAssistant(QObject * p)
    : QObject(p)
{ }
DriverAssistant::~DriverAssistant() { }
void DriverAssistant::Success(QJsonObject o) { Q_EMIT success(o); }
void DriverAssistant::Failed(Database::CmdError err) { Q_EMIT failed(err); }

Driver::Driver(const QString& path, QObject * p)
    : QObject(p),
        _path(path),
        _pf(new NotifyProgressItemFactory)
{
    #define XX(num, name, query) { Tables:: name, QUOTE(name), query },
    _tables = { TABLES_MAP(XX) };
    #undef XX
    #define XX(id, val, comm, mult, period) { RoleId:: val, QUOTE(val), comm, mult, period },
    _roles = { ROLE_MAP(XX) };
    #undef XX
    #define XX(id, n, exe) { CommandId:: n, QUOTE(n), exe },
    _commands = { COMMANDS_MAP(XX) };
    #undef XX
    #define XX(id, name, price) { ObjectType:: name, QUOTE(name), price },
    _objectTypes = { OBJECT_TYPE_MAP(XX) };
    #undef XX

    _pf->setExitOnCompleted(true);
}

Driver::~Driver()
{
    delete _pf;
    if (_db && _db->isOpen()) {
        _db->close();
        delete _db;
    }
}

//TODO add check if inited
void
Driver::Initialize()
{
    _pf->setTitle("Database initialization");
    _pf->setMaximum(4);
    Q_EMIT createNotifyItem(_pf, _p_uid_main);

    _db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    _db->setDatabaseName(_path);
    if (!_db->open())
        throw _db->lastError();

    Q_EMIT setNotifyItemPropery(_p_uid_main, "progress", 1);
    checkTables();
    Q_EMIT setNotifyItemPropery(_p_uid_main, "progress", 2);
    insertDefaultsRoles();
    Q_EMIT setNotifyItemPropery(_p_uid_main, "progress", 3);
    insertDefaultsObjectTypes();
    Q_EMIT setNotifyItemPropery(_p_uid_main, "progress", 4);

    Q_EMIT Inited();
}

void
Driver::checkTables()
{
    _pf->setTitle("Looking for tables");
    _pf->setMaximum((int)Tables::TablesCount);
    Q_EMIT createNotifyItem(_pf, _p_uid);
    int i;
    QStringList tables = _db->tables();
    for (i = 0; i < (int)Tables::TablesCount; i++) {
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
        Q_EMIT setNotifyItemPropery(_p_uid, "progress", i+1);
    }
}

// TODO add AUTO command
void
Driver::insertDefaultsRoles()
{
    _pf->setTitle("Looking for roles");
    _pf->setMaximum((int)RoleId::ROLES_COUNT);
    Q_EMIT createNotifyItem(_pf, _p_uid);

    QSqlQuery q;
    bool deleted = false;
    for (int i = 0; i < (int)RoleId::ROLES_COUNT; i++) {
        if (_roles[i].id == RoleId::AUTO) {
            continue;
        }
        auto role = _roles[i];
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

        q.prepare("SELECT * FROM RoleCommands WHERE role_id = :role_commands_id");
        q.bindValue(":role_commands_id", (int)role.id);
        if (!q.exec()) {
            throw q.lastError();
        }

        // may be deeper check? :) no
        if (!q.next()) {
            int inner_bar_uid = FloatNotifier::freeUID();
            _pf->setTitle("Looking " + QString(role.name) + " role");
            _pf->setMaximum(role.commands.length());
            Q_EMIT createNotifyItem(_pf, _p_uid_sub);
            for (int j = 0; j < role.commands.length(); j++) {
                auto command = role.commands[j];
                q.prepare("INSERT INTO RoleCommands (role_id, command_id) "
                          "VALUES (:role_id, :command_id)");
                q.bindValue(":role_id", (int)role.id);
                q.bindValue(":command_id", (int)command);
                if (!q.exec()) {
                    throw q.lastError();
                }
                Q_EMIT setNotifyItemPropery(_p_uid_sub, "progress", j+1);
            }
        }
        Q_EMIT setNotifyItemPropery(_p_uid, "progress", i+1);
    }
}

void
Driver::insertDefaultsObjectTypes()
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

        int bar_uid = FloatNotifier::freeUID();
        _pf->setTitle("Looking for default object types");
        _pf->setMaximum((int)ObjectType::COUNT);
        Q_EMIT createNotifyItem(_pf, _p_uid);
        obj["command"] = (int)CommandId::ADD_OBJECT_TYPE;
        for (int i = 0; i < (int)ObjectType::COUNT; i++) {
            obj["arg"] = QJsonObject({
                    { "name", _objectTypes[i].name },
                    { "price", _objectTypes[i].price }
            });
            if (!autoExecCommand(obj)) {
                throw _db->lastError();
            }
            Q_EMIT setNotifyItemPropery(_p_uid, "progress", i+1);
        }
    }
}

void
Driver::Run()
{
    try {
        this->Initialize();
    } catch (QSqlError e) {
        // TODO add forse end process
        Q_EMIT InitizlizationFailed(e);
    }

    _running=true;
    this->worker();
}

void
Driver::Stop()
{
    _running = false;
}

void
Driver::worker()
{
    QMutexLocker lock(&_queueMtx);
    if (_cmdQueue.length()) {
        DatabaseCmd cmd = _cmdQueue.dequeue();
        this->executeCommand((RoleId)cmd.executorRole, cmd.data, cmd.waiter);
    }

    if (_running) {
        QTimer::singleShot(100, this, SLOT(worker()));
    }
}

const QVector<Driver::role_set>& Driver::avalibleRoles() const { return _roles; }

void Driver::addCommand(Database::RoleId r, QJsonObject o, Database::DriverAssistant* a) { addCommand({(int)r, o, a}); }
void Driver::addCommand(Database::DatabaseCmd cmd) {
    QMutexLocker lock(&_queueMtx);
    _cmdQueue.append(cmd);
}

void
Driver::executeCommand(Database::RoleId role, QJsonObject obj, DriverAssistant* waiter) {
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
        auto cmd = _commands[command_n];
        CmdError rc = cmd.executor(target);
        if (rc.Ok()) {
            waiter->Success(target);
        } else {
            waiter->Failed(rc);
        }
    } else {
        waiter->Failed(CmdError(InvalidParam, "No parameters passed"));
        return;
    }
    qDebug() << "Cmd exec time: " << timer.elapsed() << "\t" << timer.nsecsElapsed();
}

bool
Driver::autoExecCommand(QJsonObject cmd)
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
