#include <iostream>

#include <tplat/array_join.hxx>
#include <tplat/array_multijoin.hxx>

int main(int argc, char **argv){
    static constexpr auto test_array_join = 
        tplat::array_join<std::array{'a', 'b'}, std::array{'c', 'd'}>;
    static constexpr auto test_array_multijoin = 
        tplat::array_multijoin<std::array{'a', 'b'}, std::array{'c', 'd'}, std::array{'e', 'f'}>;
}
