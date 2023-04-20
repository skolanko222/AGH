#include "MyList.h"
#include <iostream>

using namespace std;

MyList::~MyList()
{
    cout << "Destruktor MyList" << endl;
    clearList();
}

void MyList::append(Element * elem)
{
    if(head == nullptr && tail == nullptr)
    {
        head = elem;
        tail = elem;
    }
    else
    {
        tail->next = elem;
        tail = elem;
    }


}
void MyList::append(char * name)
{
    Element *temp = new Element(name);
    if(head == nullptr && tail == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }

}
bool MyList::isEmpty() const
{
    bool ret;
    head ? ret = false : ret = true;
    return ret;

}

void MyList::removeFirst()
{
    Element * temp = head;
    if(head != nullptr)
    {
        head = head->next;
        delete temp;
    }

}

void MyList::clearList()
{
    Element * temp = head;
    while(temp)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }

}

void print(const MyList * ptr)
{
    Element * temp = ptr->head;
    cout << "[";
    while(temp != nullptr)
    {
        cout << temp->getName();
        Element * next = temp->getNext();
        if(next != nullptr)
            cout << " ";
        temp = next;
    }
    cout << "]" << endl;

}