#include <iostream>
#include "B.h"

class A
{
    friend void B::display();

  private:
    static int _a;
};

inline void B::display()
{
    std::cout << A::_a << "\n";
}