#ifndef POINT_H
#define POINT_H

#include <glm/glm.hpp>

namespace LuHu{

class point
{
public:

    ///@brief constructors, sets all parameters

    point(glm::vec3 _pPos, glm::vec3 _pVel, float _pWeight);
    point(float _Px, float _Py, float _Pz, float _Vx, float _Vy, float _Vz, float _pWeight);


    /// @brief get and setter functions

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

    /// @param m_pPos point pos

    glm::vec3 m_pPos;

    /// @param m_pVel point vel

    glm::vec3 m_pVel;

    /// @param tmp_pos temp pos used by solver and constraints

    glm::vec3 tmp_pos;

    /// @param m_pMass point mass

    float m_pMass;

    /// @param m_pinvMass inverse mass, it can be set to 0 to make point immovable

    float m_pinvMass;

};

}

#endif // POINT_H
