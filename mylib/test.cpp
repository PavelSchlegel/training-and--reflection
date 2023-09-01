#include <gtest/gtest.h>
#include <mylib.hpp>

TEST(mylib, check_return_value)
{
    EXPECT_EQ(return_one(), 0);
}
