#ifndef KERNEL_H
#define KERNEL_H

#include "pbdlib_global.h"
#include "point.h"
#include "vec3duo.h"
#include <glm/glm.hpp>

//std lib dependencies
//#include <set>

//Assimp dependencies
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace LuHu {

using posVector = std::vector<glm::vec3>;   //vector comprised solely of positions
using pVector = std::vector<point>;         //vector comprised of point classes
using edgeVector = std::vector<vec3Duo>;

const aiScene* getModel(std::string _model);

posVector storePoints(const aiScene* scene,uint meshIndex);
pVector posToPoint(posVector _pPoints);
bool compare(glm::vec3 temp, posVector bigVec);
posVector removeDuplicates(posVector _pVec);
glm::vec3 aiToGLM(aiVector3D mVertices);
bool compare( posVector bigVec1,  posVector bigVec2);
posVector getConnectedPoints(const aiScene* scene, uint meshIndex);
void printVec3(glm::vec3 _vec);

}
#endif // KERNEL_H
