#ifndef POINT_H
#define POINT_H

#include <glm/glm.hpp>

namespace LuHu {

class point
{
public:
    point(glm::vec3 _pPos, glm::vec3 _pVel, float _pWeight);

    glm::vec3 m_pPos;
    glm::vec3 m_pVel;
    float m_pWeight;
};

}
#endif // POINT_H
