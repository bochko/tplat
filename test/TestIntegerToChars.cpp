#include <gtest/gtest.h>

#include <cstdint>
#include <limits>

#include <tplat/conv/ArrayToStringView.hpp>
#include <tplat/conv/IntegerToChars.hpp>

using tplat::conv::IntegerToChars;
using tplat::conv::ArrayToStringView;
using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::numeric_limits;


TEST(test_IntegerToChars_EQ, std_int8_t_base10) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{0}>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{
                 numeric_limits<int8_t>::max()}>>),
            "127");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{47}>>), "47");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{91}>>), "91");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{-101}>>), "-101");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{-4}>>), "-4");
}

TEST(test_IntegerToChars_EQ, std_int8_t_base16) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{0}, 16>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<
                 int8_t{numeric_limits<int8_t>::max()}, 16>>),
            "7f");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{69}, 16>>), "45");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{77}, 16>>), "4d");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{-123}, 16>>), "-7b");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{-4}, 16>>), "-4");
}

TEST(test_IntegerToChars_EQ, std_int8_t_base8) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{0}, 8>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<
                 int8_t{numeric_limits<int8_t>::max()}, 8>>),
            "177");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{69}, 8>>), "105");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{77}, 8>>), "115");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{-123}, 8>>), "-173");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{-4}, 8>>), "-4");
}

TEST(test_IntegerToChars_EQ, std_int8_t_base2) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{0}, 2>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<
                 int8_t{numeric_limits<int8_t>::max()}, 2>>),
            "1111111");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{69}, 2>>), "1000101");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{77}, 2>>), "1001101");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{-123}, 2>>),
            "-1111011");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int8_t{-4}, 2>>), "-100");
}

TEST(test_IntegerToChars_EQ, std_int16_t_base10) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{0}>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{19900}>>), "19900");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{4388}>>), "4388");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{-9903}>>), "-9903");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{-31044}>>),
            "-31044");
}

TEST(test_IntegerToChars_EQ, std_int16_t_base16) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{0}, 16>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{19900}, 16>>),
            "4dbc");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{4388}, 16>>),
            "1124");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{-9903}, 16>>),
            "-26af");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{-31044}, 16>>),
            "-7944");
}

TEST(test_IntegerToChars_EQ, std_int16_t_base8) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{0}, 8>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{19900}, 8>>),
            "46674");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{4388}, 8>>),
            "10444");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{-9903}, 8>>),
            "-23257");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{-31044}, 8>>),
            "-74504");
}

TEST(test_IntegerToChars_EQ, std_int16_t_base2) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{0}, 2>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{19900}, 2>>),
            "100110110111100");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{4388}, 2>>),
            "1000100100100");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{-9903}, 2>>),
            "-10011010101111");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int16_t{-31044}, 2>>),
            "-111100101000100");
}

TEST(test_IntegerToChars_EQ, std_int32_t_base10) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{0}>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{774891}>>),
            "774891");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{163333}>>),
            "163333");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{-256001}>>),
            "-256001");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{-1414097}>>),
            "-1414097");
}

TEST(test_IntegerToChars_EQ, std_int32_t_base16) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{0}, 16>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{774891}, 16>>),
            "bd2eb");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{163333}, 16>>),
            "27e05");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{-256001}, 16>>),
            "-3e801");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{-1414097}, 16>>),
            "-1593d1");
}

TEST(test_IntegerToChars_EQ, std_int32_t_base8) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{0}, 8>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{774891}, 8>>),
            "2751353");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{163333}, 8>>),
            "477005");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{-256001}, 8>>),
            "-764001");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{-1414097}, 8>>),
            "-5311721");
}

TEST(test_IntegerToChars_EQ, std_int32_t_base2) {
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{0}, 2>>), "0");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{774891}, 2>>),
            "10111101001011101011");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{163333}, 2>>),
            "100111111000000101");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{-256001}, 2>>),
            "-111110100000000001");
  EXPECT_EQ((ArrayToStringView<IntegerToChars<int32_t{-1414097}, 2>>),
            "-101011001001111010001");
}