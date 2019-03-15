#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "point.h"
#include <memory>

namespace LuHu{

class constraint
{
public:

    constraint(){}
    virtual void timeStep(int dt){}
};

class distanceConstraint : public constraint
{
public:

    distanceConstraint(std::shared_ptr<point> _p1, std::shared_ptr<point> _p2);

    distanceConstraint(point &_p1, point &_p2);

    void timeStep(int dt);

    std::shared_ptr<point> m_p1;
    std::shared_ptr<point> m_p2;
};


class collisionConstraint : public constraint
{

public:

    collisionConstraint();


    void timeStep(int dt);
};


class bendingConstraint : public constraint
{

public:

    bendingConstraint(std::shared_ptr<point> _p1, std::shared_ptr<point> _p2, std::shared_ptr<point> _p3);
    bendingConstraint(point _p1, point _p2, point _p3);

    void timeStep(int dt);

    std::shared_ptr<point> m_p1;
    std::shared_ptr<point> m_p2;
    std::shared_ptr<point> m_p3;
};

}
#endif // CONSTRAINT_H
