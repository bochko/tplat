#pragma once

#include <array>
#include <string_view>

namespace tplat::t {

template <auto array>
struct array_as_string_view {
    static constexpr auto value = std::string_view{array.begin(), array.end()};
};

}

namespace tplat {

template <auto array>
static constexpr auto array_as_string_view = tplat::t::array_as_string_view<array>::value;

}

