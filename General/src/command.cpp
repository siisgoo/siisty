#include "Database/command.hpp"
#include "Database/Utility.hpp"

#include <exception>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

namespace Database {

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
int
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
                return (int)CommandErrno::InvalidParam;
            }
        }
    } else {
        return (int)CommandErrno::InvalidParam;
    }

    if (auto val = obj["customer"]; val.isDouble()) {
        customer = val.toInt();
    } else {
        return (int)CommandErrno::InvalidParam;
    }

    if (auto val = obj["objectType"]; val.isDouble()) {
        objType = val.toInt();
    } else {
        return (int)CommandErrno::InvalidParam;
    }

    if (auto val = obj["address"]; val.isString()) {
        addr = val.toString();
    } else {
        return (int)CommandErrno::InvalidParam;
    }

    if (auto val = obj["address"]; val.isDouble()) {
        addr = val.toString();
    } else {
        return (int)CommandErrno::InvalidParam;
    }

    return (int)CommandErrno::OK;
}

/*
 * contract: int,
 */
int
exec_make_duty_schedule(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
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
int
exec_register_accident(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * name: string,
 * role: int,
 * wapon: int, <- optional
 * email: string, <- optional
 * login: string,
 * password: string,
 * image: string, <- optional
 */
int
exec_register_employee(QJsonObject& obj)
{
    QString name;
    int role;
    int wapon = -1;
    QString email;
    QString login;
    QString password;
    QByteArray image;

    return (int)CommandErrno::OK;
}

/*
 * name: string,
 * email: string,
 * login: string,
 * password: string,
 * image: string, < optional
 */
int
exec_register_customer(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * name: string,
 * price: double,
 */
int
exec_register_object_type(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * name: string,
 * ammo: int,
 * price: double,
 * ammoPrice: double,
 * image: string,
 */
int
exec_register_wapon(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * wapon: int,
 * employee: int,
 */
int
exec_assign_wapon(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * wapon: int,
 * count: int,
 */
int
exec_pay_ammo(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * employee: int
 */
int
exec_pay_employee(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * accident: int
 */
int
exec_pay_accident(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * name: string,
 * price: double,
 */
int
exec_add_object_type(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * id: int,
 * name: string, <- optional
 * price: double, <- optional
 */
int
exec_edit_object_type(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * role: int,
 * name: name, <- optional
 * payMult: double, <- optional
 * payPeriod: optional, <- optional
 * commands: Array<int> <- optional
 */
int
exec_update_role(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * employee: int
 */
int
exec_get_employee_entry(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * customer: int
 */
int
exec_get_customer_entry(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * accident: int
 */
int
exec_get_accident_details(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * accounting: int
 */
int
exec_get_accounting_entry(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * object: int
 */
int
exec_get_object_detalils(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * role: int
 */
int
exec_get_role_details(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * wapon: int
 */
int
exec_get_wapon_details(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}

/*
 * employee: int
 */
int
exec_get_duty_schedule(QJsonObject& obj)
{
    return (int)CommandErrno::OK;
}


} /* Database */ 
