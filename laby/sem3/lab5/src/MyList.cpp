#include <iostream>
#include "MyList.h"

using namespace std;


void MyList::append(Element * new_elem)
{
    if(_head == nullptr)
        _head = new_elem;
    else
    {
        Element * temp = _head;
        while(temp->_next != nullptr) temp = temp->_next;
        temp-> _next = new_elem;
    }
}

void MyList::append(const int * new_arr, int size)
{
    Element * new_elem = new Element(new_arr, size);
    if(_head == nullptr)
        _head = new_elem;
    else
    {
        Element * temp = _head;
        while(temp->_next != nullptr) temp = temp->_next;
        temp-> _next = new_elem;
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

void MyList::copyRev(MyList * copy)
{ 
    Element * temp = copy->_head;
    cout << "1";
    while(temp != nullptr)
    {
        this->append(temp);
        temp = temp ->_next;
    }    

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
    
}
