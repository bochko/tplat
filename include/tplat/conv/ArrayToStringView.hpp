#pragma once

#include <array>
#include <string_view>

namespace tplat::conv::impl {

template <auto array>
struct ArrayToStringView {
  static constexpr auto value = std::string_view{array.begin(), array.end()};
};

}  // namespace tplat::conv::impl

namespace tplat::conv {

template <auto array>
static constexpr auto ArrayToStringView = impl::ArrayToStringView<array>::value;

}  // namespace tplat::conv
