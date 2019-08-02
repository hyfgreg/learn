#include <iostream>
// #include "B.h"
#include "A.h"

void B::display()
{
    std::cout << A::_a << "\n";
}