#include "SortBase.h"

class SelectionSort : public SortBase
{
public:
    SelectionSort(int argc, char *argv[])
        : SortBase(argc, argv)
    {
    }

    void doSort()
    {
        for (decltype(v.size()) i = 0; i < v.size() - 1; i++)
        {
            auto pos = i;

            for (auto j = i + 1; j < v.size(); j++)
            {
                if (v[j] < v[pos])
                    pos = j;
            }

            std::swap(v[i], v[pos]);
        }
    }
};

int main(int argc, char *argv[])
{
    SelectionSort s(argc, argv);

    s.start();

    return 0;
}

