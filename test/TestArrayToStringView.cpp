#include <gtest/gtest.h>

#include <vector>
#include <array>
#include <string_view>

#include <tplat/conv/ArrayToStringView.hpp>

using std::array;
using std::pair;
using std::string_view;
using std::vector;
using testing::TestWithParam;
using testing::ValuesIn;
using tplat::conv::ArrayToStringView;

static const auto parameters_eq = vector<pair<string_view, string_view>>{
    {ArrayToStringView<array<char, 0>{}>, string_view{""}},
    {ArrayToStringView<array<char, 0>{}>, string_view{"\0"}},
    {ArrayToStringView<array{'*'}>, string_view{"*"}},
    {ArrayToStringView<array{':', ')'}>, string_view{":)"}},
    {ArrayToStringView<array{'-', '-', '>'}>, string_view{"-->"}},
    {ArrayToStringView<array{'h', 'e', 'l', 'l', 'o'}>, string_view{"hello"}}};

static const auto parameters_ne = vector<pair<string_view, string_view>>{
    {ArrayToStringView<array{'!'}>, string_view{""}}};

struct test_array_as_string_view_EQ
    : public TestWithParam<decltype(parameters_eq)::value_type> {};

struct test_array_as_string_view_NE
    : public TestWithParam<decltype(parameters_ne)::value_type> {};

INSTANTIATE_TEST_SUITE_P(tplat, test_array_as_string_view_EQ,
                         ValuesIn(parameters_eq));

INSTANTIATE_TEST_SUITE_P(tplat, test_array_as_string_view_NE,
                         ValuesIn(parameters_ne));

TEST_P(test_array_as_string_view_EQ, expr_equival) {
  EXPECT_EQ(GetParam().first, GetParam().second);
}

TEST_P(test_array_as_string_view_NE, expr_equival) {
  EXPECT_NE(GetParam().first, GetParam().second);
}