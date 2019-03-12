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

TEST(PBDobject, initialisefalse)
{
    LuHu::PBDobject hair;

    bool testval=hair.Initialize("model", glm::vec3(0,0,0));

    ASSERT_EQ(hair.m_modelName, "model");
    ASSERT_EQ(hair.m_originalPosition, glm::vec3(0,0,0));
    ASSERT_EQ(testval, false);

//    hair.Initialize("$$(PWD)/models/deCube.obj",glm::vec3(0,0,0));
//    ASSERT_EQ(testval, true);
}

TEST(PBDobject, initialisetrue)
{
    LuHu::PBDobject hair;

    bool testval=hair.Initialize("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj",glm::vec3(0,0,0));
    ASSERT_EQ(testval, false);
}

TEST(Point, defaultctr)
{
    point p(glm::vec3(0,0,0));
}
