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
    LuHu::PBDobject TestPBD;

    bool testval=TestPBD.Initialize("model", glm::vec3(0,0,0));

    ASSERT_EQ(TestPBD.m_modelName, "model");
    ASSERT_EQ(TestPBD.m_originalPosition, glm::vec3(0,0,0));
    ASSERT_EQ(testval, false);

}

TEST(PBDobject, initialisetrue)
{
    LuHu::PBDobject TestPBD;

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

TEST(kernel, getModel)
{    
    auto test=LuHu::getModel("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj");
    ASSERT_TRUE(test);
}

TEST(kernel, storePoints)
{
    const aiScene* test=LuHu::getModel("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj");
    LuHu::posVector a=LuHu::storePoints(test);
    for(int i=0; i<test->mNumMeshes; i++ )
    {
        for(int j=0; j<test->mMeshes[i]->mNumVertices; j++ )
        {
            ASSERT_EQ(test->mMeshes[i]->mVertices[j].x, a[j].x);
            ASSERT_EQ(test->mMeshes[i]->mVertices[j].y, a[j].y);
            ASSERT_EQ(test->mMeshes[i]->mVertices[j].z, a[j].z);
            //std::cout<<"glm::vec3("<<a[j].x<<", "<<a[j].y<<","<<a[j].z<<"),\n";
            std::cout<<"point( glm::vec3("<<a[j].x<<", "<<a[j].y<<","<<a[j].z<<"),glm::vec3(0,0,0), 1.0f ),\n";
        }
    }
}

TEST(point, equal_operator)
{
    point p1(glm::vec3(1,0,1), glm::vec3(10, 100000, 0), 1.0f);
    point p2(glm::vec3(1,0,1), glm::vec3(10, 100000, 0), 1.0f);
    ASSERT_TRUE(p1==p2);
}

TEST(point, posToPoint)
{
    LuHu::pVector a{point( glm::vec3(-0.5, -0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, -0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, 0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, 0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, 0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, 0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, 0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, 0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, 0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, 0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, -0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, -0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, -0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, -0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, -0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, -0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, -0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, -0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, 0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(0.5, 0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, -0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, -0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, 0.5,0.5),glm::vec3(0,0,0), 1.0f ),
                point( glm::vec3(-0.5, 0.5,-0.5),glm::vec3(0,0,0), 1.0f )
                };

    const aiScene* test=LuHu::getModel("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj");
    LuHu::posVector b = LuHu::storePoints(test);
    auto c = LuHu::posToPoint(b);
    ASSERT_EQ(a,c);

}

TEST(kernel, compressPoints)
{
    const aiScene* test=LuHu::getModel("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj");

    LuHu::posVector a =LuHu::storePoints(test);

    LuHu::pVector b =LuHu::compressPoints(a);

    auto c= LuHu::pVector{
            point( glm::vec3(0.5, -0.5,0.5),glm::vec3(0,0,0), 1.0f ),
            point( glm::vec3(0.5, 0.5,0.5),glm::vec3(0,0,0), 1.0f ),
            point( glm::vec3(-0.5, 0.5,0.5),glm::vec3(0,0,0), 1.0f ),
            point( glm::vec3(0.5, 0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
            point( glm::vec3(-0.5, 0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
            point( glm::vec3(0.5, -0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
            point( glm::vec3(-0.5, -0.5,-0.5),glm::vec3(0,0,0), 1.0f ),
            point( glm::vec3(-0.5, -0.5,0.5),glm::vec3(0,0,0), 1.0f )
            };
    ASSERT_EQ(b,c);
}


