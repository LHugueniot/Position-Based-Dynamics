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
    glm::vec3 getTmpPos() const;
    float getM() const;
    float getIM() const;

    void setP(glm::vec3 _pPos);
    void setV(glm::vec3 _pVel);
    void setTmp(glm::vec3 _tmpPos);
    void setM(float _pMass );
    void setIM(float _pinvMass);

    bool operator==(const point &p1) const;
private:
    glm::vec3 m_pPos;
    glm::vec3 m_pVel;
    glm::vec3 tmp_pos;
    float m_pMass;
    float m_pinvMass;

};

}

#endif // POINT_H
