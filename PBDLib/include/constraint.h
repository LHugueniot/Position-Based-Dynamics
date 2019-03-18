#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "point.h"
#include <memory>

namespace LuHu{

class constraint
{
public:

<<<<<<< HEAD
    constraint();
    ~constraint();
    virtual void timeStep();
    virtual std::shared_ptr<point> getPoint(uint index) const;
    virtual void setPoint(std::shared_ptr<point> _p, uint index);
};

//-----------------------------------------------------------------Distance Constraint---------------------------------------------------

=======
    constraint(){}
    virtual void timeStep(int dt){}
};

>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
class distanceConstraint : public constraint
{
public:

<<<<<<< HEAD
    /// @brief Constructor.
    /// @param _p1 is the first point type shared pointer.
    /// @param _p2 is the second point type shared pointer.
    /// @param _rest is calculated by the constructor.

    distanceConstraint(std::shared_ptr<point> _p1, std::shared_ptr<point> _p2);

    /// @brief Constructor with regular pointers for convenience.

    distanceConstraint(point &_p1, point &_p2);

    /// @brief timeStep project the distance constraint and store new values in points.

    void timeStep();

    /// @brief getPoint returns a shared pointer to an indexed point from this class
    /// @param index gets the point shared pointer at index

    std::shared_ptr<point> getPoint(uint index) const;

    /// @brief setPoint replaces one of the constraint points based on the index number
    /// @param _p new point to set
    /// @param index which constraint point to replace

    void setPoint(std::shared_ptr<point> _p, uint index);

    ///@brief getRestLength returns m_restLength

    float getRestLength() const;

    /// @brief set the value of m_restLength
    /// @param _newRestLength is new rest length to set

    void setRestLength(float _newRestLength);

private:

    /// @param m_p1 shared pointer of type point to first constraint point

    std::shared_ptr<point> m_p1;

    /// @param m_p2 shared pointer of type point to second constraint point

    std::shared_ptr<point> m_p2;

    /// @param m_restLength standard length between the points

    float m_restLength;
};

//-----------------------------------------------------------------Collision Constraint--------------------------------------------------

=======
    distanceConstraint(std::shared_ptr<point> _p1, std::shared_ptr<point> _p2);

    distanceConstraint(point &_p1, point &_p2);

    void timeStep(int dt);

    std::shared_ptr<point> m_p1;
    std::shared_ptr<point> m_p2;
};

>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad

class collisionConstraint : public constraint
{

public:
<<<<<<< HEAD
    /// @brief Constructor.
    /// @param _p1 is the first point type shared pointer.

    collisionConstraint(std::shared_ptr<point> _p1);

    /// @brief timeStep project the collision constraint and store new values in points.

    void timeStep();

    /// @brief getPoint returns a shared pointer to an indexed point from this class
    /// @param index gets the point shared pointer at index

    std::shared_ptr<point> getPoint(uint index) const;

    /// @brief setPoint replaces one of the constraint points based on the index number
    /// @param _p new point to set
    /// @param index which constraint point to replace

    void setPoint(std::shared_ptr<point> _p, uint index);

private:

    std::shared_ptr<point> m_p1;
};

//-----------------------------------------------------------------Bending Constraint----------------------------------------------------
=======

    collisionConstraint();


    void timeStep(int dt);
};

>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad

class bendingConstraint : public constraint
{

public:

<<<<<<< HEAD
    /// @brief Constructor.
    /// @param _p1 is the first point type shared pointer.
    /// @param _p2 is the second point type shared pointer.
    /// @param _p3 is the second point type shared pointer.

    bendingConstraint(std::shared_ptr<point> _p1, std::shared_ptr<point> _p2, std::shared_ptr<point> _p3);

    /// @brief Constructor with regular pointers for convenience.

    bendingConstraint(point & _p1, point & _p2, point & _p3);

    /// @brief timeStep project the bending constraint and store new values in points.

    void timeStep();

    /// @brief getPoint returns a shared pointer to an indexed point from this class
    /// @param index gets the point shared pointer at index

    std::shared_ptr<point> getPoint(uint index) const;

    /// @brief setPoint replaces one of the constraint points based on the index number
    /// @param _p new point to set
    /// @param index which constraint point to replace

    void setPoint(std::shared_ptr<point> _p, uint index);

    /// @brief getAngle returns m_angle

    float getAngle();

    /// @brief setAngle based on _angle

    void setAngle(float _angle);

private:

    /// @param m_p1 shared pointer of type point to first constraint point

    std::shared_ptr<point> m_p1;

    /// @param m_p2 shared pointer of type point to first constraint point

    std::shared_ptr<point> m_p2;

    /// @param m_p3 shared pointer of type point to first constraint point

    std::shared_ptr<point> m_p3;

    /// @param m_angle angle between the segments at rest

    float  m_angle;
=======
    bendingConstraint(std::shared_ptr<point> _p1, std::shared_ptr<point> _p2, std::shared_ptr<point> _p3);
    bendingConstraint(point _p1, point _p2, point _p3);

    void timeStep(int dt);

    std::shared_ptr<point> m_p1;
    std::shared_ptr<point> m_p2;
    std::shared_ptr<point> m_p3;
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
};

}
#endif // CONSTRAINT_H
