#ifndef TABLES_MAP_HPP_ZF6KNP58
#define TABLES_MAP_HPP_ZF6KNP58

#include "Database/Query.hpp"

#define TABLES_MAP(XX)\
    XX( 0, Accidents,             CREATE_ACCIDENTS_TABLE )             \
    XX( 1, Accounting,            CREATE_ACCOUNTING_TABLE )            \
    XX( 2, Contracts,             CREATE_CONTRACTS_TABLE )             \
    XX( 3, DutySchedule,          CREATE_DUTYSCHEDULE_TABLE )          \
    XX( 4, EmployeesAndCustomers, CREATE_EMPLOYEESANDCUSTOMERS_TABLE ) \
    XX( 5, Privilegies,           CREATE_PRIVILEGIES_TABLE )           \
    XX( 6, Role,                  CREATE_ROLES_TABLE )                 \
    XX( 7, Wapons,                CREATE_WAPONS_TABLE )                \
    XX( 8, objectType,            CREATE_OBJECTYPE_TABLE )             \

#endif /* end of include guard: TABLES_MAP_HPP_ZF6KNP58 */
