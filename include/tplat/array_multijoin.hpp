#pragma once

#include <tplat/array_join.hpp>

namespace tplat::impl {

template <auto... array_n>
struct array_multijoin;

template <auto array_0>
struct array_multijoin<array_0> {
  static constexpr auto value = array_0;
};

template <auto array_0, auto array_1>
struct array_multijoin<array_0, array_1> {
  static constexpr auto value = tplat::array_join<array_0, array_1>;
};

template <auto array_0, auto array_1, auto... array_n>
struct array_multijoin<array_0, array_1, array_n...> {
  static constexpr auto value =
      tplat::array_join<tplat::array_join<array_0, array_1>,
                        array_multijoin<array_n...>::value>;
};

}  // namespace tplat::impl

namespace tplat {

template <auto... array_n>
static constexpr auto array_multijoin =
    tplat::impl::array_multijoin<array_n...>::value;

}  // namespace tplat
