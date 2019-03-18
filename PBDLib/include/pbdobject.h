#ifndef PBDOBJECT_H
#define PBDOBJECT_H

#include "kernel.h"


//glm maths library
#include <glm/glm.hpp>


namespace LuHu {    //namespace (to be changed)

//using namespace glm;

class PBDobject
{

public:

    /// @brief constructor

    PBDobject();

    /// @brief destructor

    ~PBDobject(){}

    /// @brief initialiser, takes in the model path and name, the mesh index and generates points and constraints based on _originalPos

    bool Initialize(std::string _model, uint _meshIndex, glm::vec3 _originalPos);

    /// @brief returns pointers to the points stored in PBDObject

    const std::vector<std::shared_ptr<point> > &getPoints() const;

    /// @brief returns pointers to the constraints stored in PBDObject

    const std::vector<std::shared_ptr<constraint> > &getConstraints() const;

    /// @brief adds a point to PBDObject

    void addPoint(std::shared_ptr<point> _newP);

    /// @brief adds a constraint to PBDObject

    void addConstraint(std::shared_ptr<constraint> _newCon);

    /// @brief returns faces based on points

    const std::vector<std::shared_ptr<point> > &getFacesPoints() const;

    std::string getName() const
    {
        return m_modelName;
    }

    glm::vec3 getOriginalPos() const
    {
        return m_originalPosition;
    }

private:

    /// @param string storing model name

    std::string m_modelName;

    /// @param stores original position

    glm::vec3 m_originalPosition;

    /// @param stores all the pointers to points in order of faces, to get a face iterate through in 3s

    std::vector<std::shared_ptr<point>> m_facePoints;

    /// @param stores all the pointers to points, they are shared pointers to prevent any memory leaks

    std::vector<std::shared_ptr<point>> m_Points;

    /// @param stores all the pointers to constraints

    std::vector<std::shared_ptr<constraint>> m_Constraints;
};

}
#endif // PBDOBJECT_H
