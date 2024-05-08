#include <iostream>
#include "gtest/gtest.h"
#include "string.h"

TEST(StringTest, Constructor)
{
    String s1(" и я - студент C++.");
    EXPECT_EQ(s1.length(), 27);
    EXPECT_STREQ(s1.str, " и я - студент C++.");
}

TEST(StringTest, OperatorPlus)
{
    String s1(" снова ");
    String s2(" студент ");
    String s3 = s1 + s2;
    EXPECT_EQ(s3.length(), 35);
    EXPECT_STREQ(s3.str, " снова студент ");
}

TEST(StringTest, OperatorAssign)
{
    String s1(" снова ");
    String s2 = s1;
    EXPECT_EQ(s2.length(), 9);
    EXPECT_STREQ(s2.str, " снова ");
}

TEST(StringTest, StringUp)
{
    String s1(" снова ");
    s1.stringup();
    EXPECT_EQ(s1.length(), 9);
    EXPECT_STREQ(s1.str, " СНАДУ ");
}

TEST(StringTest, StringLow)
{
    String s1(" СНАДУ ");
    s1.stringlow();
    EXPECT_EQ(s1.length(), 9);
    EXPECT_STREQ(s1.str, " снова ");
}

TEST(StringTest, Has)
{
    String s1(" снова ");
    EXPECT_EQ(s1.has('а'), true);
    EXPECT_EQ(s1.has('A'), false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
