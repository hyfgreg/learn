#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LessThan
{
  public:
    LessThan(int val) : _val(val){};
    int comp_val() const { return _val; }
    void comp_val(int nval) { _val = nval; }

    bool operator()(int _value) const; // 类似python的__call__函数

  private:
    int _val;
};

inline bool
LessThan::operator()(int value) const
{
    return value < _val;
}

int count_less_than(const vector<int> &vec, int comp)
{
    LessThan lt(comp);
    int count = 0;
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        if (lt(vec[ix]))
            ++count;
    }
    return count;
}

void print_less_than(const vector<int> &vec, int comp, ostream &os = cout)
{
    LessThan lt(comp);
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator it_end = vec.end();
    os << "Elements less than " << lt.comp_val() << endl;
    while ((iter = find_if(iter, it_end, lt)) != it_end)
    {
        os << *iter << ' ';
        ++iter;
    }
    cout << endl;
}

int main()
{
    int tmp[7] = {17, 12, 44, 9, 18, 45, 6};
    vector<int> vec(tmp, tmp + 7);
    int comp_val = 20;
    cout << "Number of elements less than " << comp_val << " are " << count_less_than(vec, comp_val) << endl;
    print_less_than(vec, comp_val);
}