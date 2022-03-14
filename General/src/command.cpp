#include "Database/command.hpp"
#include "Database/Utility.hpp"
#include "Crypto/Hash.hpp"

#include <QLatin1String>
#include <QtSql>
#include <ctype.h>

#include <QElapsedTimer>
    // onlye for Debug

#include <exception>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

// IMAGES are stored as QLatin1String(QByteArray().toBase64)

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

bool    CmdError::Ok()      { return _errno == OK; }
int     CmdError::Type()    { return _errno; }
QString CmdError::String()  { return QString(CommandErrorDesc[_errno].desc) +  ": " + _details; }
QString CmdError::Name()    { return CommandErrorDesc[_errno].name; }
QString CmdError::Details() { return _details; }

/*
 * query: string
 */
CmdError
exec_create_table(QJsonObject& obj)
{
    QSqlQuery q;
    QString query_s = obj.take("query").toString();

    if (!query_s.length()) {
        return CmdError(CmdError::InvalidParam, "No query passed");
    }

    if (!q.exec(query_s)) {
        return CmdError(CmdError::SQLError, q.lastQuery() + " " + q.lastError().text());
    }

    return CmdError();
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

/*
 * login and password must be passed as plaintext
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
    int wapon;
    QString email;
    QString login;
    QByteArray password;
    QByteArray image;

    QJsonValue buf;

    buf = obj.take("entryDate");
    entryDate = (buf.isUndefined() ? QDateTime::currentSecsSinceEpoch() : buf.toInteger());

    buf = obj.take("role");
    role = (buf.isUndefined() ? -1 : buf.toInteger());

    buf = obj.take("wapon");
    wapon = (buf.isUndefined() ? -1 : buf.toInteger());

    name = obj.take("name").toString();
    email = obj.take("email").toString();
    login = obj.take("login").toString();
    password = obj.take("password").toString().toLatin1();
    image = obj.take("image").toString().toLatin1();

    // check values
    if (!name.length() ||
            !login.length() ||
            !password.length() ||
            role < 0)
    {
        return CmdError(CmdError::InvalidParam, "Some parapeter not passed or is NULL");
    }

    // check password
    if (passwordQuality(password) == PasswordQuality::UNAVALIBLE) {
        return CmdError(CmdError::InvalidParam, "Unavalible password"); // add more informative message aha
    }

    QByteArray salt = saltGen(passWeaknesses(password));
    QByteArray passHash =
        encryptPassword(password, salt);

    QSqlQuery q;
    q.prepare("INSERT INTO EmployeesAndCustomers"
                     "(name,   entryDate,  role_id,  wapon_id,  email,  login,  password,  salt,  image) "
              "VALUES (:name, :entryDate, :role_id, :wapon_id, :email, :login, :password, :salt, :image)");
    q.bindValue(":name", name);
    q.bindValue(":entryDate", entryDate);
    q.bindValue(":role_id", role);
    q.bindValue(":wapon_id", (wapon == -1 ? QVariant() : wapon));
    q.bindValue(":email", (email.length() > 0 ? email : QVariant()));
    q.bindValue(":login", login);
    q.bindValue(":password", passHash);
    q.bindValue(":salt", salt);
    q.bindValue(":image", (image.length() == 0 ? QVariant() : image));

    if (!q.exec()) {
        return CmdError(CmdError::SQLError, q.lastQuery() + " " + q.lastError().text());
    }

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
    return exec_register_employee(obj); //TODO add some checks maybe
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
    QString name;
    int ammo;
    double price;
    double ammoPrice;
    QByteArray image;

    QJsonValue buf;

    qDebug() << "Adding wapon";

    name = obj.take("name").toString();
    buf = obj.take("ammo");
    ammo = (buf.isDouble() ? buf.toInteger() : -1);
    buf = obj.take("ammoPrice");
    ammoPrice = (buf.isDouble() ? buf.toInteger() : -1);
    //IMAGE TODO

    if (!name.length() ||
            ammo < 0 ||
            ammoPrice < 0)
    {
        return CmdError(CmdError::InvalidParam, "Empty or not exists parameter passed");
    }

    QSqlQuery q;
    q.prepare("INSERT INTO Wapons (name, price, ammo, ammoPrice, image)"
              "VALUES (:name, :price, :ammo, :ammoPrice, :image)");
    q.bindValue(":name", name);
    q.bindValue(":price", price);
    q.bindValue(":ammo", ammo);
    q.bindValue(":ammoPrice", ammoPrice);
    q.bindValue(":image", (image.length() > 0 ? image.toBase64() : QVariant()));

    if (!q.exec()) {
        return CmdError(CmdError::SQLError, QString(q.lastQuery() + " " + q.lastError().text()));
    }

    qDebug() << "Adding wapon success";

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
        return CmdError(CmdError::SQLError, q.lastQuery() + " " + q.lastError().text());
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
 * customer: int OR customer: string,
 */
CmdError
exec_get_customer_entry(QJsonObject& obj)
{
    return CmdError();
}

/*
 * accident: int OR accident: string
 */
CmdError
exec_get_accident_details(QJsonObject& obj)
{
    return CmdError();
}

/*
 * accounting: int OR date: int
 */
CmdError
exec_get_accounting_entry(QJsonObject& obj)
{
    return CmdError();
}

/*
 * object: int OR object: string
 */
CmdError
exec_get_object_detalils(QJsonObject& obj)
{
    return CmdError();
}

/*
 * role: int OR role: name
 */
CmdError
exec_get_role_details(QJsonObject& obj)
{
    return CmdError();
}

/*
 * wapon: int OR wapon: string
 */
CmdError
exec_get_wapon_details(QJsonObject& obj)
{
    return CmdError();
}

/*
 * employee: int OR employee: string
 * dateStart: int <- optional
 * dateEnd: int <- optional
 */
CmdError
exec_get_duty_schedule(QJsonObject& obj)
{
    return CmdError();
}


} /* Database */ 
