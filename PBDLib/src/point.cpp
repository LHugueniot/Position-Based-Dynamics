#include "point.h"

namespace LuHu{

point::point(glm::vec3 _pPos, glm::vec3 _pVel, float _pMass) :
    m_pPos(_pPos),
    m_pVel(_pVel),
    m_pMass(_pMass),
    m_pinvMass(1/_pMass),
    tmp_pos(glm::vec3(0))
{}

point::point(float _Px, float _Py, float _Pz, float _Vx, float _Vy, float _Vz, float _pMass) :
    m_pPos(glm::vec3(_Px, _Py, _Pz)),
    m_pVel(glm::vec3(_Vx,_Vy,_Vz)),
    m_pMass(_pMass),
    m_pinvMass(1/_pMass),
    tmp_pos(glm::vec3(0))
{}

bool point::operator==(const point &p1) const
{
    return (this->m_pPos  == p1.m_pPos ? true : false) &&
            (this->m_pVel  == p1.m_pVel ? true : false) &&
            (this->tmp_pos  == p1.tmp_pos ? true : false) &&
            (this->m_pinvMass  == p1.m_pinvMass ? true : false);
}

//--------------------------get functions-------------------

glm::vec3 point::getP() const
{
    return m_pPos;
}

glm::vec3 point::getV() const
{
    return m_pVel;
}

glm::vec3 point::getTmpPos() const
{
    return tmp_pos;
}

float point::getM() const
{
    return m_pMass;
}

float point::getIM() const
{
    return m_pinvMass;
}

//--------------------------set functions-------------------

void point::setP(glm::vec3 _pPos)
{
    this->m_pPos=_pPos;
}

void point::setV(glm::vec3 _pVel)
{
    this->m_pVel=_pVel;
}

void point::setTmp(glm::vec3 _tmpPos)
{
    this->tmp_pos=_tmpPos;
}

void point::setM(float _pMass)
{
    this->m_pMass=_pMass;
}

void point::setIM(float _pinvMass)
{
    this->m_pinvMass=_pinvMass;
}

}
