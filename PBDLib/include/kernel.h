#ifndef KERNEL_H
#define KERNEL_H

#include "pbdlib_global.h"
#include "point.h"
#include <glm/glm.hpp>

//std lib dependencies
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

//Assimp dependencies
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace LuHu {

using posVector = std::vector<glm::vec3>;   //vector comprised solely of positions
using pVector = std::vector<point>;         //vector comprised of point classes

const aiScene* getModel(std::string _model);

posVector storePoints(const aiScene* scene);
pVector posToPoint(posVector _pPoints);
pVector compressPoints(posVector _pVec);

}
#endif // KERNEL_H
