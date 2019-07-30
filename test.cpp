#include <iostream>
#include "Triangular.h"
using namespace std;

int Sum(Triangular &t)
{
    int ret = 0;
    int tmp;
    while (t.next(tmp))
    {
        ret += tmp;
    }
    return ret;
}

int main()
{
    Triangular t(8, 1);
    cout << t;
    return 0;
}