#include "point.h"

namespace LuHu{

<<<<<<< HEAD
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
=======
point::point(glm::vec3 _pPos, glm::vec3 _pVel, float _pWeight) :
    m_pPos(_pPos),
    m_pVel(_pVel),
    m_pWeight(_pWeight)
{}

point::point(float _Px, float _Py, float _Pz, float _Vx, float _Vy, float _Vz, float _pWeight) :
    m_pPos(glm::vec3(_Px, _Py, _Pz)),
    m_pVel(glm::vec3(_Vx,_Vy,_Vz)),
    m_pWeight(_pWeight)
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
{}

bool point::operator==(const point &p1) const
{
    return (this->m_pPos  == p1.m_pPos ? true : false) &&
            (this->m_pVel  == p1.m_pVel ? true : false) &&
<<<<<<< HEAD
            (this->tmp_pos  == p1.tmp_pos ? true : false) &&
            (this->m_pinvMass  == p1.m_pinvMass ? true : false);
}

//--------------------------get functions-------------------

=======
            (this->m_pWeight  == p1.m_pWeight ? true : false);
}

>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
glm::vec3 point::getP() const
{
    return m_pPos;
}

glm::vec3 point::getV() const
{
    return m_pVel;
}

<<<<<<< HEAD
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

=======
float point::getW() const
{
    return m_pWeight;
}

>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
void point::setP(glm::vec3 _pPos)
{
    this->m_pPos=_pPos;
}
<<<<<<< HEAD

=======
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
void point::setV(glm::vec3 _pVel)
{
    this->m_pVel=_pVel;
}
<<<<<<< HEAD

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
=======
void point::setW(float _pWeight)
{
    this->m_pWeight=_pWeight;
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
}

}
