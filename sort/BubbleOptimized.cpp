#include "SortBase.h"

// Optimization:
// Avoid traversing the sorted end of the list

class OptimizedBubbleSort : public SortBase
{
public:
    OptimizedBubbleSort(int argc, char *argv[])
        : SortBase(argc, argv)
    {}

    void doSort()
    {
        auto n = v.size() - 1;

        while (true)
        {
            decltype(v.size()) newn = 0;

            for (decltype(v.size()) i = 0; i < n; i++)
            {
                // Swap if next elment is smaller
                if (v[i] > v[i+1])
                {
                    std::swap(v[i], v[i+1]);
                    newn = i;
                }
            }

            if (newn == 0)
                break;

            n = newn;
        }
    }
};

int main(int argc, char *argv[])
{
    OptimizedBubbleSort s(argc, argv);

    s.start();

    return 0;
}

