#include <iostream>
#include "Element.h"

using namespace std;

int Element::_count = 0;

void Element::printElem() const
{
    cout << "Id_" << _count2 << " (";
    if(_arr != nullptr)
    {
        for(int i = 0; i < _size; i++)
        {   
            cout << _arr[i];
            if(i != (_size - 1))
                cout << ",";   
        }
    }
    cout << ")";
}

Element Element::addElemRev(const Element & elem)
{

    int *arr = new int [elem._size];
    for(int i = 0; i < elem._size; i++)
    {
        arr[i] = elem._arr[elem._size - i - 1];    
    }
    Element ret = Element(elem);
    ret._arr = arr;
    return ret;

}

int getObjects()
{
    return Element::_count;
}
