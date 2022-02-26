#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

#include <QVariant>
#include <QVector>
#include <QString>
#include <QtSql>

#include "Database/Utility.hpp"
#include "Database/Role.hpp"
#include "Database/tables.hpp"

/*
 * TODO
 *
 * Make advanced accounting
 * Now not accounting benzine count and ammo
 */

namespace Database {

using money_t = float;

const int workedOutDaysTrashHold = 10;
    // from config TODO

class Calculator;
    // provides preset calculations and maintence operations
    // in database

class Accessor;
    // provides access to tables
    // by check authData and role

class SQLite;
    // Base of Database
    // provides initialization methods
    // Sub classes provides
    // create/update/fetch methods
    //
    // TODO update name of class!!

               /* ░█▀▀░█░░░█▀█░█▀▀░█▀▀░░░█▀▀░▄▀▄░█░░░▀█▀░▀█▀░█▀▀ */
               /* ░█░░░█░░░█▀█░▀▀█░▀▀█░░░▀▀█░█\█░█░░░░█░░░█░░█▀▀ */
               /* ░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░░░▀▀▀░░▀\░▀▀▀░▀▀▀░░▀░░▀▀▀ */

class SQLite {
    public:
        class TableEntry;

        class DutySchedule;
            // contain duty schedule(all dates) for employee

        class Role;
            // contain role entry

        class ObjectType;
            // contain object type defenition

        class AccountingEntry;
            // contain one accounting entry

        class Contract;
            // contain contract entry
            // with all employees assigned to contract

        class Wapon;
            // contain one wapon entry

        class Accident;
            // contain one accident entry

        class Human;
            // contain one human(employee/customer) entry

        using AccessMap     = QMap<QString, int>;
            // [tableName] = privilegies

        using HumanVector   = QVector<Human>;

        using Employee = Human;
        using Customer = Human;

    private:
        QSqlError init(const QString& path);

    public:
        SQLite();
        virtual ~SQLite();
};

                      /* ░█▀▀░█░█░█▀▄░█▀▀░█░░░█▀█░█▀▀░█▀▀ */
                      /* ░▀▀█░█░█░█▀▄░█░░░█░░░█▀█░▀▀█░▀▀█ */
                      /* ░▀▀▀░▀▀▀░▀▀░░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀ */
            /* ░█▀▄░█▀▀░█▀█░█░░░▀█▀░▀▀█░█▀█░▀█▀░▀█▀░█▀█░█▀█░█▀█░█▀▀ */
            /* ░█▀▄░█▀▀░█▀█░█░░░░█░░▄▀░░█▀█░░█░░░█░░█░█░█░█░█░█░▀▀█ */
            /* ░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀ */

class SQLite::TableEntry {
    protected:
        int  _id;
        bool __isNull;
        TableEntry(const int id = -200)
            : _id(id), __isNull(true) {}

    public:
        virtual ~TableEntry();
        virtual bool fetch(const QVariant) = 0;
        virtual bool update() = 0;

        int  id() const     { return _id; }
        bool isNull() const { return __isNull; }
            // updates on fetch() or by setter function
};

class SQLite::ObjectType : public SQLite::TableEntry {
    QString _name;
    money_t _basePrice;

    public:
        virtual ~ObjectType();
        virtual bool fetch(QVariant);
        virtual bool update();

        static ObjectType create(const QString name, const money_t basePrice,
                                 int id = -1);

        QString& name();
        money_t  basePrice();
        void     setBasePrice(const money_t);
};

class SQLite::Role : public SQLite::TableEntry {
    public:
        struct FieldAndAccess {
            int     flag;
            QString field;
        };
        using AccessMap = QMap<QString, FieldAndAccess>;

    private:
        QString _name;
        money_t _payMultipler;
        int     _payPeriod;

        AccessMap _accessMap;

    public:
        virtual ~Role();
        virtual bool fetch(QVariant);
        virtual bool update();

        static Role create(const QString& name, const AccessMap&,
                money_t payMult, int payPeriod, int id = -1);

        QString& name();
        money_t  payMult() const;
        int      payPeriod() const;
        AccessMap& privilegies() const;

        void setPrivilegies(const AccessMap&);
        void setPayMult(money_t);
        void setPayPeriod(int);
};

class SQLite::Wapon : public SQLite::TableEntry {
    QString    _name;
    int        _ammo;
    money_t    _price;
    money_t    _ammoPrice;
    QByteArray _image;

    public:
        virtual ~Wapon();
        virtual bool fetch(const QVariant);
        virtual bool update();

        static Wapon create(const QString& name, int ammo, money_t price,
                            money_t ammoPrice, const QByteArray& image, int id = -1);

        QString&   name();
        int        ammoCount() const;
        money_t    price() const;
        money_t    ammoPrice() const;
        QByteArray imageRaw() const;

        void setAmmoCount(int);
        void setPrice(money_t);
        void setAmmoPrice(money_t);
        void setImage(const QByteArray&);
};

class SQLite::Human : public SQLite::TableEntry {
    Role       _role;
    Wapon      _wapon;
    QDate      _entryDate;
    QString    _name;
    QString    _email;
    QString    _phone;
    QByteArray _authData;
    QByteArray _image;

    public:
        virtual ~Human();
        virtual bool fetch(const QVariant);
        virtual bool update();

        //add polimorphs
        static Human create(const QString& name, const QString& email,
                            const QString& phone, const QByteArray& authData,
                            const QByteArray& img, const Role& role,
                            const Wapon& wapon,
                            const QDate entryDate = QDate::currentDate(),
                            int id = -1);

