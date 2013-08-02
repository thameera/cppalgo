#ifndef _MERGE_H_
#define _MERGE_H_

#include "SortBase.h"

class MergeSort : public SortBase
{
public:
    MergeSort() {}

    MergeSort(int argc, char *argv[])
        : SortBase(argc, argv)
    {
    }

    const std::string getName() { return "Merge Sort"; }

    vect mergesort(vect lst)
    {
        auto sz = lst.size();

        if (sz <= 1)
            return lst;

        if (sz == 2)
        {
            if (lst[0] < lst[1])
                return lst;
            std::swap(lst[0], lst[1]);
            return lst;
        }

        // Divide
        auto halfsz = sz / 2;
        vect lst1(lst.begin(), lst.begin() + halfsz);
        vect lst2(lst.begin() + halfsz, lst.end());
        vect res1 = mergesort(lst1);
        vect res2 = mergesort(lst2);

        // Conquer
        decltype(lst.size()) pos1 = 0, pos2 = 0;
        vect result;

        for (decltype(lst.size()) i = 0; i < lst.size(); i++)
        {
            if (pos1 >= res1.size())
                result.push_back(res2[pos2++]);
            else if (pos2 >= res1.size())
                result.push_back(res1[pos1++]);
            else if (res1[pos1] < res2[pos2])
                result.push_back(res1[pos1++]);
            else
                result.push_back(res2[pos2++]);
        }

        return result;
    }

    void doSort()
    {
        v = mergesort(v);
    }
};

#endif // _MERGE_H_
