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
        /**
         * @brief Construct a new My List object
         * 
         */
        MyList() : _head(nullptr) {};
        
        /**
         * @brief konstruktor kopiujacy MyList
        */
        MyList(const MyList & cpy)
        {
            _head  = new Element(*(cpy._head));
            Element * temp = _head;
            Element * temp_cpy = cpy._head;

            while(temp)
            {
                if(temp_cpy->_next != nullptr) temp->_next = new Element(*(temp_cpy->_next)); //żeby nie kopiowalo _arr gdy _next == nullptr
                temp = temp->_next;
                temp_cpy = temp_cpy->_next;
            }
        }

        MyList(MyList && mv) : MyList(mv) //konstruktor przenoszący który tak na prawde kopiuje??   
        {
            mv._head = nullptr; //przenosi się 

        }
        /**
         * @brief metoda dodajaca Elementy do listy
         * 
         * @param new_elem 
         */
        void add(Element * new_elem);
        /**
         * @brief Get the Head object - zwraca wskaznik na poczatek listy
         * 
         * @return Element* 
         */
        Element * getHead() const {return _head;} 
        /**
         * @brief metoda dodajaca Elementy do listy - kopiujaca
         * 
         * @param new_arr 
         * @param size 
         */
        void add(const int * new_arr,int size);
        /**
         * @brief funkcja sprawdzajaca czy lista pusta
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty() const;
        //usuwa pierwszy element list i przepina odpowiednio wskaznik _head
        void removeFirst();
        //destruktor MyList
        ~MyList();
        //
        void print(string n) const;
};
