#include <iostream>
#include <vector>
#include <string>
#include "Triangular_iterator.h"
using namespace std;

class Triangular
{
public:
  friend class Triangular_iterator;

  typedef Triangular_iterator iterator;

  Triangular_iterator begin() const
  {
    return Triangular_iterator(_beg_pos);
  }

  Triangular_iterator end() const
  {
    return Triangular_iterator(_beg_pos + _length);
  }

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
  static bool is_elem(int val);
  static void gen_elements(int length);
  static void gen_elems_to_value(int value);

private:
  static vector<int> _elems;
  mutable int _next;
  int _length;
  int _beg_pos;
  static const int _max_elems = 1024;

  void fill_elem();
};

class iterator_overflow
{
};

inline int Triangular_iterator::operator*() const
{
  check_integrity();
  return Triangular::_elems[_index];
}

inline void Triangular_iterator::check_integrity() const
{
  if (_index >= Triangular::_max_elems)
  {
    throw iterator_overflow();
  }

  if (_index >= Triangular::_elems.size())
  {
    Triangular::gen_elements(_index + 1);
  }
}