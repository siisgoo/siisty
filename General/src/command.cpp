#include "Database/command.hpp"
#include "Database/Utility.hpp"
#include <QCryptographicHash>

#include <QLatin1String>
#include <QtSql>
#include <ctype.h>

#include <exception>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

namespace Database {

#define XX(id, name, desc) { QUOTE(name), QUOTE(desc) },
    static struct CommandErrorDesc_t {
        const char * name;
        const char * desc;
    } const CommandErrorDesc[] {
        COMMANDS_ERRNO_MAP(XX)
    };
#undef XX

CmdError::CmdError()
    : CmdError(CmdError::ErrorNo::OK, "Success")
{
}

CmdError::CmdError(CmdError::ErrorNo error_n, QString details)
    : _errno(error_n), _details(details)
{
}

bool
CmdError::Ok()
{
    return _errno == OK;
}

int
CmdError::Type()
{
    return _errno;
}

QString
CmdError::String()
{
    return QString(CommandErrorDesc[_errno].desc) + ": " + _details;
}

QString
CmdError::Name()
{
    return CommandErrorDesc[_errno].name;
}

QString
CmdError::Details()
{
    return _details;
}

/*
 * employees: Array<int>,
 * customer: int,
 * objectType: int,
 * address: string,
 * wayPoint: string,
 * experation: int,
 * start: int,
 * weekends: Array<int>,
 */
CmdError
exec_make_contract(QJsonObject& obj)
{
    QVector<int> employees;
    int customer;
    int objType;
    QString addr;
    QString wayPoint;
    QDate experation;
    QDate start;
    Weekends weekends;

    if (obj["employees"].isArray()) {
        auto employeesJson = obj["employees"].toArray();
        for (auto emp : employeesJson) {
            if (emp.isDouble()) {
                employees.push_back(obj["employees"].toInt());
            } else {
                return CmdError(CmdError::InvalidParam, "");
            }
        }
    } else {
        return CmdError(CmdError::InvalidParam, "");
    }

    if (auto val = obj["customer"]; val.isDouble()) {
        customer = val.toInt();
    } else {
        return CmdError(CmdError::InvalidParam, "");
    }

    if (auto val = obj["objectType"]; val.isDouble()) {
        objType = val.toInt();
    } else {
        return CmdError(CmdError::InvalidParam, "");
    }

    if (auto val = obj["address"]; val.isString()) {
        addr = val.toString();
    } else {
        return CmdError(CmdError::InvalidParam, "");
    }

    if (auto val = obj["address"]; val.isDouble()) {
        addr = val.toString();
    } else {
        return CmdError(CmdError::InvalidParam, "");
    }

    return CmdError();
}

/*
 * contract: int,
 */
CmdError
exec_make_duty_schedule(QJsonObject& obj)
{
    return CmdError();
}

/*
 * name: string,
 * contract: int,
 * damagePrice: double,
 * guiltyEmployees: Array<{
 *                          employee: int,
 *                          usedAmmo: int,
 *                          guiltyPercent: double
 *                        }
 */
CmdError
exec_register_accident(QJsonObject& obj)
{
    return CmdError();
}

/* TODO add check LOGIN and PASSWORD with pattern
 * login and password passed as not encrypted
 *
 * name: string,
 * entryDate: int, <- optional (default today)
 * role: int,
 * wapon: int, <- optional
 * email: string, <- optional
 * login: string,
 * password: string,
 * image: string, <- optional
 */
CmdError
exec_register_employee(QJsonObject& obj)
{
    QString name;
    qint64 entryDate;
    int role;
    int wapon = -1;
    QString email;
    QString login;
    QString password;
    QByteArray image;

    if (auto val = obj["name"]; val.isString()) {
        name = val.toString();
    } else {
        return CmdError(CmdError::InvalidParam, "No \"name\" entry");
    }
    if (auto val = obj["entryDate"]; val.isDouble()) {
        entryDate = val.toInteger();
    }
    if (auto val = obj["role"]; val.isDouble()) {
        role = val.toInt();
    } else {
        return CmdError(CmdError::InvalidParam, "No \"role\" entry");
    }
    if (auto val = obj["wapon"]; val.isDouble()) {
        wapon = val.toInt();
    }
    if (auto val = obj["email"]; val.isString()) {
        email = val.toString();
    }
    if (auto val = obj["login"]; val.isString()) {
        login = val.toString();
    } else {
        return CmdError(CmdError::InvalidParam, "No \"login\" entry");
    }
    if (auto val = obj["password"]; val.isString()) {
        password = val.toString();
        if (password.length() < 8) { //TODO make it editable or write to config.hpp file
            return CmdError(CmdError::InvalidParam, "Too small password. Minimum 8 symbols");
        } else if (password.length() > 64) {
            return CmdError(CmdError::InvalidParam, "Too long password. Maximum 64 symbols");
        }
    } else {
        return CmdError(CmdError::InvalidParam, "No \"password\" entry");
    }
    if (auto val = obj["image"]; val.isString()) {
        image = val.toString().toLocal8Bit(); //TODO test :_)
    }

    QSqlQuery q;
    q.prepare("INSERT INTO EmployeesAndCustomers"
              "(name, entryDate, role_id, wapon_id, email, login, password, image) "
              "VALUES (:name, :entryDate, :role_id, :wapon_id, :login, :password, :image)");
    q.bindValue(":name", name);
    q.bindValue(":entryDate", entryDate);
    q.bindValue(":role_id", role);
    q.bindValue(":wapon_id", (wapon == -1 ? QVariant() : wapon));
    q.bindValue(":login", login);
    q.bindValue(":password", password);
    q.bindValue(":image", (image.length() == 0 ? QVariant() : image));

    return CmdError();
}

/*
 * name: string,
 * email: string,
 * login: string,
 * password: string,
 * image: string, < optional
 */
CmdError
exec_register_customer(QJsonObject& obj)
{
    return CmdError();
}

/*
 * name: string,
 * price: double,
 */
CmdError
exec_register_object_type(QJsonObject& obj)
{
    return CmdError();
}

/*
 * name: string,
 * ammo: int,
 * price: double,
 * ammoPrice: double,
 * image: string,
 */
CmdError
exec_register_wapon(QJsonObject& obj)
{
    return CmdError();
}

/*
 * wapon: int,
 * employee: int,
 */
CmdError
exec_assign_wapon(QJsonObject& obj)
{
    return CmdError();
}

/*
 * wapon: int,
 * count: int,
 */
CmdError
exec_pay_ammo(QJsonObject& obj)
{
    return CmdError();
}

/*
 * employee: int
 */
CmdError
exec_pay_employee(QJsonObject& obj)
{
    return CmdError();
}

/*
 * accident: int
 */
CmdError
exec_pay_accident(QJsonObject& obj)
{
    return CmdError();
}

/*
 * name: string,
 * price: double,
 */
CmdError
exec_add_object_type(QJsonObject& obj)
{
    QString name;
    double price;

    if (auto val = obj["name"]; val.isString()) {
        name = val.toString();
    } else {
        return CmdError(CmdError::InvalidParam, "");
    }

    if (auto val = obj["price"]; val.isDouble()) {
        price = val.toDouble();
    } else {
        return CmdError(CmdError::InvalidParam, "");
    }

    QSqlQuery q;
    q.prepare("INSERT INTO objectType (name, price) "
              "VALUES (:name, :price)");
    q.bindValue(":name", name);
    q.bindValue(":price", price);
    if (!q.exec()) {
        return CmdError(CmdError::SQLError, q.lastError().text());
    }

    return CmdError();
}

/*
 * id: int,
 * name: string, <- optional
 * price: double, <- optional
 */
CmdError
exec_edit_object_type(QJsonObject& obj)
{
    return CmdError();
}

/*
 * role: int,
 * name: name, <- optional
 * payMult: double, <- optional
 * payPeriod: optional, <- optional
 * commands: Array<int> <- optional
 */
CmdError
exec_update_role(QJsonObject& obj)
{
    return CmdError();
}

/*
 * employee: int
 */
CmdError
exec_get_employee_entry(QJsonObject& obj)
{
    return CmdError();
}

/*
 * customer: int
 */
CmdError
exec_get_customer_entry(QJsonObject& obj)
{
    return CmdError();
}

/*
 * accident: int
 */
CmdError
exec_get_accident_details(QJsonObject& obj)
{
    return CmdError();
}

/*
 * accounting: int
 */
CmdError
exec_get_accounting_entry(QJsonObject& obj)
{
    return CmdError();
}

/*
 * object: int
 */
CmdError
exec_get_object_detalils(QJsonObject& obj)
{
    return CmdError();
}

/*
 * role: int
 */
CmdError
exec_get_role_details(QJsonObject& obj)
{
    return CmdError();
}

/*
 * wapon: int
 */
CmdError
exec_get_wapon_details(QJsonObject& obj)
{
    return CmdError();
}

/*
 * employee: int
 */
CmdError
exec_get_duty_schedule(QJsonObject& obj)
{
    return CmdError();
}


} /* Database */ 
