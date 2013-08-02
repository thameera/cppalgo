#include <ctime>
#include <random>

#include "testsim.h"

namespace ts
{
    void Randomize()
    {
        std::srand( unsigned(std::time(0)) );
    }

    vect CreateVect(int size, int low, int high)
    {
        vect v;
        for (int i = 0; i < size; i++)
            v.push_back(std::rand() % (high - low) + low);

        return v;
    }

    bool IsSorted(const vect &v)
    {
        auto sz = v.size();
        for (decltype(sz) i = 1; i < sz; i++)
        {
            if (v[i] < v[i-1])
                return false;
        }

        return true;
    }
}

