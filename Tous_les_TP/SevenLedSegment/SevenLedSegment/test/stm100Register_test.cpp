#include <stdlib.h>

#include "gtest/gtest.h"

extern "C" {
    #include "../STMF100RegisterConfiguration.h"
}


TEST(STMF100Register, dummy) {
    EXPECT_EQ(get_APB2EN_register(GPIOA), 2);
    ASSERT_TRUE(true);
}

TEST(STMF100Register, STMF100Register_NULL) {
    EXPECT_EQ(get_APB2EN_register(NULL), NULL);
    ASSERT_TRUE(true);
}

class get_APB2EN_registerTest : public ::testing::TestWithParam<std::tuple<GPIO_TypeDef*, int >> {};
TEST_P(get_APB2EN_registerTest, get_APB2EN_register_test) {
    GPIO_TypeDef* gpio_register = std::get<0>(GetParam());
    int offset = std::get<1>(GetParam());
   
    uint8_t result = get_APB2EN_register(gpio_register);
    EXPECT_EQ(offset, result);
}

INSTANTIATE_TEST_SUITE_P(
    get_APB2EN_registerTests, get_APB2EN_registerTest,
    ::testing::Values(
        std::make_tuple(GPIOA, 2),
        std::make_tuple(GPIOB, 3),
        std::make_tuple(GPIOC, 4),
        std::make_tuple(GPIOD, 5),
        std::make_tuple(GPIOE, 6)
    )
);