#include "solver.h"

namespace LuHu {

solver::solver(float _damp, glm::vec3 _grav)
{
    m_gravity=_grav;
    m_dampening=_damp;
}

glm::vec3 solver::getGrav() const
{
    return m_gravity;
}

float solver::getDamp() const
{
    return m_dampening;
}

void solver::setGrav(glm::vec3 _grav)
{
    m_gravity=_grav;
}

void solver::setDamp(float _damp)
{
    m_dampening=_damp;
}

bool solver::addPBDobject(std::shared_ptr<LuHu::PBDobject> _PBDobjectPtr)
{
    if(_PBDobjectPtr)
    {
        m_PBDObjects.push_back(_PBDobjectPtr);
    }
    else{
        return false;
    }
}

bool solver::addPBDobject(PBDobject & _PBDobjectPtr)
{
    if(&_PBDobjectPtr)
    {
        m_PBDObjects.push_back(std::make_shared<PBDobject>(_PBDobjectPtr));
    }
}

bool solver::rmPBDobject(std::shared_ptr<LuHu::PBDobject> _PBDobjectPtr)
{
    if(_PBDobjectPtr)
    {
        auto it = std::find(m_PBDObjects.begin(), m_PBDObjects.end(),_PBDobjectPtr);
        m_PBDObjects.erase(it);
    }
    else{
        return false;
    }
}
bool solver::rmPBDobject(uint index)
{
    if(index<=m_PBDObjects.size())
    {
        m_PBDObjects.erase(m_PBDObjects.begin()+index);
        return true;
    }
    else
    {
        return false;
    }

}

std::vector<std::shared_ptr<LuHu::PBDobject>> solver::getObjects() const
{
    return m_PBDObjects;
}

void solver::RunSolver(float dt)
{
    float inv_dt = 1/dt;
    for(std::shared_ptr<PBDobject> & pObject :m_PBDObjects)
    {
        auto objPoints= pObject->getPoints();
        auto objConstraints = pObject.get()->getConstraints();

        for(uint i=0; i<objPoints.size(); i++)
        {
            point & p= *(objPoints[i].get());
            p.setV( p.getV()+
                    (m_gravity* m_dampening*p.getIM()*inv_dt));
            //printVec3(p.getV());

            p.setTmp(p.getP() + p.getV() * inv_dt);
        }

        for (uint i=0; i<5; i++)
        {
            for (uint j=0; j<objConstraints.size(); j++)
            {
                objConstraints[j]->timeStep();
            }
        }

        for (uint i=0; i<objPoints.size(); i++)
        {
            point & p= *(objPoints[i].get());

            p.setV( (p.getTmpPos() - p.getP())/ inv_dt);
            p.setP(p.getTmpPos());
        }

    }

}

} // end of namespace

