#include "SortBase.h"

class BubbleSort : public SortBase
{
public:
    BubbleSort(int argc, char *argv[])
        : SortBase(argc, argv)
    {}

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

int main(int argc, char *argv[])
{
    BubbleSort s(argc, argv);

    s.start();

    return 0;
}

