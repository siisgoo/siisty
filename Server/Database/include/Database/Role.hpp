#ifndef ROLE_HPP_TLNRD93C
#define ROLE_HPP_TLNRD93C

#include "Database/tables_map.hpp"
#include <QString>

/*
 * default privilegies and roles
 */

#define SECURITY_PRIV(XX) \
    XX( Operation::READ || Operation::WRITE,  "", "") \

// id, name, privilegyID, payMult, payPeriod
#define ROLE_MAP(XX) \
    XX( 0, Admin,        0, 0.8, 30 ) \
    XX( 1, Security,     0, 0.5, 30 ) \
    XX( 2, Inkosor,      0, 0.8, 30 ) \
    XX( 3, Recruter,     0, 0.8, 30 ) \
    XX( 4, WaponManager, 0, 0.5, 0  ) \
    XX( 5, Customer,     0, 0,   0  ) \

namespace Database {

enum class Operation : uint {
    READ  = 0x1,
    WRITE = 0x2,
};

#define XX(id, val, priv, mult, period) val = id,
    enum class Roles {
        ROLE_MAP(XX)
    };
#undef XX

} /* Database  */ 

#endif /* end of include guard: ROLE_HPP_TLNRD93C */
