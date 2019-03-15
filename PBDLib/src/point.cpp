#include "point.h"

namespace LuHu{

point::point(glm::vec3 _pPos, glm::vec3 _pVel, float _pWeight) :
    m_pPos(_pPos),
    m_pVel(_pVel),
    m_pWeight(_pWeight)
{}

point::point(float _Px, float _Py, float _Pz, float _Vx, float _Vy, float _Vz, float _pWeight) :
    m_pPos(glm::vec3(_Px, _Py, _Pz)),
    m_pVel(glm::vec3(_Vx,_Vy,_Vz)),
    m_pWeight(_pWeight)
{}

bool point::operator==(const point &p1) const
{
    return (this->m_pPos  == p1.m_pPos ? true : false) &&
            (this->m_pVel  == p1.m_pVel ? true : false) &&
            (this->m_pWeight  == p1.m_pWeight ? true : false);
}

glm::vec3 point::getP() const
{
    return m_pPos;
}

glm::vec3 point::getV() const
{
    return m_pVel;
}

float point::getW() const
{
    return m_pWeight;
}

void point::setP(glm::vec3 _pPos)
{
    this->m_pPos=_pPos;
}
void point::setV(glm::vec3 _pVel)
{
    this->m_pVel=_pVel;
}
void point::setW(float _pWeight)
{
    this->m_pWeight=_pWeight;
}

}
