#include "pbdobject.h"

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace LuHu {

PBDobject::PBDobject()
{

}

bool PBDobject::Initialize(std::string _model, glm::vec3 _originalPos)
{
    m_modelName=_model;
    m_originalPosition=_originalPos;

    int n = m_modelName.length();
    char tempModelName[n+1];

    std::strcpy(tempModelName, m_modelName.c_str());

    const aiScene* scene= aiImportFile(tempModelName,  aiProcess_CalcTangentSpace       |
                                       aiProcess_Triangulate            |
                                       aiProcess_JoinIdenticalVertices  |
                                       aiProcess_SortByPType);
    if(!scene){
        std::cout<<aiGetErrorString()<<"\n";
        return false;
    }
    scene->mMeshes[0]->mVertices;
    return true;
}

}
