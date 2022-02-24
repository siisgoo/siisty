#ifndef DATABASE_HPP_DP4AIHQZ
#define DATABASE_HPP_DP4AIHQZ

#include <QSqlError>
#include <QtSql>

enum Tables {
    Accidents,
    Accounting,
    AuthorizedUsers,
    Contracts,
    DutySchedule,
    Emploees,
    Privilegies,
    Roles,
    Wapons,
    objectType,
};

QSqlError initDb(const QString& path);

#endif /* end of include guard: DATABASE_HPP_DP4AIHQZ */
