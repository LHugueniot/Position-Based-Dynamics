#include "constraint.h"

namespace LuHu{

//-----------------------------------------------------------------Distance Constraint---------------------------------------------------


distanceConstraint::distanceConstraint(std::shared_ptr<point> _p1,
                                       std::shared_ptr<point> _p2):
    m_p1(_p1),
    m_p2(_p2)
{
    m_restLength=glm::length(m_p1->getP() - m_p2->getP());
}

distanceConstraint::distanceConstraint(point & _p1, point & _p2):
    m_p1(std::make_shared<point>(_p1)),
    m_p2(std::make_shared<point>(_p2))
{
    m_restLength=glm::length(m_p1->getP() - m_p2->getP());
}

void distanceConstraint::timeStep(uint dt)
{
    glm::vec3 dir = m_p1->getTmpPos() - m_p2->getTmpPos();
    float len = glm::length(dir);
    float inv_mass=m_p1->getIM() + m_p2->getIM();

    //std::cout<<len<<"\n";

    m_p1->setTmp(((m_p1->getIM()/inv_mass)*
                     (len - m_restLength)*
                     (dir/len))-
                 m_p1->getTmpPos());

    m_p2->setTmp(((m_p2->getIM()/inv_mass)*
                    (len - m_restLength)*
                    (dir/len))+
                 m_p2->getTmpPos());
}

float distanceConstraint::getRestLength() const
{
    return m_restLength;
}

std::shared_ptr<point> distanceConstraint::getPoint1() const
{
    return m_p1;
}

std::shared_ptr<point> distanceConstraint::getPoint2() const
{
    return m_p2;
}
//-----------------------------------------------------------------Collision Constraint--------------------------------------------------

collisionConstraint::collisionConstraint()
{

}

void collisionConstraint::timeStep(uint dt)
{

}


//-----------------------------------------------------------------Bending Constraint----------------------------------------------------



bendingConstraint::bendingConstraint(std::shared_ptr<point> _p1,
                                     std::shared_ptr<point> _p2,
                                     std::shared_ptr<point> _p3):
    m_p1(_p1), m_p2(_p2), m_p3(_p3){}

bendingConstraint::bendingConstraint(point & _p1, point & _p2, point & _p3):
    m_p1(std::make_shared<point>(_p1)),
    m_p2(std::make_shared<point>(_p2)),
    m_p3(std::make_shared<point>(_p3)){}

void bendingConstraint::timeStep(uint dt)
{

}



std::shared_ptr<point> bendingConstraint::getPoint1() const
{
    return m_p1;
}

std::shared_ptr<point> bendingConstraint::getPoint2() const
{
    return m_p2;
}

std::shared_ptr<point> bendingConstraint::getPoint3() const
{
    return m_p3;
}

float bendingConstraint::getAngle()
{
    return m_angle;
}


}
