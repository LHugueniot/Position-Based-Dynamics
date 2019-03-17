#ifndef PBDOBJECT_H
#define PBDOBJECT_H

#include "pbdlib_global.h"
#include "constraint.h"
#include "kernel.h"


//glm maths library
#include <glm/glm.hpp>


namespace LuHu {    //namespace (to be changed)

//using namespace glm;

class PBDLIBSHARED_EXPORT PBDobject
{

public:

    PBDobject();
    ~PBDobject(){}
    bool Initialize(std::string _model, glm::vec3 _originalPos);
    std::vector<std::shared_ptr<constraint>> getConstraints() const;
    std::string m_modelName;
    glm::vec3 m_originalPosition;


private:
    posVector m_facePoints;
    pVector m_pVector;
    std::vector<std::shared_ptr<point>> m_Points;
    std::vector<std::shared_ptr<constraint>> m_Constraints;
};

}
#endif // PBDOBJECT_H
