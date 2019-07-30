#include <iostream>
#include "Triangular.h"
using namespace std;

vector<int> Triangular::_elems;

bool Triangular::is_elem(int val)
{
    return true;
}

int Triangular::elem(int pos) const
{
    return _elems[pos - 1];
}

bool Triangular::next(int &val)
{
    if (_next < _beg_pos + _length - 1)
    {
        val = _elems[_next++];
        return true;
    }
    return false;
}

void Triangular::fill_elem()
{
    int current_length = _elems.size();
    if (int new_elems_length = _length - current_length)
    {
        int start_value = current_length ? _elems[current_length - 1] : 0;
        while (new_elems_length > 0)
        {
            _elems.push_back(start_value);
            start_value++;
            new_elems_length--;
        }
    }
}

ostream &operator<<(ostream &out, Triangular &tri)
{
    int tmp;
    string s = "{ ";
    while (tri.next(tmp))
    {
        s += to_string(tmp);
        s += ", ";
    }
    int length = s.size();
    s.erase(length - 2, length - 1);
    s += " }";
    out << s << endl;
    return out;
}