#ifndef POINT_H
#define POINT_H

#include <glm/glm.hpp>

class point
{
public:
    point(glm::vec3 _pPos, glm::vec3 _pVel, float _pWeight);

    glm::vec3 m_pPos;
    glm::vec3 m_pVel;
    float m_pWeight;

    bool operator==(const point &p1) const;
};


#endif // POINT_H