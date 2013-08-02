#ifndef _SORT_BASE_H_
#define _SORT_BASE_H_

#include <iostream>
#include <vector>

#define DEBUG(x) do { std::cerr << x << std::endl; } while (false)
#define DEBUGL(x) do { std::cerr << __FILE__ << ":" << __LINE__ << " " << x << std::endl; } while (false)

typedef std::vector<int> vect;

class SortBase
{
public:
    SortBase()
    {
        v = {7, 8, 1, 10, 5, 25, 12};
    }

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

    inline const vect& getVect() { return v; }
    inline void setVect(const vect& vv) { v = vv; }

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

    const vect& getSorted(const vect& vv)
    {
        v = vv;
        doSort();
        return v;
    }

protected:
    vect v;
    vect v_orig;
};

#endif // _SORT_BASE_H_

