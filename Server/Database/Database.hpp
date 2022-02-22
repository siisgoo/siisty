#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

/*
 * Defenitions to work with data base
 */

#define CREATE_ACCIDENTS_TABLE_QUERY \
    CREATE TABLE "Accidents" (\
        "id"    INTEGER NOT NULL UNIQUE,\
        "name"  TEXT NOT NULL,\
        "involvedEmploee_id"    INTEGER,\
        "isEmploeeGuilty"   INTEGER,\
        "contract_id"   INTEGER NOT NULL,\
        "usedWapon_id"  INTEGER,\
        "usedAmmoCount" INTEGER,\
        "damagePrice"   INTEGER,\
        FOREIGN KEY("contract_id") REFERENCES "Contracts"("id") ON DELETE RESTRICT,\
        FOREIGN KEY("usedWapon_id") REFERENCES "Wapons"("id") ON DELETE RESTRICT,\
        FOREIGN KEY("involvedEmploee_id") REFERENCES "Employees"("id") ON DELETE RESTRICT,\
        PRIMARY KEY("id")\
    ) WITHOUT ROWID;\

#define CREATE_ACCOUNTING_TABLE_QUERY \
    CREATE TABLE "Accounting" (\
        "id"    INTEGER NOT NULL,\
        "emploee_id"    INTEGER NOT NULL,\
        "pay"   INTEGER NOT NULL,\
        "date"  TEXT NOT NULL,\
        FOREIGN KEY("emploee_id") REFERENCES "Employees"("id") ON DELETE RESTRICT,\
        PRIMARY KEY("id")\
    ) WITHOUT ROWID;\

#define CREATE_AUTHORIZEDUSERS_TABLE_QUERY \
    CREATE TABLE "AuthorizedUsers" (\
        "employee_id"   INTEGER NOT NULL UNIQUE,\
        "login" TEXT NOT NULL UNIQUE,\
        "password"  TEXT NOT NULL UNIQUE,\
        "privilegies"   INTEGER NOT NULL,\
        "accessible_tables" TEXT,\
        FOREIGN KEY("employee_id") REFERENCES "Employees"("id") ON DELETE RESTRICT\
    );\

#define CREATE_CONTRACTS_TABLE_QUERY \
    CREATE TABLE "Contracts" (\
        "id"    INTEGER NOT NULL UNIQUE,\
        "employee_id"   INTEGER NOT NULL,\
        "customer_id"   INTEGER NOT NULL,\
        "objectType_id" INTEGER NOT NULL,\
        "objectAddress" TEXT NOT NULL UNIQUE,\
        "expirationDate"    TEXT NOT NULL,\
        "date"  TEXT NOT NULL,\
        FOREIGN KEY("objectType_id") REFERENCES "objectType"("id") ON DELETE RESTRICT,\
        FOREIGN KEY("employee_id") REFERENCES "Employees"("id") ON DELETE RESTRICT,\
        PRIMARY KEY("id"),\
        FOREIGN KEY("customer_id") REFERENCES "Customers"("id") ON DELETE RESTRICT\
    ) WITHOUT ROWID;\

#define CREATE_CUSTOMERS_TABLE_QUERY \
    CREATE TABLE "Customers" (\
        "id"    INTEGER NOT NULL UNIQUE,\
        "name"  TEXT NOT NULL,\
        "phone" TEXT NOT NULL UNIQUE,\
        "email" TEXT NOT NULL UNIQUE,\
        PRIMARY KEY("id")\
    ) WITHOUT ROWID;\

#define CREATE_DUTYSCHEDULE_TABLE_QUERY \
    CREATE TABLE "DutySchedule" (\
        "emploee_id"    INTEGER NOT NULL,\
        "day"   TEXT\
    );\

#define CREATE_EMPLOYEES_TABLE_QUERY \
    CREATE TABLE "Employees" (\
        "id"    INTEGER NOT NULL UNIQUE,\
        "name"  TEXT NOT NULL,\
        "role_id"   INTEGER NOT NULL,\
        "wapon_id"  INTEGER,\
        FOREIGN KEY("role_id") REFERENCES "Roles"("id") ON DELETE RESTRICT,\
        PRIMARY KEY("id"),\
        FOREIGN KEY("wapon_id") REFERENCES "Wapons"("id") ON DELETE RESTRICT\
    ) WITHOUT ROWID;\

#define CREATE_ROLES_TABLE_QUERY \
    CREATE TABLE "Roles" (\
        "id"    INTEGER NOT NULL UNIQUE,\
        "name"  TEXT NOT NULL UNIQUE,\
        "payMultipler"  REAL NOT NULL,\
        PRIMARY KEY("id")\
    );\

#define CREATE_WAPONS_TABLE_QUERY \
    CREATE TABLE "Wapons" (\
        "id"    INTEGER NOT NULL UNIQUE,\
        "name"  TEXT NOT NULL,\
        "ammo"  INTEGER NOT NULL,\
        PRIMARY KEY("id")\
    ) WITHOUT ROWID;\

#define CREATE_OBJECTTYPE_TABLE_QUERY \
    CREATE TABLE "objectType" (\
        "id"    INTEGER NOT NULL UNIQUE,\
        "name"  TEXT NOT NULL UNIQUE,\
        "price" NUMERIC NOT NULL,\
        PRIMARY KEY("id")\
    )\

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
