#pragma once

#include <array>

namespace tplat::t {
    
    static constexpr auto full_digit_charmap = std::array {
           '0', '1', '2', '3', 
           '4', '5', '6', '7', 
           '8', '9', 'a', 'b', 
           'c', 'd', 'e', 'f'
    };

    template <std::size_t base>
    struct base_n_digit_charmap {
        static constexpr auto value = std::array{full_digit_charmap.begin(), full_digit_charmap.begin() + base};
    };

    using digit = std::int8_t;

    template <digit... digits> struct positive_map_chars_from_integral {
        static constexpr auto value = std::array{full_digit_charmap[digits]...};
    };

    template <digit... digits> struct negative_map_chars_from_integral {
        static constexpr auto value = std::array{'-', (full_digit_charmap[digits])...};
    };

    template <bool negative, 
              digit... digits>
    struct map_chars_from_integral;

    template <digit... digits>
    struct map_chars_from_integral<false, digits...> : positive_map_chars_from_integral<digits...> {};

    template <digit... digits>
    struct map_chars_from_integral<true, digits...> : negative_map_chars_from_integral<digits...> {};

    template <typename integral>
    struct for_integral_type {
        template <bool negative, auto base, integral remainder, digit... digits>
        struct dismember_integral : dismember_integral<negative, base, remainder / base, remainder % base, digits...> {};

        template <bool negative, auto base, digit... digits>
        struct dismember_integral<negative, base, 0, digits...> : map_chars_from_integral<negative, digits...> {};

        template <bool negative, auto base>
        struct dismember_integral<negative, base, 0> : map_chars_from_integral<negative, 0> {};
    };

    template <auto number>
    struct abs_integral {
        static constexpr auto value = ((number < 0) ? -number : number);
    };

    template <auto base, auto min_number_base, auto max_number_base>
    struct constrain_number_base {
        static_assert(base >= min_number_base && base <= max_number_base);
    };

    template <auto number, auto base = 10, typename integral = decltype(number)>
    struct array_chars_from_integral : 
        for_integral_type<integral>::template dismember_integral<(number < integral{0}), base, abs_integral<number>::value>, 
        constrain_number_base<base, 2, 16> {};

}

namespace tplat {
    template <auto number, auto base = 10>
    static constexpr auto array_chars_from_integral = tplat::t::array_chars_from_integral<number, base>::value;
}