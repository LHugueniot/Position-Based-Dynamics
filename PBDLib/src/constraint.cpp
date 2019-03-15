#include "constraint.h"

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
{

}

void collisionConstraint::timeStep(int dt)
{

}

//-----------------------------------------------------------------Bending Constraint----------------------------------------------------



bendingConstraint::bendingConstraint(std::shared_ptr<point> _p1,
                                     std::shared_ptr<point> _p2,
                                     std::shared_ptr<point> _p3):
                                      m_p1(_p1), m_p2(_p2), m_p3(_p3){}

bendingConstraint::bendingConstraint(point _p1, point _p2, point _p3):
    m_p1(std::make_shared<point>(_p1)),
    m_p2(std::make_shared<point>(_p2)),
    m_p3(std::make_shared<point>(_p3)){}

void bendingConstraint::timeStep(int dt)
{

}

}

