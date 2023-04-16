#include <iostream>
#include "Element.h"
#pragma once
using namespace std;


class MyList
{
    private:
        Element * head;
        Element * tail;
        char * name;
    public:
        MyList() : head(nullptr), tail(nullptr) {};
        ~MyList();
        void append(Element * elem);
        void append(char * name);
        char * getName() const {return name;}
        Element * getHead() const { return head;}
        Element * getLast() const { return tail;}
        bool isEmpty() const;
        void removeFirst();
        void clearList();
        friend void print(const MyList * ptr);
};