#include "point.h"


point::point(glm::vec3 _pPos, glm::vec3 _pVel, float _pWeight)
{
    m_pPos= _pPos;
    m_pVel= _pVel;
    m_pWeight= _pWeight;
}
