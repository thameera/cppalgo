#ifndef _BUBBLE_H_
#define _BUBBLE_H_

#include "SortBase.h"

class BubbleSort : public SortBase
{
public:
    BubbleSort(int argc, char *argv[])
        : SortBase(argc, argv)
    {}

    const std::string getName() { return "Bubble Sort"; }

    void doSort()
    {
        while (true)
        {
            bool sorted = true;

            for (decltype(v.size()) i = 0; i < v.size() - 1; i++)
            {
                // Swap if next elment is smaller
                if (v[i] > v[i+1])
                {
                    std::swap(v[i], v[i+1]);
                    sorted = false;
                }
            }

            if (sorted)
                break;
        }
    }
};

#endif // _BUBBLE_H_

