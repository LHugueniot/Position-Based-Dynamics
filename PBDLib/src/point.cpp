#include "point.h"


point::point(glm::vec3 _pPos, glm::vec3 _pVel, float _pWeight)
{
    m_pPos= _pPos;
    m_pVel= _pVel;
    m_pWeight= _pWeight;
}

bool point::operator==(const point &p1) const
{
    return (this->m_pPos  == p1.m_pPos ? true : false) &&
           (this->m_pVel  == p1.m_pVel ? true : false) &&
           (this->m_pWeight  == p1.m_pWeight ? true : false);
}
