#include <gtest/gtest.h>
#include <PBDLib>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(gtest, succes)
{
    ASSERT_EQ(0,0);
}

TEST(gtest, fail)
{
    ASSERT_EQ(0,0);
}

TEST(PBDLib, default_ctr)
{
    PBDobj hair(10);
    EXPECT_EQ(10,hair.m_numStrands);
}
