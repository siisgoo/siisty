#ifndef ACCOUNTING_HPP_AGFHDO9N
#define ACCOUNTING_HPP_AGFHDO9N

#define ACCOUNTING_TYPE_MAP(XX) \
    XX( 0, Contract ) \
    XX( 1, Accident ) \
    XX( 2, Employee )

namespace Database {
#define XX(id, name) ACC_ ##name = id,
    enum AccountingType {
        ACCOUNTING_TYPE_MAP(XX)
        ACC_COUNT
    };
#undef XX
}

#endif /* end of include guard: ACCOUNTING_HPP_AGFHDO9N */
