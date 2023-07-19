#include <iostream>
#include <tplat/array_join.hpp>
#include <tplat/array_multijoin.hpp>
#include <tplat/conv/ArrayToStringView.hpp>
#include <tplat/conv/IntegerToChars.hpp>
#include <tplat/conv/ParameterPackToArray.hpp>

using std::array;
using std::cout;
using std::endl;
using std::string_view;
using tplat::array_join;
using tplat::array_multijoin;
using tplat::conv::ArrayToStringView;
using tplat::conv::IntegerToChars;
using tplat::conv::ParameterPackToArray;

template <auto array>
void print(string_view msg) {
  cout << msg << " ~~> " << string_view{array.begin(), array.end()} << endl;
}

template <unsigned code>
static constexpr auto ansi_3bit = ArrayToStringView<
    array_multijoin<ParameterPackToArray<char, '\x1b', '['>,
                    IntegerToChars<code>, ParameterPackToArray<char, 'm'>>>;

static constexpr auto red = ansi_3bit<31>;

int main(int argc, char **argv) {
  print<array_join<array{'a', 'b'}, array{'c', 'd'}>>("array_join");
  print<array_multijoin<array{'a', 'b'}, array{'c', 'd'}, array{'e', 'f'}>>(
      "array_multijoin");
  print<IntegerToChars<9931>>("IntegerToChars (positive)");
  print<IntegerToChars<-140071>>("IntegerToChars (negative)");
  print<IntegerToChars<0>>("IntegerToChars (zero)");
  print<IntegerToChars<9931, 2>>("IntegerToChars (positive, base-2)");
  print<IntegerToChars<-140071, 2>>("IntegerToChars (negative, base-2)");
  print<IntegerToChars<0, 2>>("IntegerToChars (zero, base-2)");
  print<IntegerToChars<9931, 16>>("IntegerToChars (positive, base-16)");
  print<IntegerToChars<-140071, 16>>("IntegerToChars (negative, base-16)");
  print<IntegerToChars<0, 16>>("IntegerToChars (zero, base-16)");

  static constexpr auto test_array_join =
      array_join<array{'a', 'b'}, array{'c', 'd'}>;

  static constexpr auto test_array_multijoin =
      array_multijoin<array{'a', 'b'}, array{'c', 'd'}, array{'e', 'f'}>;

  static constexpr auto test_pos_IntegerToChars = IntegerToChars<9931>;

  static constexpr auto test_neg_IntegerToChars = IntegerToChars<-140071>;

  static constexpr auto sv_neg_array =
      ArrayToStringView<test_neg_IntegerToChars>;
  cout << red << sv_neg_array << endl;

  static constexpr auto test_zero_IntegerToChars = IntegerToChars<0>;

  static constexpr auto test_array_from_param_pack =
      ParameterPackToArray<int64_t, 1, 2, 3, 4>;
}
