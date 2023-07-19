#pragma once

#include <array>

namespace tplat::conv::impl {

template <typename element_type, element_type... args>
struct ParameterPackToArray {
  static constexpr auto value = std::array{args...};
};

}  // namespace tplat::conv::impl

namespace tplat::conv {

template <typename element_type, auto... args>
static constexpr auto ParameterPackToArray =
    impl::ParameterPackToArray<element_type, args...>::value;

}  // namespace tplat::conv
