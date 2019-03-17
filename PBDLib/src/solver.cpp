#include "solver.h"

solver::solver()
{

}

bool solver::addPBDobject(std::shared_ptr<LuHu::PBDobject> _PBDobjectPtr)
{
    if(_PBDobjectPtr)
    {
        m_PBDObjects.push_back(_PBDobjectPtr);
    }
    else{return false;}
}
