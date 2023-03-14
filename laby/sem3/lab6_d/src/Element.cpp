#include <iostream>
#include "Element.h"

using namespace std;

int Element::_count;

int Element::getObjects()
{
    return _count;
}

void Element::printElem() const
{
    cout << "(";
    for(int i = 0; i < _size; i++)
    {   
        cout << _arr[i];
        if(i != (_size - 1))
            cout << ",";   
    }
    cout << ")";
}

Element Element::addElemRev(const Element & cpy)
{
    int * arr = new int [cpy._size];
    for(int i = 0; i < cpy._size; i++)
    {
         arr[i] = cpy._arr[cpy._size - i - 1];
    }
    Element ret(arr,cpy._size);
    return ret;
}
