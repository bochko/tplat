#include <iostream>

#include <tplat/array_join.hxx>
#include <tplat/array_multijoin.hxx>
#include <tplat/array_chars_from_integral.hxx>
#include <tplat/array_from_param_pack.hxx>

template <auto array>
void print(std::string_view msg) {
    std::cout << msg << " ~~> " << std::string_view{array.begin(), array.end()} << std::endl;
}

int main(int argc, char **argv){

    print<tplat::array_join<std::array{'a', 'b'}, std::array{'c', 'd'}>>("tplat::array_join");
    print<tplat::array_multijoin<std::array{'a', 'b'}, std::array{'c', 'd'}, std::array{'e', 'f'}>>("tplat::array_multijoin");
    print<tplat::array_chars_from_integral<9931>>("tplat::array_chars_from_integral (positive)");
    print<tplat::array_chars_from_integral<-140071>>("tplat::array_chars_from_integral (negative)");
    print<tplat::array_chars_from_integral<0>>("tplat::array_chars_from_integral (zero)");
    print<tplat::array_chars_from_integral<9931, 2>>("tplat::array_chars_from_integral (positive, base-2)");
    print<tplat::array_chars_from_integral<-140071, 2>>("tplat::array_chars_from_integral (negative, base-2)");
    print<tplat::array_chars_from_integral<0, 2>>("tplat::array_chars_from_integral (zero, base-2)");
    print<tplat::array_chars_from_integral<9931, 16>>("tplat::array_chars_from_integral (positive, base-16)");
    print<tplat::array_chars_from_integral<-140071, 16>>("tplat::array_chars_from_integral (negative, base-16)");
    print<tplat::array_chars_from_integral<0, 16>>("tplat::array_chars_from_integral (zero, base-16)");

    static constexpr auto test_array_join = 
        tplat::array_join<std::array{'a', 'b'}, std::array{'c', 'd'}>;

    static constexpr auto test_array_multijoin = 
        tplat::array_multijoin<std::array{'a', 'b'}, std::array{'c', 'd'}, std::array{'e', 'f'}>;

    static constexpr auto test_pos_array_chars_from_integral =
        tplat::array_chars_from_integral<9931>;

    static constexpr auto test_neg_array_chars_from_integral =
        tplat::array_chars_from_integral<-140071>;

    static constexpr auto test_zero_array_chars_from_integral = 
        tplat::array_chars_from_integral<0>;

    static constexpr auto test_array_from_param_pack = 
        tplat::array_from_param_pack<std::int64_t, 1, 2, 3, 4>;

}
