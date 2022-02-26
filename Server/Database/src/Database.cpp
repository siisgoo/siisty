#include "Database/Database.hpp"

namespace Database {

#define XX(num, name, query) { Tables:: name, QUOTE(name), query },
    static struct tables_def {
        Tables number;
        const char * name;
        const char * createQuery;
    } tablesDefenitions[] = {
        TABLES_MAP(XX)
    };
#undef XX

#define XX(num, val) { Roles:: val, QUOTE(val) },
    static struct role_str {
        Roles number;
        const char * string;
    } roleString[] {
        ROLE_MAP(XX)
    };
#undef XX

QSqlError
initDb(const QString& path)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(path);

    if (!sdb.open())
        return sdb.lastError();

    int i;
    QStringList tables = sdb.tables();
    for (i = 0; i < (int)Tables::TablesCount
            && tables.contains(tablesDefenitions[i]); i++)
        ;

    // do skip
    if (i == (int)Tables::TablesCount) {
        return QSqlError();
    }

    QSqlQuery q;
    for (i = 0; i < (int)Tables::TablesCount; i++) {
        if (!q.exec(tablesDefenitions[i].createQuery)) {
            return q.lastError();
        }
    }

    //create defults

    return QSqlError();
}

Role
addRole(int id,
        QString& name,
        int privilegiesID,
        float payMult)
{
    Role role;
}

TablePrivilegies
addPrivilegies(int id, AccessMap)
{

}

ObjectType
addObjectType(QString& name, money_t price)
{

}

AccountingEntry
registryEmploeePay(int emploeeID)
{

}

Contract
addEmployeeToContract(int contractID)
{

}

Contract
createContract(int emploeeID, int customerID, int objTypeID,
                    QString& address,
                    QString wayPoint, // if objTypeID isnt incosation type wayPoint must by empty
                    QString& startDate,
                    QString& experationData,
                    WeekVector weekends)
{

}

Wapon
registryWapon(QString& name, int ammo)
{

}

Human
attachWaponToEmploee(int emploeeID, int waponID)
{

}

Human
registryUser(QString& name,
        QString& encryptedAuth,
        int role,
        int waponID)
{

}

Accident
registryAccident(QString& name,
        int  contractID,
        QVector<int> emploeesID,
        bool guilty,
        int  usedAmmoConunt,
        money_t damagePrice)
{

}


ObjectType ObjectType::create()
{
}

} /* Database  */ 
