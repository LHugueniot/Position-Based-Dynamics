#ifndef SOLVER_H
#define SOLVER_H

#include "pbdobject.h"

class solver
{
public:
    solver();
    bool addPBDobject(std::shared_ptr<LuHu::PBDobject>);
    void removePBDobject(uint _index);
    void removePBDobject(std::shared_ptr<LuHu::PBDobject>);

    void iterate(uint dt);
    std::vector<std::shared_ptr<LuHu::PBDobject>> m_PBDObjects;

};

#endif // SOLVER_H
