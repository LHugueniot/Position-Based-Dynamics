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
    if(scene->HasMeshes())
    {
        for(int i=0; i<scene->mNumMeshes; i++)
        {
            for(int j=0; j<scene->mMeshes[i]->mNumVertices; j++)
            {
                m_pArray.push_back(
                glm::vec3(scene->mMeshes[i]->mVertices[j].x,
                scene->mMeshes[i]->mVertices[j].y,
                scene->mMeshes[i]->mVertices[j].z));
            }
        }
    }
    scene->mMeshes;
    scene->mMeshes[1]->mVertices;

    return true;
}

}
