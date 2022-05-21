#pragma once

#include <array>

namespace tplat::t {

template <typename element_type, element_type... args>
struct array_from_param_pack {
    static constexpr auto value = std::array{args...};
};

}

namespace tplat {

template <typename element_type, auto... args>
static constexpr auto array_from_param_pack = 
    tplat::t::array_from_param_pack<element_type, args...>::value;

}