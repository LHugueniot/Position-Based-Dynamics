#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "point.h"
#include <memory>

namespace LuHu{

class constraint
{
public:

    constraint(){}
    virtual void timeStep(uint dt){}
    virtual std::shared_ptr<point> getPoint(uint index){}
};

class distanceConstraint : public constraint
{
public:

    distanceConstraint(std::shared_ptr<point> _p1, std::shared_ptr<point> _p2);

    distanceConstraint(point &_p1, point &_p2);

    void timeStep(uint dt);

    std::shared_ptr<point> getPoint(uint index){
        if(index==0)
            return m_p1;
        else
            return m_p2;
        }

    float getRestLength() const;
    std::shared_ptr<point> getPoint1() const;
    std::shared_ptr<point> getPoint2() const;

private:
    std::shared_ptr<point> m_p1;
    std::shared_ptr<point> m_p2;

    float m_restLength;
};


class collisionConstraint : public constraint
{

public:

    collisionConstraint();


    void timeStep(uint dt);
};


class bendingConstraint : public constraint
{

public:

    bendingConstraint(std::shared_ptr<point> _p1, std::shared_ptr<point> _p2, std::shared_ptr<point> _p3);
    bendingConstraint(point & _p1, point & _p2, point & _p3);

    void timeStep(uint dt);
    float getAngle();
    std::shared_ptr<point> getPoint1() const;
    std::shared_ptr<point> getPoint2() const;
    std::shared_ptr<point> getPoint3() const;

private:
    std::shared_ptr<point> m_p1;
    std::shared_ptr<point> m_p2;
    std::shared_ptr<point> m_p3;
    float  m_angle;
};

}
#endif // CONSTRAINT_H
