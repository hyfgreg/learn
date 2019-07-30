#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Triangular
{
  public:
    Triangular(int length = 1, int beg_pos = 1)
    {
        _length = length > 0 ? length : 1;
        _beg_pos = beg_pos > 0 ? beg_pos : 1;
        _next = _beg_pos - 1;
        fill_elem();
    }

    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const;

    bool next(int &val);
    void next_reset() { _next = _beg_pos - 1; }
    friend ostream &operator<<(ostream &out, Triangular &tri);

  private:
    mutable int _next;
    int _length;
    int _beg_pos;
    static vector<int> _elems;

    void fill_elem();
    static bool is_elem(int val);
};