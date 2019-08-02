// #include "Triangular.h"
#include <vector>

using namespace std;

class Triangular_iterator
{
  public:
    Triangular_iterator(int index) : _index(index) {}
    bool operator==(const Triangular_iterator &) const;
    bool operator!=(const Triangular_iterator &) const;
    int operator*() const;
    Triangular_iterator &operator++();   // 前置++
    Triangular_iterator operator++(int); // 后置++

  private:
    void check_integrity() const;
    int _index;
};

inline bool
Triangular_iterator::operator==(const Triangular_iterator &rhs) const
{
    return _index == rhs._index;
}

inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const
{
    return !(*this == rhs);
}

inline Triangular_iterator &Triangular_iterator::operator++()
{
    ++_index;
    check_integrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::operator++(int)
{
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}