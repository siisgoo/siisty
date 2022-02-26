#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

#include <QVariant>
#include <QVector>
#include <QString>
#include <QtSql>

#include "Database/Role.hpp"
#include "Database/tables.hpp"

namespace Database {

using money_t = float;

class SQLite {
    public:
        SQLite();
        virtual ~SQLite();

        QSqlError initDb(const QString& path);

        Role addRole(int id, QString& name, int privilegiesID, float payMult);
        TablePrivilegies addPrivilegy(int id, AccessMap);
            // Add new entry to Roles/Privilegies

        ObjectType addObjectType(QString& name, money_t price);
            // Add new entry to objectType

        AccountingEntry registryEmploeePay(int emploeeID);
            // Add new entry to Accounting table;
            //
            // Emploee income calculating by formula:
            //    >> Role->payMultipler * objectType->price * days
            // Payment period defined in Role->payPeriod
            //
            // Payment may be negativ.
            //
            // All payments summarize in "Period Report"

        Contract addEmployeeToContract(int contractID);
        Contract createContract(int emploeeID, int customerID, int objTypeID,
                            QString& address,
                            QString wayPoint, // if objTypeID isnt incosation type wayPoint must by empty
                            QString& startDate,
                            QString& experationData,
                            WeekVector weekends); // each cell - week day number from zero
            // Create new entry in Contracts table
            // Links emploeeID with objectAddress
            //
            // Also automaticaly creates Entries in DutySchedule

        Wapon registryWapon(QString& name, int ammo);
            // Create new entry in Wapons table

        Human attachWaponToEmploee(int emploeeID, int waponID);
            // Attach wapon to emploee
            // do not check role

        Human registryUser(QString& name,
                QString& encryptedAuth,
                int role,
                int waponID = -1);
            // Add new entry to AuthorizedUsers
            // encryptedAuth - encrypted login+password by RSA pulic key
            //
            // Contain both of Emploees and Customers
            // if role < 0 its a customer

        Accident registryAccident(QString& name,
                int  contractID,
                QVector<int> emploeesID,
                bool guilty,
                int  usedAmmoConunt,
                money_t damagePrice);
            // Add new entry to Accidents;
            // emploeeID and guilty,
            // wapon and usedAmmoCount,
            // can be empty, if *ID is less zero
            //
            // Also updates int Table Wapons the ammo count
};

} /* Database */

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
