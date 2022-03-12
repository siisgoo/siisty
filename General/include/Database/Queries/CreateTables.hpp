#ifndef CREATETABLES_HPP_Y3XIBLZH
#define CREATETABLES_HPP_Y3XIBLZH

static const auto CREATE_ACCIDENTS_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "Accidents" ( "id" INTEGER NOT NULL UNIQUE, "name" TEXT NOT NULL,
    "contract_id" INTEGER NOT NULL, "usedAmmoCount" INTEGER, "damagePrice" REAL,
    "assignedEmployees_id" INTEGER, FOREIGN KEY("contract_id") REFERENCES "Contracts"("id") ON
    DELETE RESTRICT, FOREIGN KEY("assignedEmployees_id") REFERENCES "AssignedEmployees"("id")
    ON DELETE RESTRICT, PRIMARY KEY("id") ) WITHOUT ROWID
    )";

static const auto CREATE_ACCOUNTING_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "Accounting" ( "id" INTEGER NOT NULL UNIQUE, "accountingType_id" INTEGER NOT
    NULL, "pay" REAL NOT NULL, "date" TEXT NOT NULL, FOREIGN KEY("accountingType_id")
    REFERENCES "AccountingType"("id") ON DELETE RESTRICT, PRIMARY KEY("id") ) WITHOUT ROWID
    )";

static const auto CREATE_ACCOUNTING_TYPE_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "AccountingType" ( "id" INTEGER NOT NULL UNIQUE, "name" TEXT NOT NULL UNIQUE,
    PRIMARY KEY("id","name") ) WITHOUT ROWID
    )";

static const auto CREATE_ASSIGNED_EMPLOYEES_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "AssignedEmployees" ( "id" INTEGER NOT NULL, "employee_id" INTEGER NOT NULL,
    "guiltyPercent" REAL NOT NULL, "usedAmmo" INTEGER, FOREIGN KEY("employee_id") REFERENCES
    "EmployeesAndCustomers"("id") ON DELETE RESTRICT, PRIMARY KEY("id") )
    )";

static const auto CREATE_CONTRACTS_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "Contracts" ( "id" INTEGER NOT NULL UNIQUE, "assignedEmployees_id" INTEGER NOT
    NULL, "customer_id" INTEGER NOT NULL, "objectType_id" INTEGER NOT NULL, "objectAddress"
    TEXT NOT NULL, "objectWayPoint" TEXT, "date" TEXT NOT NULL, "expirationDate" TEXT NOT NULL,
    "weekends" TEXT NOT NULL, FOREIGN KEY("customer_id") REFERENCES
    "EmployeesAndCustomers"("id") ON DELETE RESTRICT, PRIMARY KEY("id"), FOREIGN
    KEY("assignedEmployees_id") REFERENCES "AssignedEmployees"("employee_id") ON DELETE
    RESTRICT, FOREIGN KEY("objectType_id") REFERENCES "objectType"("id") ON DELETE RESTRICT )
    )";

static const auto CREATE_DUTY_SCHEDULE_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "DutySchedule" ( "emploee_id" INTEGER NOT NULL, "day" INTEGER NOT NULL,
    FOREIGN KEY("emploee_id") REFERENCES "EmployeesAndCustomers"("id") ON DELETE RESTRICT )
    )";

static const auto CREATE_EMPLOYEES_AND_CUSTOMERS_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "EmployeesAndCustomers" ( "id" INTEGER NOT NULL UNIQUE, "name" TEXT NOT NULL,
    "entryDate" TEXT NOT NULL, "role_id" INTEGER NOT NULL, "wapon_id" INTEGER UNIQUE, "email"
    TEXT UNIQUE, "login" TEXT NOT NULL UNIQUE, "password" TEXT NOT NULL UNIQUE, "image" BLOB,
    FOREIGN KEY("wapon_id") REFERENCES "Wapons"("id") ON DELETE RESTRICT, FOREIGN
    KEY("role_id") REFERENCES "Roles"("id") ON DELETE RESTRICT, PRIMARY KEY("id") ) WITHOUT
    ROWID
    )";

static const auto CREATE_ROLES_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "Roles" ( "id" INTEGER NOT NULL UNIQUE, "name" TEXT NOT NULL UNIQUE,
    "commands_id" INTEGER NOT NULL, "payMultipler" REAL NOT NULL, "payPeriod" INTEGER NOT NULL,
    PRIMARY KEY("id"), FOREIGN KEY("commands_id") REFERENCES "roleCommands"("id") ON DELETE
    RESTRICT )
    )";

static const auto CREATE_WAPONS_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "Wapons" ( "id" INTEGER NOT NULL UNIQUE, "name" TEXT NOT NULL, "ammo" INTEGER
    NOT NULL, "price" REAL NOT NULL, "ammoPrice" REAL NOT NULL, "image" BLOB, PRIMARY KEY("id")
    ) WITHOUT ROWID
    )";

static const auto CREATE_OBJECT_TYPE_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "objectType" ( "id" INTEGER NOT NULL UNIQUE, "name" TEXT NOT NULL UNIQUE,
    "price" REAL NOT NULL, PRIMARY KEY("id") )
    )";

static const auto CREATE_ROLE_COMMANDS_TABLE =
    R"(
    CREATE TABLE IF NOT EXISTS "roleCommands" ( "id" INTEGER NOT NULL, "role_id" INTEGER NOT NULL,
    "command_id" INTEGER NOT NULL, FOREIGN KEY("role_id") REFERENCES "Roles"("id") ON DELETE
    RESTRICT, PRIMARY KEY("id","command_id") )
    )";

#endif /* end of include guard: CREATETABLES_HPP_Y3XIBLZH */
