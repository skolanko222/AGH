#include <iostream>
#include "MyList.h"

using namespace std;

void MyList::add(Element * new_elem)
{
    if(_head == nullptr)
        _head =  new_elem;
    else
    {
        Element * temp = _head;
        while(temp->_next != nullptr) temp = temp->_next;
        temp->_next = new_elem;

    }

}

void MyList::add(const int * new_arr, int size)
{
    int * even_newer = new int [size];
    for(int i = 0; i < size; i++) // huj wie czy ma być czy nie 
        even_newer[i] = new_arr[i];
    Element * new_elem = new Element(even_newer, size);
    this->add(new_elem);

}

bool MyList::isEmpty() const
{
    bool ret;
    _head == nullptr ? ret = true : ret = false;
    return ret;

}

void MyList::print(char * name) const
{
    cout << name << " = ";
    cout << "<";
    Element * temp = _head;
    while(temp != nullptr)
    {
        temp->printElem();
        temp = temp->_next;
    }
    cout << ">" << endl;


}

void MyList::copyRev(MyList * copy)
{
    _head = copy->_head;
}

void MyList::removeFirst()
{
    if(_head == nullptr) return;
    Element * temp = _head;
    _head = _head ->_next;
    delete temp;
}