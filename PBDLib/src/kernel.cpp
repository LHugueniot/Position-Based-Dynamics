#include "kernel.h"
#include <unordered_set>


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
    return scene;
}

posVector storePoints(const aiScene* scene,uint meshIndex)
{
    posVector temp;
    if(scene->HasMeshes())
    {
            for(uint j=0; j<scene->mMeshes[meshIndex]->mNumVertices; j++)
            {

                temp.push_back(glm::vec3(scene->mMeshes[meshIndex]->mVertices[j].x,
                                         scene->mMeshes[meshIndex]->mVertices[j].y,
                                         scene->mMeshes[meshIndex]->mVertices[j].z));
            }
    }
    return temp;
}

pVector posToPoint(posVector _pPoints)
{
    pVector temp;
    for(uint i=0; i<_pPoints.size(); i++)
    {
        temp.push_back(point(_pPoints[i], glm::vec3(0,0,0), 1.0f));
    }
    return temp;
}

bool compare(glm::vec3 temp, posVector bigVec)
{
    for(auto p: bigVec)
    {
        if(temp==p)
        {
            return true;
        }
    }
    return false;
}

bool compare( posVector bigVec1,  posVector bigVec2)
{
    if(bigVec1.size()%2==0 && bigVec2.size()%2==0)
    {
        for(uint i=0; i<bigVec1.size(); i+=2)
        {
            //std::cout<<"bigVec1\n";

            for(uint j=0; j<bigVec2.size(); j+=2)
            {
                //std::cout<<"bigVec2\n";

                if((bigVec1[i]==bigVec2[j] && bigVec1[i+1]==bigVec2[j+1] )||
                        (bigVec1[i]==bigVec2[j+1] && bigVec1[i+1]==bigVec2[j]))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

posVector removeDuplicates(posVector _pVec)
{
    posVector tempVec=_pVec;

    posVector newVec;

    newVec.push_back(tempVec[0]);

    bool sorted=false;
    while(!sorted)
    {
        uint count=newVec.size()-1;
        for (uint i=0;i<tempVec.size()-1; i++)
        {

            if(compare(tempVec[i], newVec)==true)
            {

                continue;
            }
            else
            {
                newVec.push_back(tempVec[i]);
                count--;
            }
        }
        if(count==newVec.size()-1)
        {
            sorted=true;
        }
    }


    return newVec;
}

glm::vec3 aiToGLM(aiVector3D mVertices)
{
    return glm::vec3(mVertices.x,mVertices.y,mVertices.z);
}

posVector getConnectedPoints(const aiScene* scene, uint meshIndex)
{

    posVector tempVec = storePoints(scene,meshIndex);
    posVector tempVec2;
    edgeVector newVec;
    std::vector<uint> m_indices;


    if(scene && scene->HasMeshes())
    {
        auto mesh = scene->mMeshes[meshIndex];
        size_t numFaces = mesh->mNumFaces;
        // We iterate through faces not vertices,
        // as the verts will be duplicated when used by more than one face.
        for (size_t faceIndex = 0; faceIndex < numFaces; ++faceIndex)
        {
          auto& face = mesh->mFaces[faceIndex];
          const auto numIndices = face.mNumIndices;
          // Iterate over the vertices of this face
          for (size_t i = 0; i < numIndices; ++i)
          {
            // Get the index of the vertex, we use this for it's normals and UV's too
            size_t vertInFace = face.mIndices[i];
            m_indices.push_back(static_cast<uint>(vertInFace));
          }
        }

        // get the edges
        std::unordered_set<vec3Duo> edgeSet;
        // Roughly
        auto numEdges = static_cast<size_t>(std::abs(static_cast<long>(tempVec.size()) + (static_cast<long>(m_indices.size()) / 3l) - 2l));
        std::cout<<numEdges<<"\n";
        edgeSet.reserve(numEdges);
        // Add all edges to the set, our Edge class is ordered so will eliminate reversed edges
        const auto last = m_indices.size() - 2;
        for (size_t i = 0; i < last; i+=3)
        {
          const auto p1 = m_indices[i];
          const auto p2 = m_indices[i + 1];
          const auto p3 = m_indices[i + 2];
          edgeSet.insert({p1, p2});
          edgeSet.insert({p2, p3});
          edgeSet.insert({p3, p1});
        }
        std::copy(edgeSet.begin(), edgeSet.end(), std::back_inserter(newVec));
    }
    for (size_t i = 0; i < newVec.size(); ++i)
    {
        tempVec2.push_back(tempVec[newVec[i].p.first]);
        tempVec2.push_back(tempVec[newVec[i].p.second]);

        std::cout<<"first "<<newVec[i].p.first<<" second "<<newVec[i].p.second<< "\n";
        //std::cout<<newVec[i].p.first_type;
        //std::cout<<"\n";
        //std::cout<<newVec[i].p.second_type;
    }
    std::cout<<newVec.size()<<"\n";

//    std::vector<std::vector<uint>> m_adjacency;

//    auto numVerts=scene->mMeshes[meshIndex]->mNumVertices;
//    m_adjacency.resize(numVerts);

//    std::vector<std::unordered_set<uint>> adjacencySets(numVerts);

//    for(const auto & edge: newVec)
//    {
//        adjacencySets[edge.p.first].insert(edge.p.second);
//        adjacencySets[edge.p.second].insert(edge.p.first);
//    }
//    for (size_t i = 0; i < numVerts; ++i)
//      m_adjacency[i].insert(m_adjacency[i].end(), adjacencySets[i].begin(), adjacencySets[i].end());

//    for (size_t i = 0; i < m_adjacency.size(); ++i)
//    {
//        auto a=m_adjacency[i];
//        for (size_t j = 0; j < a.size(); ++j)
//        {
//        //std::cout<<a[j]<<"\n";
//        }
//        //std::cout<<"\n";
//    }

//    //std::cout<<newVec.size()<<"\n";
    return tempVec2;
}

void printVec3(glm::vec3 _vec)
{
    std::cout<<"x="<<_vec.x<<" y="<<_vec.y<<" z="<<_vec.z<<"\n";
}

}
