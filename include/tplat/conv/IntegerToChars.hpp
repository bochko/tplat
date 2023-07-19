#pragma once

#include <array>
#include <cstdint>

namespace tplat::conv::impl {

static constexpr auto kDigitCharmap =
    std::array{'0', '1', '2', '3', '4', '5', '6', '7',
               '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

template <std::size_t base>
struct CharmapForNumericBase {
  static constexpr auto value =
      std::array{kDigitCharmap.begin(), kDigitCharmap.begin() + base};
};

using Digit = std::int8_t;

template <Digit... digits>
struct DigitsToCharsFromPositive {
  static constexpr auto value = std::array{kDigitCharmap[digits]...};
};

template <Digit... digits>
struct DigitsToCharsFromNegative {
  static constexpr auto value = std::array{'-', (kDigitCharmap[digits])...};
};

template <bool negative, Digit... digits>
struct DigitsToChars;

template <Digit... digits>
struct DigitsToChars<false, digits...> : DigitsToCharsFromPositive<digits...> {
};

template <Digit... digits>
struct DigitsToChars<true, digits...> : DigitsToCharsFromNegative<digits...> {};

template <typename IntegerType>
struct ForIntegerType {
  template <bool negative, auto base, IntegerType remainder, Digit... digits>
  struct GetDigits : GetDigits<negative, base, remainder / base,
                               remainder % base, digits...> {};

  template <bool negative, auto base, Digit... digits>
  struct GetDigits<negative, base, 0, digits...>
      : DigitsToChars<negative, digits...> {};

  template <bool negative, auto base>
  struct GetDigits<negative, base, 0> : DigitsToChars<negative, 0> {};
};

template <auto number>
struct AbsVal {
  static constexpr auto value = ((number < 0) ? -number : number);
};

template <auto base, auto min_number_base, auto max_number_base>
struct ValidNumericBaseRange {
  static_assert(base >= min_number_base && base <= max_number_base);
};

template <auto number, auto base = 10, typename IntegerType = decltype(number)>
struct IntegerToChars
    : ForIntegerType<IntegerType>::template GetDigits<
          (number < IntegerType{0}), base, AbsVal<number>::value>,
      ValidNumericBaseRange<base, 2, 16> {};

}  // namespace tplat::conv::impl

namespace tplat::conv {

template <auto number, auto base = 10>
static constexpr auto IntegerToChars =
    impl::IntegerToChars<number, base>::value;

}  // namespace tplat::conv