        QString&    name();
        QString&    email() const;
        QString&    phone() const;
        QByteArray& authData() const;
        Role&       role() const;
        QDate&      entryDate() const;
        QByteArray& imageRaw() const;

        void setEmail(const QString&);
        void setPhone(const QString&);
        void setAuthData(const QByteArray&);
        void setRole(const QString&);
        void setEntryDate(const QString&);
        void setImageRaw(const QByteArray&);
};

class SQLite::Contract : SQLite::TableEntry {
    HumanVector _employees;
    Human       _customer;
    ObjectType  _objectType;
    QString     _objectAddress;
    QString     _wayPoint;
    QDate       _startDate;
    QDate       _experationData;
    Week        _weekends;

    public:
        virtual bool fetch(const QVariant);
        virtual bool update();

        static Contract create(const Human& employee, const Human& customer,
                               const ObjectType& ot, const QString& address,
                               const QDate experation,
                               const QDate start = QDate::currentDate(),
                               const Week& weekends = Weekends::five_on_two,
                               int id = -1);
            // create for secure one object with one security

        static Contract create(const HumanVector& employees,
                               const Human& customer, const ObjectType& ot,
                               const QString& address, const QDate experation,
                               const QDate start = QDate::currentDate(),
                               const Week& weekends = Weekends::five_on_two,
                               int id = -1);
            // create for secure one object with multiple security

        static Contract create(const HumanVector& employees,
                               const Human& customer, const ObjectType& ot,
                               const QString& address, const QString& wayPoint,
                               const QDate experation,
                               const QDate start = QDate::currentDate(),
                               const Week& weekends = Weekends::five_on_two,
                               int id = -1);
            // create for inkose object with one or multiple inkosors

        HumanVector& employees() const;
        Human&       customer() const;
        ObjectType&  objectType() const;
        QString&     objectAddress() const;
        QString&     wayPoint() const;
        QDate&       startDate() const;
        QDate&       experationDate() const;
        Week&        weekends() const;

        void setEmployees(const Human&);
        void setCustomer(const Human&);
        void setObjectType(const ObjectType&);
        void setObjectAddress(const QString&);
        void setWayPoint(const QString&);
        void setStartDate(const QDate& = QDate::currentDate());
        void setExperationDate(const QDate&);
        void setWeekends(const Week&);
};

class SQLite::Accident : public SQLite::TableEntry {
    QString  _name;
    Contract _contract;
    HumanVector    _guiltyEmployees; // vvvv linked
    QVector<float> _guiltyPercent;   // ^^^^ linked
    int      _usedAmmoConunt;
    money_t  _damagePrice;

    public:
        virtual bool fetch(const QVariant);
        virtual bool update();

        static Accident create(QString& name, Contract& contract,
                               money_t damagePrice, bool emplGuilty = true,
                               int usedAmmoCount = 0, int id = -1);

        QString& name();

        // TODO
        // add getter+setter guilty percentage

        Contract&    contract() const;
        HumanVector& guiltyEmployees() const;
        int          usedAmmoCount() const;
        money_t      damagePrice() const;

        void setContract(const Contract&);
        void addGuiltyEmployees(const Human&);
        void setUsedAmmoCount(int);
        void setDamagePrice(money_t);
};

class SQLite::AccountingEntry : public SQLite::TableEntry {
    Human   _employee;
    money_t _pay;
    QDate   _date;

    public:
        virtual bool fetch(const QVariant);
        virtual bool update();

        static AccountingEntry create(const Human& employee, money_t pay,
                                      const QDate& = QDate::currentDate(),
                                      int id = -1);

        Human&  employee() const;
        money_t pay() const;
        QDate   payDate() const;

        void setEmployee(const Human&);
        void setPay(money_t);
        void setPayDate(const QDate&);
};

// contain all days of one employee
class SQLite::DutySchedule :public SQLite::TableEntry {
    Human _employee;
    QVector<QDate> _workdays;

    public:
        virtual bool fetch(const QVariant); //by employee
        virtual bool update();

        static DutySchedule create(const Human& employee, const QVector<Week>& workdays);

        Human& employee() const;
        QVector<Week>& workdays() const;

        void employee(const Human&);
        void workdays(const QVector<QDate>&);
};

       /* ░█▀▀░█░░░█▀█░█▀▀░█▀▀░░░█▀▀░█▀█░█░░░█▀▀░█░█░█░░░█▀█░▀█▀░█▀█░█▀▄ */
       /* ░█░░░█░░░█▀█░▀▀█░▀▀█░░░█░░░█▀█░█░░░█░░░█░█░█░░░█▀█░░█░░█░█░█▀▄ */
       /* ░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░░░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀░▀ */

class Calculator {
    public:
        Calculator();
        virtual ~Calculator();

        void trimDutySchedule();
            // delete expared contracts work days

        void handleAccident();
};

           /* ░█▀▀░█░░░█▀█░█▀▀░█▀▀░░░█▀█░█▀▀░█▀▀░█▀▀░█▀▀░█▀▀░█▀█░█▀▄ */
           /* ░█░░░█░░░█▀█░▀▀█░▀▀█░░░█▀█░█░░░█░░░█▀▀░▀▀█░▀▀█░█░█░█▀▄ */
           /* ░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀ */

class Accessor {
    SQLite::Human _user;

    public:
        Accessor(const QByteArray& authData);
        virtual ~Accessor();

        QSqlError performSQL(const QString& query);
            // identification
            // retrun
            // TRUE if authData exists(user registred),
            // FALSE otherwise
};

} /* Database */

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
