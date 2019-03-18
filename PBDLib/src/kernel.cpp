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
<<<<<<< HEAD
        for(uint j=0; j<scene->mMeshes[meshIndex]->mNumVertices; j++)
        {

            temp.push_back(aiToGLM(scene->mMeshes[meshIndex]->mVertices[j]));
        }
=======
            for(uint j=0; j<scene->mMeshes[meshIndex]->mNumVertices; j++)
            {

                temp.push_back(glm::vec3(scene->mMeshes[meshIndex]->mVertices[j].x,
                                         scene->mMeshes[meshIndex]->mVertices[j].y,
                                         scene->mMeshes[meshIndex]->mVertices[j].z));
            }
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
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
<<<<<<< HEAD
            for(uint j=0; j<bigVec2.size(); j+=2)
            {
=======
            //std::cout<<"bigVec1\n";

            for(uint j=0; j<bigVec2.size(); j+=2)
            {
                //std::cout<<"bigVec2\n";

>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
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
<<<<<<< HEAD
        for (auto p : tempVec)
        {

            if(compare(p, newVec)==true)
            {

                continue;
            }
            else
            {
                newVec.push_back(p);
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

void printVec3(glm::vec3 _vec)
{
    std::cout<<"x="<<_vec.x<<" y="<<_vec.y<<" z="<<_vec.z<<"\n";
}

bool compare1(indexDuo _p1, indexDuo _p2)
{
    if( _p1 == _p2)
    {
        return true;
    }
}

std::vector<std::shared_ptr<point>> getFaces(const aiScene* scene, uint meshIndex,
                                             std::vector<std::shared_ptr<point>> &pointVector,
                                             posVector defaultIndexing)
{
    std::vector<indexTrio> _temp;
    std::vector<std::shared_ptr<point>> faceVector;
    if(scene && scene->HasMeshes())
    {
        auto mesh=scene->mMeshes[meshIndex];
        auto& faces=mesh->mFaces;
        auto numFace=mesh->mNumFaces;

//        auto defaultIndexing=storePoints(scene,0);
        posVector uniqueVertices=removeDuplicates(defaultIndexing);
        std::vector<uint> filter;

        for(uint i=0; i<defaultIndexing.size(); i++)
        {
            for(uint j=0; j<uniqueVertices.size(); j++)
            {
                if(defaultIndexing[i] == uniqueVertices[j])
                {
                    filter.push_back(j);
                }
            }
        }

        for(uint i=0;i<(numFace-1); i++)
        {
            auto faceIndices=faces[i].mIndices;
            if(faces[i].mNumIndices==3 && i!=numFace-1)
            {
                //std::cout<<"tri\n";
                _temp.push_back(indexTrio(filter[faceIndices[0]], filter[faceIndices[1]] , filter[faceIndices[2]]));
            }

        }

        for(auto  p: _temp)
        {
            faceVector.push_back(pointVector[p.p1]);
            faceVector.push_back(pointVector[p.p2]);
            faceVector.push_back(pointVector[p.p3]);
        }
    }
    return faceVector;
}

std::vector<indexDuo> getEdges(const aiScene* scene, uint meshIndex,
                               posVector defaultIndexing)
{
    std::vector<indexDuo> _temp;
    std::vector<indexDuo> f_temp;
    if(scene && scene->HasMeshes())
    {
        auto mesh=scene->mMeshes[meshIndex];
        auto& faces=mesh->mFaces;
        auto numFace=mesh->mNumFaces;

        std::cout<<numFace;

//        auto defaultIndexing=storePoints(scene,0);
        posVector uniqueVertices=removeDuplicates(defaultIndexing);
        std::vector<uint> filter;

        for(uint i=0; i<defaultIndexing.size(); i++)
        {
            for(uint j=0; j<uniqueVertices.size(); j++)
            {
                if(defaultIndexing[i] == uniqueVertices[j])
                {
                    filter.push_back(j);
                }
            }
        }

        for(uint i=0;i<(numFace); i++)
        {
            auto faceIndices=faces[i].mIndices;
            if(faces[i].mNumIndices==3)
            {
                //std::cout<<"tri\n";
                _temp.push_back(indexDuo(filter[faceIndices[0]], filter[faceIndices[1]]));
                _temp.push_back(indexDuo(filter[faceIndices[1]], filter[faceIndices[2]]));
                _temp.push_back(indexDuo(filter[faceIndices[2]], filter[faceIndices[0]]));

            }
        }

        std::vector<std::vector<int>> test;
        for(auto t : _temp)
        {
            std::vector<int> temp2;
            temp2.push_back(t.p.first);
            temp2.push_back(t.p.second);
            test.push_back(temp2);
        }

        std::sort(test.begin(), test.end());
        test.erase(std::unique(test.begin(), test.end()), test.end());

        for(auto p : test)
        {
            f_temp.push_back(indexDuo(p[0], p[1]));
        }
        return f_temp;
    }
}

std::vector<std::shared_ptr<constraint>> createDistanceConstraints(std::vector<indexDuo> edges,
                                                                   std::vector<glm::vec3> vertices,
                                                                   std::vector<std::shared_ptr<point>> &pointVector)
{

    posVector uniqueVertices=removeDuplicates(vertices);
    std::vector<std::shared_ptr<point>> temp;           //to be a duplicate free vertex of point pointers

    std::vector<std::shared_ptr<constraint>> conIndex;

    for(auto p : uniqueVertices)
    {
        std::shared_ptr<point> a(new point(p,glm::vec3(0), 1.0f));
        temp.push_back(a);
    }

    pointVector=temp;

    for(uint j=0; j<edges.size(); j++)
    {
        auto ip1 =edges[j].p.first;
        auto ip2 =edges[j].p.second;

        auto p1= pointVector[ip1];
        auto p2= pointVector[ip2];
        std::shared_ptr<constraint> b(new distanceConstraint(p1, p2));
        conIndex.push_back(b);
    }

    return conIndex;
=======
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
>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
}

}
