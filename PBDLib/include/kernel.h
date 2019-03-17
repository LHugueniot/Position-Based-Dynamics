#ifndef KERNEL_H
#define KERNEL_H

#include "pbdlib_global.h"
#include "point.h"
#include "indexDuo.h"
#include "constraint.h"
#include <glm/glm.hpp>

//std lib dependencies
//#include <set>

//Assimp dependencies
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace LuHu {

//class vec3Face
//{
//public:
//    vec3Face(glm::vec3 _p1, glm::vec3 _p2, glm::vec3 _p3):
//        m_p1(_p1), m_p2(_p2), m_p3(_p3)
//    {}

//    glm::vec3 m_p1;
//    glm::vec3 m_p2;
//    glm::vec3 m_p3;
//};

class vec3Face
{
public:
    vec3Face(int _p1, int _p2, int _p3):
        m_p1(_p1), m_p2(_p2), m_p3(_p3)
    {}

    int m_p1;
    int m_p2;
    int m_p3;
};

using posVector = std::vector<glm::vec3>;   //vector comprised solely of positions
using pVector = std::vector<point>;         //vector comprised of point classes
using edgeVector = std::vector<indexDuo>;
using conVector =std::vector<constraint>;
using faceVec =std::vector<vec3Face>;

const aiScene* getModel(std::string _model);

posVector storePoints(const aiScene* scene,uint meshIndex);

pVector posToPoint(posVector _pPoints);

bool compare(glm::vec3 temp, posVector bigVec);
bool compare( posVector bigVec1,  posVector bigVec2);

posVector removeDuplicates(posVector _pVec);
glm::vec3 aiToGLM(aiVector3D mVertices);

void printVec3(glm::vec3 _vec);

std::vector<indexDuo> getEdges(const aiScene* scene,uint meshIndex);
std::vector<std::shared_ptr<constraint>> createDistanceConstraints(std::vector<indexDuo> edges,
                                                  std::vector<glm::vec3> vertices,
                                                  std::vector<std::shared_ptr<point> > &pointVector);

}
#endif // KERNEL_H
