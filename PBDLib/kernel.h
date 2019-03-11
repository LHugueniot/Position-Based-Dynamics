#ifndef KERNEL_H
#define KERNEL_H

#include "pbdlib_global.h"

class PBDLIBSHARED_EXPORT PBDobj
{

public:
    PBDobj(uint _numStrands);

    uint m_numStrands;
};

#endif // KERNEL_H
