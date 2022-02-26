#ifndef TABLES_MAP_HPP_ZF6KNP58
#define TABLES_MAP_HPP_ZF6KNP58

#include "Database/Query.hpp"

#define TABLES_MAP(XX)                                                  \
    XX(  0, GuiltyEmployees,       CREATE_GUILTYEMPLOYEES_TABLE )       \
    XX(  1, Accidents,             CREATE_ACCIDENTS_TABLE )             \
    XX(  2, Accounting,            CREATE_ACCOUNTING_TABLE )            \
    XX(  3, AccignedEmployees,     CREATE_ASSIGNEDEMPLOYEES_TABLE )     \
    XX(  4, Contracts,             CREATE_CONTRACTS_TABLE )             \
    XX(  5, DutySchedule,          CREATE_DUTYSCHEDULE_TABLE )          \
    XX(  6, EmployeesAndCustomers, CREATE_EMPLOYEESANDCUSTOMERS_TABLE ) \
    XX(  7, RoleAccessableObject,  CREATE_ROLEACCESSABLEOBJECT_TABLE )  \
    XX(  8, Role,                  CREATE_ROLES_TABLE )                 \
    XX(  9, Wapons,                CREATE_WAPONS_TABLE )                \
    XX( 10, objectType,            CREATE_OBJECTYPE_TABLE )             \

#endif /* end of include guard: TABLES_MAP_HPP_ZF6KNP58 */
