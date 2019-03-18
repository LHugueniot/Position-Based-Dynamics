#ifndef PBDOBJECT_H
#define PBDOBJECT_H

<<<<<<< HEAD
=======
#include "pbdlib_global.h"
#include "constraint.h"
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
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
<<<<<<< HEAD

    /// @brief initialiser, takes in the model path and name, the mesh index and generates points and constraints based on _originalPos

    bool Initialize(std::string _model, uint _meshIndex, glm::vec3 _originalPos);

    /// @brief returns pointers to the points stored in PBDObject

    std::vector<std::shared_ptr<point>> getPoints() const;

    /// @brief returns pointers to the constraints stored in PBDObject

    std::vector<std::shared_ptr<constraint>> getConstraints() const;

    /// @brief adds a point to PBDObject

    void addPoint(std::shared_ptr<point> _newP);

    /// @brief adds a constraint to PBDObject

    void addConstraint(std::shared_ptr<constraint> _newCon);

    /// @brief returns faces based on points

    std::vector<std::shared_ptr<point>> getFacesPoints() const;

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
=======
    bool Initialize(std::string _model, glm::vec3 _originalPos);
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad

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
