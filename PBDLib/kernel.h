#ifndef KERNEL_H
#define KERNEL_H

#include "pbdlib_global.h"

class PBDLIBSHARED_EXPORT PBDobject
{

public:
    PBDobject(uint _numStrands);

    uint m_numStrands;
};

#endif // KERNEL_H
