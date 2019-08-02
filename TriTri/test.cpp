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
    char ch;
    bool more = true;
    while (more)
    {
        cout << "Enter value: ";
        int ival;
        cin >> ival;

        bool is_elem = Triangular::is_elem(ival);
        cout << ival << (is_elem ? " is " : " is not ") << "an element in the Triangular series.\n"
             << "Another value?(y/n)";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
        {
            more = false;
            cout<< "Bye~~~\n";
        }
    }
}