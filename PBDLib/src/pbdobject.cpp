#include "pbdobject.h"


namespace LuHu {



PBDobject::PBDobject()
{

}

bool PBDobject::Initialize(std::string _model,uint _meshIndex, glm::vec3 _originalPos)
{
    m_modelName=_model;
    m_originalPosition=_originalPos;

    const aiScene* scene=getModel(m_modelName);
    if(scene==NULL)
    {
        return false;
    }

<<<<<<< HEAD
    auto allpoints = storePoints(scene, _meshIndex);
    auto edges = getEdges(scene, _meshIndex, allpoints);
    auto faceIndices=removeDuplicates(allpoints);

    m_Constraints =createDistanceConstraints(edges,faceIndices, m_Points);
    m_facePoints=getFaces(scene, _meshIndex , m_Points, allpoints);

    for(auto p : m_Points)
    {
        auto pos = p.get()->getP();
        p.get()->setP(pos+m_originalPosition );
    }
=======
    m_facePoints=storePoints(scene,0);
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
    return true;
}

std::vector<std::shared_ptr<constraint>> PBDobject::getConstraints() const
{
    return m_Constraints;
}


std::vector<std::shared_ptr<point>> PBDobject::getPoints() const
{
    return m_Points;
}

void PBDobject::addPoint(std::shared_ptr<point>  _newP)
{
    m_Points.push_back(_newP);
}

void PBDobject::addConstraint(std::shared_ptr<constraint> _newCon)
{
    m_Constraints.push_back(_newCon);
}

std::vector<std::shared_ptr<point>> PBDobject::getFacesPoints() const
{
    return m_facePoints;
}

} // end of namespace

