#ifndef TABLES_HPP_URXDMEZB
#define TABLES_HPP_URXDMEZB

#include "Database/tables_map.hpp"

#include <QMap>
#include <QString>
#include <QDate>

namespace Database {

#define Q(x) #x
#define QUOTE(x) Q(x)

#define XX(num, name, query) name = num,
    enum class Tables : int {
        TABLES_MAP(XX)
        TablesCount
    };
#undef XX

} /* Database  */

#endif /* end of include guard: TABLES_HPP_URXDMEZB */
