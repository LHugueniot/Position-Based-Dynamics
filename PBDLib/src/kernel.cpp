#include "kernel.h"

namespace LuHu {

const aiScene* getModel(std::string _model)
{
    const aiScene* scene= aiImportFile(_model.c_str(),  aiProcess_CalcTangentSpace       |
                                       aiProcess_Triangulate            |
                                       aiProcess_JoinIdenticalVertices  |
                                       aiProcess_SortByPType);
    if(!scene){
        std::cout<<aiGetErrorString()<<"\n";
        return NULL;
    }
}

posVector storePoints(const aiScene* scene)
{
    posVector m_posVector;
    if(scene->HasMeshes())
    {
        for(int i=0; i<scene->mNumMeshes; i++)
        {
            for(int j=0; j<scene->mMeshes[i]->mNumVertices; j++)
            {

                m_posVector.push_back(glm::vec3(scene->mMeshes[i]->mVertices[j].x,
                                                scene->mMeshes[i]->mVertices[j].y,
                                                scene->mMeshes[i]->mVertices[j].z));
            }
        }
    }
    return m_posVector;
}

pVector posToPoint(posVector _pPoints)
{
    pVector temp;
    for(int i=0; i<_pPoints.size(); i++)
    {
        temp.push_back(point(_pPoints[i], glm::vec3(0,0,0), 1.0f));
    }
    return temp;
}

pVector compressPoints(posVector _pVec)
{
    posVector tempVec=_pVec;
    int n=tempVec.size();
    bool sorted=false;
    while(!sorted)
     for(int i=tempVec.size()-1; i<tempVec.size(); i--)
        if(tempVec[i] == tempVec[n])
            tempVec.erase(i);



    tempVec.push_back(_pVec[0]);


}

}
