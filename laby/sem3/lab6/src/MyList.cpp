#include <iostream>
#include "MyList.h"

using namespace std;


void MyList::add(Element * cpy)
{
    Element * new_elem = new Element(cpy->_arr,cpy->_size);
    if(_head == nullptr)
        _head = new_elem;
    else
    {
        new_elem->_next = _head;
        _head = new_elem;
    }
}

void MyList::add(const int * new_arr, int size)
{
    Element * new_elem = new Element(new_arr, size);
    if(_head == nullptr)
        _head = new_elem;
    else
    {
        new_elem -> _next = _head;
        _head = new_elem;
    }
}

bool MyList::isEmpty() const
{
    bool ret;
    _head == nullptr ? ret=true : ret=false;

    return ret;
}

void print(string name, const MyList * list)
{
    cout << name << " = <";
    Element *temp = list->getHead();
    while(temp != nullptr)
    {
        temp->printElem();
        temp = temp -> getNext();
    }
    cout << " >" << endl;

}

void MyList::removeFirst()
{
    if(_head == nullptr) return;
    Element *temp = _head;
    _head = temp->_next;
    delete temp;

}

MyList::~MyList()
{
    cout<<"Destruktor MyList" << endl;
    Element * temp = _head;
    while(temp != nullptr)
    {
        delete temp;
        temp = temp->_next;
    }
    _head = nullptr;
    
}

void MyList::print(string n) const
{
    cout << n << " = <";
    Element *temp = getHead();
    if(temp != nullptr){
        while(temp != nullptr)
        {
            temp->printElem();
            if(temp->_next != nullptr)
                cout << " ";
            temp = temp -> getNext();
        }
    }
    cout << ">" << endl;

}