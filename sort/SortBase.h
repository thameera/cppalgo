#ifndef _SORT_BASE_H_
#define _SORT_BASE_H_

#include <iostream>
#include <vector>

typedef std::vector<int> vect;

class SortBase
{
public:
    SortBase(int argc, char *argv[])
    {
        if (argc > 1)
        {
            for (int i = 1; i < argc; i++)
                v.push_back(atoi(argv[i]));
        }
        else
            v = {7, 8, 1, 10, 5, 25, 12};
    }

    virtual ~SortBase() {}

    void Print(const vect& vv, const std::string s = "")
    {
        using std::cout;

        if (!s.empty())
            cout << s << " : ";

        for (auto x : vv)
            cout << x << " ";

        cout << std::endl;
    }

    inline void Print(const std::string s = "") { Print(v, s); }

    virtual void doSort() = 0;

    virtual const std::string getName() { return "N/A"; }

    void start()
    {
        std::cout << "Running " << getName() << "..." << std::endl;
        Print("Input ");
        doSort();
        Print("Output");
    }

protected:
    vect v;
    vect v_orig;
};

#endif // _SORT_BASE_H_

