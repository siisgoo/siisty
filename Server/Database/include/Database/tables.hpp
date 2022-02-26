#ifndef TABLES_HPP_URXDMEZB
#define TABLES_HPP_URXDMEZB

#include "Database/tables_map.hpp"
#include "Database/Role.hpp"

#include <QMap>
#include <QString>
#include <QDate>

namespace Database {

#define Q(x) #x
#define QUOTE(x) Q(x)

#define XX(num, name, query) name = num,
    enum class Tables : int {
        TABLES_MAP(XX)
        TablesCount
    };
#undef XX

const auto TABLE_ARRAY_SEPARATOR = R"(:)";

enum class Weekdays {
    Mondey,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
};

#include <array>
class Human;
using HumanVector = QVector<Human>;
using Week = Weekdays[7];

// presets
struct Weekends {
    static Week five_on_two; //{Weekdays::Saturday, Weekdays::Sunday};
};

enum class PrivilegiesOperations : int {
    READ  = 0x1,
    WRITE = 0x2,
};

class TableEntry {
    protected:
        int  _id;
        bool __isNull;
        TableEntry(int id = -200)
            : _id(id), __isNull(true) {}

    public:
        virtual ~TableEntry();
        virtual bool fetch(QVariant) = 0;
        virtual bool update() = 0;

        bool isNull() { return __isNull; }
};

/* val < 0 mean not involved/used */
class ObjectType : public TableEntry {
    QString _name;
    float   _basePrice;

    public:
        virtual ~ObjectType();
        virtual bool fetch(QVariant);
        virtual bool update();

        static ObjectType create(QString& name, float basePrice, int id = -1);

        int      id() const;
        QString& name();
        float&   basePrice();
};


/* Contain all settings for one ID */
using AccessMap = QMap<QString, int>;
class TablePrivilegies : public TableEntry {
    AccessMap _accessList;

    public:
        virtual ~TablePrivilegies();
        virtual bool fetch(QVariant);
        virtual bool update();

        static TablePrivilegies create(AccessMap, int id = -1);

        int id() const;
        AccessMap accessableTables() const;
        bool canAccessToTable(QString&);
        bool canPerformOperation(QString& table, int);
        void setTableOperations(QString& table, int);
        void addAccessableTable(QString&, int);
        void removeAccessableTable(QString&);
};

class Role : public TableEntry {
    QString   _name;
    TablePrivilegies _privelegy;
    float     _payMultipler;
    int       _payPeriod;

    public:
        virtual ~Role();
        virtual bool fetch(QVariant);
        virtual bool update();

        static Role create(QString& name, TablePrivilegies& priv,
                float payMult, int payPeriod, int id = -1);

        int id() const;
        TablePrivilegies privilegies() const;
        QString role() const;
        float   payMult() const;
        int     payPeriod() const;
};

class Wapon : public TableEntry {
    QString    _name;
    int        _ammo;
    float      _price;
    float      _ammoPrice;
    QByteArray _image;

    public:
        virtual ~Wapon();
        virtual bool fetch(QVariant);
        virtual bool update();

        static Wapon create(QString& name, int ammo, float price,
                            float ammoPrice, QByteArray image, int id = -1);

        int id() const;
        QString&   name() const;
        int        ammoCount() const;
        float      price() const;
        float      ammoPrice() const;
        QByteArray imageRaw() const;
};

class Human : public TableEntry {
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
        virtual bool fetch(QVariant);
        virtual bool update();

        //add polimorphs
        static Human create(QString& name, QString& email, QString& phone,
                            QByteArray& authData, QByteArray& img, Role& role,
                            Wapon& wapon, QDate entryDate = QDate::currentDate(), int id = -1);

        int id() const;
        QString&    name() const;
        QString&    email() const;
        QString&    phone() const;
        QByteArray& authData() const;
        Role&       role() const;
        QDate&      entryDate() const;
        QByteArray& imageRaw() const;
};

class Contract : TableEntry {
    HumanVector _employees;
    Human       _customer;
    ObjectType  _objectType;
    QString     _objectAddress;
    QString     _wayPoint;
    QDate       _startDate;
    QDate       _experationData;
    Week  _weekends;

    public:
        virtual bool fetch(QVariant);
        virtual bool update();

        static Contract create(Human& employee, Human& customer, ObjectType& ot,
                               QString& address, QDate experation,
                               QDate start = QDate::currentDate(),
                               Week weekends = Weekends::five_on_two,
                               int id = -1);
        static Contract create(HumanVector& employees, Human& customer,
                               ObjectType& ot, QString& address,
                               QDate experation,
                               QDate start = QDate::currentDate(),
                               Week weekends = Weekends::five_on_two,
                               int id = -1);
        static Contract create(HumanVector& employees, Human& customer,
                               ObjectType& ot, QString& address,
                               QString& wayPoint, QDate experation,
                               QDate start = QDate::currentDate(),
                               Week weekends = Weekends::five_on_two,
                               int id = -1);

        int id() const;
        HumanVector& employees() const;
        Human& customer() const;
        ObjectType& objectType() const;
        QString& objectAddress() const;
        QString& wayPoint() const;
        QDate& startDate() const;
        QDate& experationDate() const;
        Week weekends() const;
};

class Accident : public TableEntry {
    QString  _name;
    Contract _contract;
    bool     _employeeGuilty;
    int      _usedAmmoConunt;
    float    _damagePrice;

    public:
        virtual bool fetch(QVariant);
        virtual bool update();

        static Accident create(QString& name, Contract& contract,
                               float damagePrice, bool emplGuilty = true,
                               int usedAmmoCount = 0, int id = -1);

        int id() const;
        QString& name() const;
        Contract& contract() const;
        QVector<Human>& involvedEmployees() const;
        int usedAmmoCount() const;
        float damagePrice() const;
};

class AccountingEntry : public TableEntry {
    Human _employee;
    float _pay;
    QDate _date;

    public:
        virtual bool fetch(QVariant);
        virtual bool update();

        static AccountingEntry create(Human& employee, float pay,
                                      QDate = QDate::currentDate(),
                                      int id = -1);

        int id() const;
        Human& employee() const;
        float  pay() const;
        QDate  payDate() const;
};

// contain all days of one employee
class DutySchedule :public TableEntry {
    Human _employee;
    Week _workdays;

    public:
        virtual bool fetch(QVariant); //by employee
        virtual bool update();

        static DutySchedule create(Human& employee, Week workdays);

        Human& employee() const;
        Week& workdays() const;
};

using ptrTableEntry = QPointer<TableEntry>;

} /* Database  */

#endif /* end of include guard: TABLES_HPP_URXDMEZB */
