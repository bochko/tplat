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
        template <bool negative, integral remainder, digit... digits>
        struct dismember_integral : dismember_integral<negative, remainder / 10, remainder % 10, digits...> {};

        template <bool negative, digit... digits>
        struct dismember_integral<negative, 0, digits...> : map_chars_from_integral<negative, digits...> {};

        template <bool negative>
        struct dismember_integral<negative, 0> : map_chars_from_integral<negative, 0> {};
    };

    template <auto number>
    struct abs_integral {
        static constexpr auto value = ((number < 0) ? -number : number);
    };

    template <auto number, auto base = 10, typename integral = decltype(number)>
    struct array_chars_from_integral : for_integral_type<integral>::template dismember_integral<(number < integral{0}), abs_integral<number>::value> {};

}

namespace tplat {
    template <auto number, auto base = 10>
    static constexpr auto array_chars_from_integral = tplat::t::array_chars_from_integral<number, base>::value;
}

// namespace detail
// {
//     template<uint8_t... digits> struct positive_to_chars { static const char value[]; };
//     template<uint8_t... digits> constexpr char positive_to_chars<digits...>::value[] = {('0' + digits)..., 0};

//     template<uint8_t... digits> struct negative_to_chars { static const char value[]; };
//     template<uint8_t... digits> constexpr char negative_to_chars<digits...>::value[] = {'-', ('0' + digits)..., 0};

//     template<bool neg, uint8_t... digits>
//     struct to_chars : positive_to_chars<digits...> {};

//     template<uint8_t... digits>
//     struct to_chars<true, digits...> : negative_to_chars<digits...> {};

//     template<bool neg, uintmax_t rem, uint8_t... digits>
//     struct explode : explode<neg, rem / 10, rem % 10, digits...> {};

//     template<bool neg, uint8_t... digits>
//     struct explode<neg, 0, digits...> : to_chars<neg, digits...> {};

//     template<typename T>
//     constexpr uintmax_t cabs(T num) { return (num < 0) ? -num : num; }
// }

// template<typename Integer, Integer num>
// struct string_from : detail::explode<(num < 0), detail::cabs(num)> {};