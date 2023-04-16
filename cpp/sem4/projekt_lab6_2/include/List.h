#pragma once
#include <iostream>
#include "Data.h"

class Data;
class IntData;
class StringData;

class List
{
    private:
        Data* _head = nullptr;
    public:
        List() {}

        ~List() 
        {
            while(_head)
            {
                Data *temp = _head->getNext();
                delete(_head);
                _head = temp;
            }
        }

        List(const List & a) 
        {
            
        }

        List(const List && a) {} 

        enum _moment{Begin, End};

        List & insert(const IntData &a, const List::_moment b = List::End) 
        {
            if(b == List::Begin)
            {
                Data * new_data = new IntData(a.getValue(), _head);
                _head = new_data;
                return *this;
            }
            else
            {
                Data *temp = _head;
                while(temp->getNext()) 
                    temp = temp->getNext();
                Data * new_data = new IntData(a.getValue());
                temp->setNext(new_data);
                return *this;
            }
        }

        List & insert(const StringData &a, const List::_moment b = List::End) 
        {
            if(b == List::Begin)
            {
                Data * new_data = new StringData(a.getValue(), _head);
                _head = new_data;
                return *this;
            }
            else
            {
                Data *temp = _head;
                while(temp->getNext()) 
                    temp = temp->getNext();
                Data * new_data = new StringData(a.getValue());
                temp->setNext(new_data);
                return *this;
            }
        }

        void print()
        {
            std::cout << "[";
            _head->print(std::cout);
            std::cout << "\b\b]" << std::endl;
        }


};
