#include <iostream>
#include "Wektor.h"

using namespace std;


void Wektor::print()
{
    cout << "[";

    _x.print();
    cout << ", ";
    _y.print();
    cout << ", ";
    _z.print();

    cout << "]" << endl;

    return;
}