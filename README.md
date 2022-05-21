## TPLAT++

### `tplat::array_join` | <tplat/array_join.hxx>

```cpp
/// joins (concatenates) two `std::array` of the same element type at compile-time

constexpr auto kFoo = std::array{'f','o','o'};
constexpr auto kBar = std::array{'b','a','r'};

constexpr auto kFooBar = 
  tplat::array_join<kFoo, kBar>; /* std::array{'f','o','o','b','a','r'} */
```

### `tplat::array_multijoin` | <tplat/array_multijoin.hxx>

```cpp
/// joins (concatenates) two OR MORE* `std::array` of the same element type at compile-time
/// *up to the compiler limits

constexpr auto kOne = std::array{0,6};
constexpr auto kTwo = std::array{14,1};
constexpr auto kThree = std::array{9,16,22};

constexpr auto kOneTwoThree =
  tplat::array_multijoin<kOne, kTwo, kThree>; /* std::array{0,6,14,1,9,16,22} */
```

### `tplat::array_chars_from_integral` | <tplat/array_chars_from_integral.hxx>

```cpp
/// converts a signed or unsigned integer literal to a non-terminated character
/// string representation, similar to std::to_string, but completely compile-time;
/// also allows the user to set a number base for the conversion

// -199, base-10 -> "-199"
constexpr auto kStr10 = 
  tplat::array_chars_from_integral<-199>; /* std::array{'-','1','9','9'} */

// 32713, base-16 -> "7fc9"
constexpr auto kStr16 = 
  tplat::array_chars_from_integral<32713, 16>; /* std::array{'7','f','c','9'} */

// 105, base-2 -> "1101001"
constexpr auto kStr02 = 
  tplat::array_chars_from_integral<1105, 2>; /* std::array{'1','1','0','1','0','0','1'} */
```

### `tplat::array_from_param_pack` | <tplat/array_from_param_pack.hxx>

```cpp
/// expands any homogeneous parameter pack into an std::array at compile-time

constexpr auto kParams = 
  tplat::array_from_param_pack<std::uint64_t, 0xF, 0xB, 0x3> /* std::array<std::uint64_t, 3>{15,10,3};
```