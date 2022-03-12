#ifndef OBJECTTYPE_HPP_DPYEI5TG
#define OBJECTTYPE_HPP_DPYEI5TG

// id, name, base price
#define OBJECT_TYPE_MAP(XX) \
    XX( 0, JOB_ADMIN,        0 ) \
    XX( 1, JOB_ECURITY,      0 ) \
    XX( 2, JOB_NKOSOR,       0 ) \
    XX( 3, JOB_APON_MANAGER, 0 ) \
    XX( 4, JOB_ECRUTER,      0 ) \
    XX( 5, GUARD_HOUSE,      0 ) \
    XX( 6, GUARD_OFFICE,     0 ) \
    XX( 7, INKOS_MONEY,      0 ) \

#define XX(id, name, price) name = id,
    enum class ObjectType {
        OBJECT_TYPE_MAP(XX)
    };
#undef XX

#endif /* end of include guard: OBJECTTYPE_HPP_DPYEI5TG */
