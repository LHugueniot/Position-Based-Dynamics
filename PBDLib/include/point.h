#ifndef POINT_H
#define POINT_H

#include <glm/glm.hpp>

namespace LuHu{

class point
{
public:
    point(glm::vec3 _pPos, glm::vec3 _pVel, float _pWeight);
    point(float _Px, float _Py, float _Pz, float _Vx, float _Vy, float _Vz, float _pWeight);

    glm::vec3 getP() const;
    glm::vec3 getV() const;
    float getW()     const;

    void setP(glm::vec3 _pPos);
    void setV(glm::vec3 _pVel);
    void setW(float _pWeight );

    bool operator==(const point &p1) const;
private:
    glm::vec3 m_pPos;
    glm::vec3 m_pVel;
    float m_pWeight;
};

}

#endif // POINT_H
