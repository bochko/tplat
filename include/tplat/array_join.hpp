#pragma once

#include <array>

namespace tplat::impl {

template <auto... size>
using iseq = std::index_sequence<size...>;
template <auto size>
using make_iseq = std::make_index_sequence<size>;

template <auto array_lhs, auto array_rhs,
          typename iseq_lhs = make_iseq<array_lhs.size()>,
          typename iseq_rhs = make_iseq<array_rhs.size()>>
struct array_join;

template <auto array_lhs, auto array_rhs, std::size_t... idxs_lhs,
          std::size_t... idxs_rhs>
struct array_join<array_lhs, array_rhs, iseq<idxs_lhs...>, iseq<idxs_rhs...>> {
  static constexpr auto value =
      std::array{array_lhs[idxs_lhs]..., array_rhs[idxs_rhs]...};
};

}  // namespace tplat::impl

namespace tplat {

template <auto array_lhs, auto array_rhs>
static constexpr auto array_join =
    tplat::impl::array_join<array_lhs, array_rhs>::value;

}  // namespace tplat
