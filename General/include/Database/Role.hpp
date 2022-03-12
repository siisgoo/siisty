#ifndef ROLE_HPP_TLNRD93C
#define ROLE_HPP_TLNRD93C

#include <QString>

#include "Database/command.hpp"
#include "Database/tables.hpp"

namespace Database {

#define AdminCommands { \
    CommandId::ADD_OBJECT_TYPE,      \
    CommandId::EDIT_OBJECT_TYPE,     \
    CommandId::MAKE_DUTY_SCHEDULE,   \
    CommandId::REGISTER_ACCIDENT,    \
    CommandId::REGISTER_EMPLOYEE,    \
    CommandId::REGISTER_OBJECT_TYPE, \
    CommandId::UPDATE_ROLE,          \
    CommandId::GET_ROLE_DETAILS,     \
    CommandId::GET_OBJECT_DETAILS,   \
    CommandId::GET_DUTY_SCHEDULE,    \
}

#define SecurityCommands { \
    CommandId::PAY_ACCIDENT,         \
    CommandId::GET_ROLE_DETAILS,     \
    CommandId::GET_OBJECT_DETAILS,   \
    CommandId::GET_EMPLOYEE_ENTRY,   \
    CommandId::GET_CUSTOMER_ENTRY,   \
    CommandId::GET_ACCIDENT_DETAILS, \
    CommandId::GET_WAPON_DETAILS,    \
    CommandId::GET_DUTY_SCHEDULE,    \
}

#define InkosorCommands { \
    CommandId::PAY_ACCIDENT,         \
    CommandId::GET_ROLE_DETAILS,     \
    CommandId::GET_OBJECT_DETAILS,   \
    CommandId::GET_EMPLOYEE_ENTRY,   \
    CommandId::GET_CUSTOMER_ENTRY,   \
    CommandId::GET_ACCIDENT_DETAILS, \
    CommandId::GET_WAPON_DETAILS,    \
    CommandId::GET_DUTY_SCHEDULE,    \
}

#define RecruterCommands { \
    CommandId::REGISTER_EMPLOYEE,  \
    CommandId::GET_ROLE_DETAILS,   \
    CommandId::GET_OBJECT_DETAILS, \
    CommandId::GET_EMPLOYEE_ENTRY, \
    CommandId::GET_CUSTOMER_ENTRY, \
    CommandId::GET_DUTY_SCHEDULE,  \
}

#define WaponManagerCommands { \
    CommandId::REGISTER_WAPON,     \
    CommandId::ASSIGN_WAPON,       \
    CommandId::GET_ROLE_DETAILS,   \
    CommandId::GET_OBJECT_DETAILS, \
    CommandId::GET_WAPON_DETAILS,  \
    CommandId::GET_DUTY_SCHEDULE,  \
}

#define CusomerCommands { \
    CommandId::GET_DUTY_SCHEDULE,\
}

// id, name, commands, privilegyID, payMult, payPeriod
// AUTO - only initiated by server logic automaticaly and have all permissions
#define ROLE_MAP(XX) \
    XX( -1, AUTO,         {},                   0,   0  ) \
    XX( 0,  Admin,        AdminCommands,        0.8, 30 ) \
    XX( 1,  Security,     SecurityCommands,     0.5, 30 ) \
    XX( 2,  Inkosor,      InkosorCommands,      0.8, 30 ) \
    XX( 3,  Recruter,     RecruterCommands,     0.8, 30 ) \
    XX( 4,  WaponManager, WaponManagerCommands, 0.5, 30 ) \
    XX( 5,  Customer,     CusomerCommands,      0,   0  ) \

#define XX(id, val, commands, mult, period) val = id,
    enum class RoleId {
        ROLE_MAP(XX)
        ROLES_COUNT
    };
#undef XX

} /* Database  */ 

#endif /* end of include guard: ROLE_HPP_TLNRD93C */
