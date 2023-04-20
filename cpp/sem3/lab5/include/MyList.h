#include <iostream>
#include "Element.h"

#pragma once

using namespace std;

class MyList
{
    friend void print(string name, const MyList * list);
    private:
        Element *_head;
    public:
        //domysly konstruktor MyLit
        MyList() : _head(nullptr) {};
        //metoda dolaca element do listy
        void append(Element * new_elem);
        //getter prywatnego wskaznika _head
        Element * getHead() const {return _head;} 
        //metoda dolacza element do list ale kopiujac wartosci
        void append(const int * new_arr,int size); //kopia
        //metoda sprawdza czy lista pusta
        bool isEmpty() const;
        //metoda mopiuje liste w sposob odwrocony, podana jako argument
        void copyRev(MyList * copy);
        //usuwa pierwszy element list i przepina odpowiednio wskaznik _head
        void removeFirst();
        //destruktor MyList
        ~MyList();
};
