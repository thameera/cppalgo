#include <iostream>
#include <vector>

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

    void Print(const std::vector<int>& vv, const std::string s = "")
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

    void start()
    {
        Print("Input ");
        doSort();
        Print("Output");
    }

protected:
    std::vector<int> v;
    std::vector<int> v_orig;
};
