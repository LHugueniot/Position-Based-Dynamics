#include <gtest/gtest.h>

#include <PBDLib>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

using namespace LuHu;

std::string modelName="/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/deCube.obj";
//std::string modelName="/home/datlucien/Documents/PP/PPproj/PBDLib/models/deCube.obj";


TEST(gtest, succes)
{
    ASSERT_EQ(0,0);
}


TEST(PBDobject, initialisefalse)
{
    LuHu::PBDobject TestPBD;

    bool testval=TestPBD.Initialize("model",0 ,glm::vec3(0,0,0));

    ASSERT_EQ(TestPBD.getName(), "model");
    ASSERT_EQ(TestPBD.getOriginalPos(), glm::vec3(0,0,0));
    ASSERT_EQ(testval, false);

}

TEST(PBDobject, initialisetrue)
{
    LuHu::PBDobject TestPBD;

    bool testval=TestPBD.Initialize(modelName,0,glm::vec3(0,0,0));

    ASSERT_EQ(TestPBD.getName(), "model");
    ASSERT_EQ(TestPBD.getOriginalPos(), glm::vec3(0,0,0));
    ASSERT_EQ(testval, true);
}

TEST(point, constructorAndgetAndSetMethods)
{
    point a(glm::vec3(0), glm::vec3(0), 1.0f);
    point b(1,0,1209321, 213314, 210940, 41, 1.0f);

    ASSERT_EQ(glm::vec3(0),a.getP());
    ASSERT_EQ(glm::vec3(0), a.getV());
    ASSERT_EQ(glm::vec3(0), a.getTmpPos());
    ASSERT_EQ(1.0f,a.getM());

    ASSERT_EQ(glm::vec3(1,0,1209321),b.getP());
    ASSERT_EQ( glm::vec3(213314, 210940, 41), b.getV());
    ASSERT_EQ(glm::vec3(0), b.getTmpPos());
    ASSERT_EQ(1.0f, b.getM());

    a.setP(glm::vec3(0,0,0));
    a.setV(glm::vec3(0,0,0));
    a.setM(10.0f);
    a.setTmp(glm::vec3(10.0f));

    ASSERT_EQ(glm::vec3(0), a.getP());
    ASSERT_EQ(glm::vec3(0), a.getV());
    ASSERT_EQ(10.0f,a.getM());
    ASSERT_EQ(glm::vec3(10.0f),a.getTmpPos());
}

TEST(kernel, getModel)
{    
    auto test=LuHu::getModel(modelName);
    ASSERT_TRUE(test);
}

TEST(kernel, storePoints)
{
    const aiScene* test=LuHu::getModel(modelName);
    LuHu::posVector a=LuHu::storePoints(test,0);
    for(uint i=0; i<test->mNumMeshes; i++ )
    {
        for(uint j=0; j<test->mMeshes[i]->mNumVertices; j++ )
        {
            ASSERT_EQ(test->mMeshes[i]->mVertices[j].x, a[j].x);
            ASSERT_EQ(test->mMeshes[i]->mVertices[j].y, a[j].y);
            ASSERT_EQ(test->mMeshes[i]->mVertices[j].z, a[j].z);
        }
    }
    for(uint j=0; j<test->mMeshes[0]->mNumVertices; j++ )
    {
        LuHu::printVec3(a[j]);
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

    const aiScene* test=LuHu::getModel(modelName);
    LuHu::posVector b = LuHu::storePoints(test,0);
    auto c = LuHu::posToPoint(b);
    ASSERT_EQ(a,c);

}

TEST(kernel, removeDuplicates)
{
    const aiScene* test=getModel(modelName);

    posVector a =storePoints(test,0);

    posVector b = removeDuplicates(a);

    ASSERT_EQ(b.size(),uint(8));
}

TEST(distanceConstraint, constructor)
{
    auto p1 = point(glm::vec3(0), glm::vec3(0), 1.0f);
    auto p2 = point(glm::vec3(0), glm::vec3(0), 1.0f);
    auto test = new LuHu::distanceConstraint(p1, p2);
    ASSERT_TRUE(test->getPoint(0));
    ASSERT_TRUE(test->getPoint(1));

}

TEST(bendingConstraint, constructor)
{
    auto p1 = point(glm::vec3(0), glm::vec3(0), 1.0f);
    auto p2 = point(glm::vec3(0), glm::vec3(0), 1.0f);
    auto p3 = point(glm::vec3(0), glm::vec3(0), 1.0f);
    auto test = new LuHu::bendingConstraint(p1, p2, p3);
    ASSERT_TRUE(test->getPoint(0));
    ASSERT_TRUE(test->getPoint(1));
    ASSERT_TRUE(test->getPoint(2));
}

TEST(kernel, compare)
{
    ASSERT_TRUE(compare(posVector{glm::vec3(0),glm::vec3(31,10,42)},
                        posVector{glm::vec3(31,10,42), glm::vec3(0)}
                        ));
    ASSERT_TRUE(compare(posVector{glm::vec3(0),glm::vec3(31,10,42)},
                        posVector{ glm::vec3(0), glm::vec3(31,10,42)}
                        ));
    ASSERT_FALSE(compare(posVector{glm::vec3(1),glm::vec3(31,10,42)},
                         posVector{ glm::vec3(0), glm::vec3(31,10,42)}
                         ));
    ASSERT_FALSE(compare(posVector{glm::vec3(0),glm::vec3(31,10,42), glm::vec3(0)},
                         posVector{ glm::vec3(0), glm::vec3(31,10,42)}
                         ));
}

TEST(kernel, getEdge)
{
    LuHu::PBDobject TestPBD;
    TestPBD.Initialize(modelName,0,glm::vec3(0,0,0));
    auto modelPtr=getModel(modelName);

    auto pointTest=storePoints(modelPtr,0);

    auto a =LuHu::getEdges(modelPtr,0,pointTest);
    ASSERT_EQ(a.size(), 18);
}

TEST(kernel, createDistanceConstraints)
{
    const aiScene* test=LuHu::getModel(modelName);

    auto pointTest=storePoints(test,0);
    auto a =LuHu::getEdges(test,0,pointTest);
    posVector b =storePoints(test,0);
    std::vector<std::shared_ptr<point>> pointsPtr;
    auto c=createDistanceConstraints(a,b,pointsPtr);

    ASSERT_EQ(c.size(), 18);
}

TEST(solver, constructor)
{
    solver test(1.0f, glm::vec3(0, -0.98, 0));
    ASSERT_FLOAT_EQ(test.getDamp(), 1.0f);
    ASSERT_EQ(test.getGrav(), glm::vec3(0, -0.98, 0));

    //auto TestPBD = new LuHu::PBDobject();
    LuHu::PBDobject TestPBD;

    TestPBD.Initialize(modelName,0,glm::vec3(0,0,0));

    auto TestPBD1 =std::make_shared<LuHu::PBDobject>(TestPBD);

    test.addPBDobject(TestPBD1);

}
