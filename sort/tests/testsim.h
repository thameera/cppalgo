#ifndef _TEST_SIM_H_
#define _TEST_SIM_H_

#include "../SortBase.h"

namespace ts
{
    vect CreateVect(int size, int low = 0, int high = 1000);
    bool IsSorted(const vect &v);
};

#endif // _TEST_SIM_H_

