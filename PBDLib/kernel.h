#ifndef KERNEL_H
#define KERNEL_H

#include "pbdhair_global.h"

class PBDHAIRSHARED_EXPORT PBDHair
{

public:
    PBDHair(uint _numStrands);

    uint m_numStrands;
};

#endif // KERNEL_H
