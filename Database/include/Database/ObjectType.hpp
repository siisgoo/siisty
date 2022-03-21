#ifndef OBJECTTYPE_HPP_DPYEI5TG
#define OBJECTTYPE_HPP_DPYEI5TG

// id, name, base price
#define OBJECT_TYPE_MAP(XX) \
    XX( 0, JOB_ADMIN,         10000 ) \
    XX( 1, JOB_SECURITY,      20000 ) \
    XX( 2, JOB_INKOSOR,       15000 ) \
    XX( 3, JOB_WAPON_MANAGER, 30000 ) \
    XX( 4, JOB_RECRUTER,      20000 ) \
    XX( 5, GUARD_HOUSE,       20000 ) \
    XX( 6, GUARD_OFFICE,      10000 ) \
    XX( 7, INKOS_MONEY,       30000 ) \

#define XX(id, name, price) name = id,
    enum class ObjectType {
        OBJECT_TYPE_MAP(XX)
        COUNT,
    };
#undef XX

#endif /* end of include guard: OBJECTTYPE_HPP_DPYEI5TG */
