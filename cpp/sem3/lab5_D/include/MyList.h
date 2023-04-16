#pragma once
#include <iostream>

#include "Element.h"

using namespace std;

class MyList
{

    private:
        Element * _head;

    public:
        MyList() : _head(nullptr) {};
        ~MyList() { };
        void add(Element * new_elem);
        Element * getHead() const {return _head;}
        void add(const int * new_arr, int size);
        bool isEmpty() const ;
        void print(char * name) const;
        void copyRev(MyList * copy);
        void removeFirst();


};