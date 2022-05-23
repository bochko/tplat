#include <gtest/gtest.h>

#include <tplat/array_as_string_view.hxx>
#include <vector>

static const auto parameters_eq =
    std::vector<std::pair<std::string_view, std::string_view>>{
        {tplat::array_as_string_view<std::array<char, 0>{}>,
         std::string_view{""}},
        {tplat::array_as_string_view<std::array<char, 0>{}>,
         std::string_view{"\0"}},
        {tplat::array_as_string_view<std::array{'*'}>, std::string_view{"*"}},
        {tplat::array_as_string_view<std::array{':', ')'}>,
         std::string_view{":)"}},
        {tplat::array_as_string_view<std::array{'-', '-', '>'}>,
         std::string_view{"-->"}},
        {tplat::array_as_string_view<std::array{'h', 'e', 'l', 'l', 'o', ' ',
                                                'w', 'o', 'r', 'l', 'd'}>,
         std::string_view{"hello world"}}};

static const auto parameters_ne =
    std::vector<std::pair<std::string_view, std::string_view>>{
        {tplat::array_as_string_view<std::array{'!'}>, std::string_view{""}}};

struct test_array_as_string_view_EQ
    : public testing::TestWithParam<decltype(parameters_eq)::value_type> {};

struct test_array_as_string_view_NE
    : public testing::TestWithParam<decltype(parameters_ne)::value_type> {};

INSTANTIATE_TEST_SUITE_P(tplat, test_array_as_string_view_EQ,
                         testing::ValuesIn(parameters_eq));

INSTANTIATE_TEST_SUITE_P(tplat, test_array_as_string_view_NE,
                         testing::ValuesIn(parameters_ne));

TEST_P(test_array_as_string_view_EQ, expr_equival) {
  EXPECT_EQ(GetParam().first, GetParam().second);
}

TEST_P(test_array_as_string_view_NE, expr_equival) {
  EXPECT_NE(GetParam().first, GetParam().second);
}