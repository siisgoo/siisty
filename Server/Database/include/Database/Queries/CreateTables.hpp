#ifndef CREATETABLES_HPP_Y3XIBLZH
#define CREATETABLES_HPP_Y3XIBLZH

#define CREATE_GUILTYEMPLOYEES_TABLE                                                              \
    R"(CREATE TABLE "GuiltyEmployees" (                                                           \
        "id"            INTEGER NOT NULL,                                                         \
        "employee_id"   INTEGER NOT NULL,                                                         \
        "guiltyPercent" REAL    NOT NULL,                                                         \
        PRIMARY KEY("id"),                                                                        \
        FOREIGN KEY("employee_id") REFERENCES "EmployeesAndCustomers"("id") ON DELETE RESTRICT))"

#define CREATE_ACCIDENTS_TABLE                                                                   \
    R"(CREATE TABLE "Accidents" (                                                                \
        "id" INTEGER NOT NULL UNIQUE,                                                            \
        "name"               TEXT    NOT NULL,                                                   \
        "contract_id"        INTEGER NOT NULL,                                                   \
        "usedAmmoCount"      INTEGER,                                                            \
        "damagePrice"        REAL,                                                               \
        "guiltyEmployees_id" INTEGER,                                                            \
        PRIMARY KEY("id"),                                                                       \
        FOREIGN KEY("contract_id")        REFERENCES "Contracts"("id")       ON DELETE RESTRICT, \
        FOREIGN KEY("guiltyEmployees_id") REFERENCES "GuiltyEmployees"("id") ON DELETE RESTRICT  \
    ) WITHOUT ROWID)"

#define CREATE_ACCOUNTING_TABLE                                                                 \
    R"(CREATE TABLE "Accounting" (                                                              \
        "id"          INTEGER NOT NULL,                                                         \
        "employee_id" INTEGER NOT NULL,                                                         \
        "pay"         REAL    NOT NULL,                                                         \
        "date"        TEXT    NOT NULL,                                                         \
        FOREIGN KEY("employee_id") REFERENCES "EmployeesAndCustomers"("id") ON DELETE RESTRICT, \
        PRIMARY KEY("id")                                                                       \
    ) WITHOUT ROWID)"

#define CREATE_ASSIGNEDEMPLOYEES_TABLE                                                          \
    R"(CREATE TABLE "AssignedEmployees" (                                                       \
        "id"          INTEGER NOT NULL,                                                         \
        "employee_id" INTEGER NOT NULL,                                                         \
        FOREIGN KEY("employee_id") REFERENCES "EmployeesAndCustomers"("id") ON DELETE RESTRICT, \
        PRIMARY KEY("id"))"

#define CREATE_CONTRACTS_TABLE                                                                                \
    R"(CREATE TABLE "Contracts" (                                                                             \
        "id"                   INTEGER NOT NULL UNIQUE,                                                       \
        "assignedEmployees_id" INTEGER NOT NULL,                                                              \
        "customer_id"          INTEGER NOT NULL,                                                              \
        "objectType_id"        INTEGER NOT NULL,                                                              \
        "objectAddress"        TEXT    NOT NULL,                                                              \
        "objectWayPoint"       TEXT,                                                                          \
        "date"                 TEXT    NOT NULL,                                                              \
        "expirationDate"       TEXT    NOT NULL,                                                              \
        "weekends"             TEXT    NOT NULL,                                                              \
        FOREIGN KEY("customer_id")          REFERENCES "EmployeesAndCustomers"("id") ON DELETE RESTRICT,      \
        FOREIGN KEY("assignedEmployees_id") REFERENCES "AssignedEmployees"("employee_id") ON DELETE RESTRICT, \
        FOREIGN KEY("objectType_id")        REFERENCES "objectType"("id")                 ON DELETE RESTRICT, \
        PRIMARY KEY("id")                                                                                     \
    ) WITHOUT ROWID)"

#define CREATE_DUTYSCHEDULE_TABLE       \
    R"(CREATE TABLE "DutySchedule" (    \
        "employee_id" INTEGER NOT NULL, \
        "day"        INTEGER NOT NULL,  \
        FOREIGN KEY("employee_id") REFERENCES "EmployeesAndCustomers"("id") ON DELETE RESTRICT))"

#define CREATE_EMPLOYEESANDCUSTOMERS_TABLE \
    R"(CREATE TABLE "EmployeesAndCustomers" (                                 \
        "id"        INTEGER NOT NULL UNIQUE,                                  \
        "name"      TEXT NOT NULL,                                            \
        "entryDate" TEXT NOT NULL,                                            \
        "role_id"   INTEGER NOT NULL,                                         \
        "wapon_id"  INTEGER UNIQUE,                                           \
        "email"     TEXT UNIQUE,                                              \
        "phone"     TEXT UNIQUE,                                              \
        "authData"  TEXT NOT NULL UNIQUE,                                     \
        "image" BLOB,                                                         \
        FOREIGN KEY("role_id") REFERENCES "Roles"("id") ON DELETE RESTRICT,   \
        FOREIGN KEY("wapon_id") REFERENCES "Wapons"("id") ON DELETE RESTRICT, \
        PRIMARY KEY("id")                                                     \
    ) WITHOUT ROWID)"

#define CREATE_ROLEACCESSABLEOBJECT_TABLE    \
    R"(CREATE TABLE "RoleAccessableObject" ( \
        "id"         INTEGER NOT NULL,       \
        "table"      TEXT    NOT NULL,       \
        "field"      TEXT    NOT NULL,       \
        "accessFlag" INTEGER NOT NULL,       \
        PRIMARY KEY("id")))"

#define CREATE_ROLES_TABLE                                                                                \
    R"(CREATE TABLE "Roles" (                                                                             \
        "id"                   INTEGER NOT NULL UNIQUE,                                                   \
        "name"                 TEXT    NOT NULL UNIQUE,                                                   \
        "accessableObjects_id" INTEGER NOT NULL,                                                          \
        "payMultipler"         REAL    NOT NULL,                                                          \
        "payPeriod"            INTEGER NOT NULL,                                                          \
        PRIMARY KEY("id"),                                                                                \
        FOREIGN KEY("accessableObjects_id") REFERENCES "RoleAccessableObject"("id") ON DELETE RESTRICT))"

#define CREATE_WAPONS_TABLE              \
    R"(CREATE TABLE "Wapons" (           \
        "id"    INTEGER NOT NULL UNIQUE, \
        "name"  TEXT NOT NULL,           \
        "ammo"  INTEGER NOT NULL,        \
        "price" REAL NOT NULL,           \
        "ammoPrice" REAL NOT NULL,       \
        "image" BLOB,                    \
        PRIMARY KEY("id")                \
    ) WITHOUT ROWID)"

#define CREATE_OBJECTYPE_TABLE           \
    R"(CREATE TABLE "objectType" (       \
        "id"    INTEGER NOT NULL UNIQUE, \
        "name"  TEXT NOT NULL UNIQUE,    \
        "price" REAL NOT NULL,           \
        PRIMARY KEY("id")))"

#endif /* end of include guard: CREATETABLES_HPP_Y3XIBLZH */
