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
    return true;
}

}
