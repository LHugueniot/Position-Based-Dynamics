#include "constraint.h"
<<<<<<< HEAD
#include "kernel.h"

namespace LuHu{

//-----------------------------------------------------------------Base Constraint class-------------------------------------------------


constraint::constraint(){}

constraint::~constraint(){}

void constraint::timeStep(){}

std::shared_ptr<point> constraint::getPoint(uint index) const{}

void constraint::setPoint(std::shared_ptr<point> _p, uint index){}

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

void distanceConstraint::timeStep()
{
    glm::vec3 dir = m_p1->getTmpPos() - m_p2->getTmpPos();

    float len = glm::length(dir);
    float inv_mass=m_p1->getIM() + m_p2->getIM();

    m_p1->setTmp(
                (m_p1->getTmpPos()-
                 (m_p1->getIM()/inv_mass)*
                 (len - m_restLength)*
                 (dir/len)
                 )
                );


    m_p2->setTmp(
                (
                    m_p2->getTmpPos()+
                    (m_p2->getIM()/inv_mass)*
                    (len - m_restLength)*
                    (dir/len)
                    )
                );
}
std::shared_ptr<point> distanceConstraint::getPoint(uint index) const

{
    if(index==0)
    {
        return m_p1;
    }
    else if(index==1)
    {
        return m_p2;
    }
    else
    {
        return NULL;
    }

}

float distanceConstraint::getRestLength() const
{
    return m_restLength;
}

void distanceConstraint::setPoint(std::shared_ptr<point> _p, uint index)
{
    if(index==0)
    {
        m_p1=_p;
    }
    else if(index==1)
    {
        m_p2=_p;
    }
    else
    {
        std::cout<<"distanceConstraint error, index too big, must be smaller than 2";
    }
}

void distanceConstraint::setRestLength(float _newRestLength)
{
    m_restLength=_newRestLength;
}

//-----------------------------------------------------------------Collision Constraint--------------------------------------------------

collisionConstraint::collisionConstraint(std::shared_ptr<point> _p1) :
    m_p1(_p1)
=======

namespace LuHu{

//-----------------------------------------------------------------Distance Constraint---------------------------------------------------


distanceConstraint::distanceConstraint(std::shared_ptr<point> _p1,
                                       std::shared_ptr<point> _p2):
                                        m_p1(_p1), m_p2(_p2){}

distanceConstraint::distanceConstraint(point & _p1, point & _p2):
                                        m_p1(std::make_shared<point>(_p1)),
                                        m_p2(std::make_shared<point>(_p2)){}

void distanceConstraint::timeStep(int dt)
{

}
//-----------------------------------------------------------------Collision Constraint--------------------------------------------------

collisionConstraint::collisionConstraint()
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
{

}

<<<<<<< HEAD
void collisionConstraint::timeStep()
{

}
std::shared_ptr<point> collisionConstraint::getPoint(uint index) const
{

}

void collisionConstraint::setPoint(std::shared_ptr<point> _p, uint index)
{
    if(index==0)
    {
        m_p1=_p;
    }
    else
    {
        std::cout<<"bendingConstraint error, index too big, must be equal to 0";
    }
}
=======
void collisionConstraint::timeStep(int dt)
{

}
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad

//-----------------------------------------------------------------Bending Constraint----------------------------------------------------



bendingConstraint::bendingConstraint(std::shared_ptr<point> _p1,
                                     std::shared_ptr<point> _p2,
                                     std::shared_ptr<point> _p3):
<<<<<<< HEAD
    m_p1(_p1), m_p2(_p2), m_p3(_p3){}

bendingConstraint::bendingConstraint(point & _p1, point & _p2, point & _p3):
=======
                                      m_p1(_p1), m_p2(_p2), m_p3(_p3){}

bendingConstraint::bendingConstraint(point _p1, point _p2, point _p3):
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
    m_p1(std::make_shared<point>(_p1)),
    m_p2(std::make_shared<point>(_p2)),
    m_p3(std::make_shared<point>(_p3)){}

<<<<<<< HEAD
void bendingConstraint::timeStep()
=======
void bendingConstraint::timeStep(int dt)
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
{

}

<<<<<<< HEAD
std::shared_ptr<point> bendingConstraint::getPoint(uint index) const
{
    if(index==0)
    {
        return m_p1;
    }
    else if(index==1)
    {
        return m_p2;
    }
    else if(index==2)
    {
        return m_p3;
    }
    else
    {
        std::cout<<"bendingConstraint error, index too big, must be smaller than 3";
    }
}

void bendingConstraint::setPoint(std::shared_ptr<point> _p, uint index)
{
    if(index==0)
    {
        m_p1=_p;
    }
    else if(index==1)
    {
        m_p2=_p;
    }
    else if(index==2)
    {
        m_p3=_p;
    }
    else
    {
        std::cout<<"distanceConstraint error, index too big, must be smaller than 3";
    }
}

float bendingConstraint::getAngle()
{
    return m_angle;
}

void bendingConstraint::setAngle(float _angle)
{
    m_angle=_angle;
}

}
=======
}

>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
