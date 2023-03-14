#include <iostream>
#include "Wektor.h"

using namespace std;

void Wektor::print()
{
    cout << "[";
    _x.print(false);
    cout << ", ";
    _y.print(false);
    cout << ", ";
    _z.print(false);
    cout << "]" << endl;

}