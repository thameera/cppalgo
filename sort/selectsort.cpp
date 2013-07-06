#include <iostream>
#include <vector>

void vprint(std::vector<int> v)
{
    for (auto x : v)
        std::cout << x << " ";
    std::cout << std::endl;
}

void selectionSort(std::vector<int> &v)
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

int main(int argc, char *argv[])
{
    std::vector<int> v;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
            v.push_back(atoi(argv[i]));
    }
    else
        v = {7, 8, 1, 10, 5, 25, 12};

    selectionSort(v);

    vprint(v);

    return 0;
}
