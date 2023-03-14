#include <iostream>
#include "Element.h"

using namespace std;

void Element::printElem() const
{

    cout << "(";
    for(int i = 0; i < _size; i++)
    {
        cout << _arr[i];
        if(i != _size - 1)
            cout << ",";
    }
    cout << ")";
}