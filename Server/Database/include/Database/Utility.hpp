#ifndef UTILITY_HPP_H9ZYO2LK
#define UTILITY_HPP_H9ZYO2LK

#include <array>
#include <QVector>

namespace Database {

    const auto TABLE_ARRAY_SEPARATOR = R"(:)";

    enum class Weekdays {
        Mondey,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday,
    };

    /* using Week = Weekdays[7]; */
    using Week = std::array<Weekdays, 7>;

    // presets
    struct Weekends {
        static Week five_on_two; //{Weekdays::Saturday, Weekdays::Sunday};
    };

} /* Database  */ 


#endif /* end of include guard: UTILITY_HPP_H9ZYO2LK */
