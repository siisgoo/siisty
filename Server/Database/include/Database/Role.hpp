#ifndef ROLE_HPP_TLNRD93C
#define ROLE_HPP_TLNRD93C

#include <QString>

#define ROLE_MAP(XX) \
    XX( 0, Admin     ) \
    XX( 1, Secrutity ) \
    XX( 2, Inkosor   ) \
    XX( 3, Recruter  ) \
    XX( 4, Customer  ) \

namespace Database {

#define XX(num, val) val = num,
    enum class Roles {
        ROLE_MAP(XX)
    };
#undef XX

} /* Database  */ 

#endif /* end of include guard: ROLE_HPP_TLNRD93C */
