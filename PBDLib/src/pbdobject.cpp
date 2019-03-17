#include "pbdobject.h"


namespace LuHu {



PBDobject::PBDobject()
{

}

bool PBDobject::Initialize(std::string _model, glm::vec3 _originalPos)
{
    m_modelName=_model;
    m_originalPosition=_originalPos;

    const aiScene* scene=getModel(m_modelName);
    if(scene==NULL)
    {
        return false;
    }

    m_facePoints=storePoints(scene,0);

    auto edges = getEdges(scene,0);

    m_Constraints =createDistanceConstraints(edges,m_facePoints, m_Points);

    return true;
}

std::vector<std::shared_ptr<constraint>> PBDobject::getConstraints() const
{
    return m_Constraints;
}

}
