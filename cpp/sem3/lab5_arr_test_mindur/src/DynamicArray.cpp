#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray() 
:capacity(10),arrPtr(new int [capacity]), lenght(0)
{
    for(int i=0; i<capacity; i++)
        arrPtr[i]=0;

}

DynamicArray::~DynamicArray()
{
    delete [] arrPtr;
}

int DynamicArray::size() const
{
    return lenght;
}

void DynamicArray::print() const
{
    cout << "[";
    for(int i = 0; i < lenght; i++)
        cout << arrPtr[i] << ", ";
    cout << "]" << "len: " << lenght << " capacity: " << capacity << endl;

}   

void DynamicArray::add(int value, int index)
{
    if(index < capacity)
    {
        arrPtr[index] = value;
        lenght = index + 1;
    }
    else
    {
        capacity = 10 + index;
        int * newArr = new int [capacity];
        for(int i = 0; i < lenght; i++)
        {
            newArr[i] = arrPtr[i];
        }
        for(int i = lenght; i < capacity; i++)
        {
            newArr[i] = 0;
        }
        newArr[index] = value;
        delete [] arrPtr;
        lenght = index + 1;
        arrPtr = newArr;

    }

}