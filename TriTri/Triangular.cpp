#include <iostream>
#include <vector>
#include <algorithm>
#include "Triangular.h"
using namespace std;

vector<int> Triangular::_elems;

void Triangular::gen_elements(int length)
{
    if (length < 0 || length > _max_elems)
    {
        cerr << "No!!! length: " << length << " is illegal\n";
        return;
    }
    if (_elems.size() < length)
    {
        int ix = _elems.size() ? _elems.size() + 1 : 1;
        for (; ix <= length; ++ix)
        {
            _elems.push_back(ix * (ix + 1) / 2);
        }
    }
}

bool Triangular::is_elem(int value)
{
    if (!_elems.size() || _elems[_elems.size() - 1] < value)
    {
        gen_elems_to_value(value);
    }

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();
    found_it = std::find(_elems.begin(), end_it, value); // #include <algorithm>
    return found_it != end_it;
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

void Triangular::gen_elems_to_value(int value)
{
    int ix = _elems.size();
    if (!ix)
    {
        _elems.push_back(1);
        ix = 1;
    }
    while (_elems[ix - 1] < value && ix < _max_elems)
    {
        ++ix;
        _elems.push_back(ix * (ix + 1) / 2);
    }
    if (ix == _max_elems)
    {
        cerr << "Triangular Sequence: oops: value too large " << value << " -- exceeds max size of " << _max_elems << endl;
    }
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