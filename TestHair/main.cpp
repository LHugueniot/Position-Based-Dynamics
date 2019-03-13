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

    //bool testval=hair.Initialize("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj",glm::vec3(0,0,0));
    bool testval=hair.Initialize("/home/datlucien/Documents/PP/PPproj/PBDLib/models/deCube.obj",glm::vec3(0,0,0));
    ASSERT_EQ(testval, true);
}

TEST(Point, defaultctr)
{
    LuHu::point p(glm::vec3(0,0,0), glm::vec3(0,0,0), 1.0f);
    ASSERT_EQ(p.m_pPos,glm::vec3(0,0,0));
    ASSERT_EQ(p.m_pVel,glm::vec3(0,0,0));
    ASSERT_EQ(p.m_pWeight, 1.0f);
}

TEST(PBDobject, storePoints)
{

}




