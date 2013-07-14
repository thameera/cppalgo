#ifndef _INSERTION_H_
#define _INSERTION_H_

#include "SortBase.h"

class InsertionSort : public SortBase
{
public:
    InsertionSort(int argc, char *argv[])
        : SortBase(argc, argv)
    {
    }

    void doSort()
    {
        for (decltype(v.size()) i = 0; i < v.size(); i++)
        {
            auto curVal = v[i];
            auto hole = i;

            while (hole > 0 && v[hole - 1] > curVal)
            {
                v[hole] = std::move(v[hole - 1]);
                hole--;
            }
            
            v[hole] = curVal;
        }
    }
};

#endif // _INSERTION_H_

