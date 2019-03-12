#ifndef PBDOBJECT_H
#define PBDOBJECT_H

#include "pbdlib_global.h"
#include "point.h"
#include <iostream>
#include <string>
#include <array>

#include <glm/glm.hpp>

namespace LuHu {

//using namespace glm;

class PBDLIBSHARED_EXPORT PBDobject
{

public:

    PBDobject();
    ~PBDobject(){}
    bool Initialize(std::string _model, glm::vec3 _originalPos);
    std::string m_modelName;
    uint m_numStrands;
    glm::vec3 m_originalPosition;
};

}
#endif // PBDOBJECT_H
