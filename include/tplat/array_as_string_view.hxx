#pragma once

#include <array>
#include <string_view>

namespace tplat::t {

template <auto array>
struct array_as_string_view {
  static constexpr auto value = std::string_view{array.begin(), array.end()};
};

template <auto array>
struct array_as_string_view_interface {
  constexpr auto string_view() const noexcept -> std::string_view {
    return tplat::t::array_as_string_view<array>::value;
  }
};

}  // namespace tplat::t

namespace tplat {

template <auto array>
static constexpr auto array_as_string_view =
    tplat::t::array_as_string_view<array>::value;

template <auto array>
static constexpr auto array_as_string_view_interface =
    tplat::t::array_as_string_view_interface<array>{};

}  // namespace tplat
