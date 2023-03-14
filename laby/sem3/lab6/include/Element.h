#include <iostream>
#include <string>
#include <utility>
#pragma once

using namespace std;

class Element
{
    friend class MyList;
    friend int getObjects();
    private:
        int * _arr;
        Element * _next = nullptr;
        int _size;
        static int _count;
        int _count2;

    public:
        /**
         * @brief Construct a new Element object - konstruktor domyslny
         * 
         */
        Element() : Element(nullptr,0) {};
        /**
         * @brief Construct a new Element object - konstruktor tworzacy nowa tablice
         * 
         * @param new_arr 
         * @param size 
         */
        Element(const int * new_arr, int size) : _arr(new int [size]), _size(size),_next(nullptr) 
        {
            if(new_arr != nullptr){
                for(int i = 0; i < size; i++) 
                    _arr[i] = new_arr[i];
            _count2 = ++_count;
            }
        }

        /**
         * @brief konstruktor kopiujacy obiektu typue Element 
         * 
         * @param cpy 
         */
        Element(const Element & cpy) : Element(cpy._arr, cpy._size)
        {
            cout << "Konstruktor kopiujacy " << _count2 << endl;

        }

        /**
         * @brief Funkcja wypisujaca elementy listy
         * 
         */
        void printElem() const;

        /**
         * @brief Construct a new Element object - konstruktor przenoszacy
         *          
         * @param mv 
         */
        Element(Element && mv) : Element(mv._arr, mv._size) 
        {
            cout << "Konstruktor przenoszacy " << _count2 << endl;
            mv._arr = nullptr; //usuwamy wskaźnik by free() 2 razy nie zadzialalo!!!!
            mv._next = nullptr;
            mv._size = 0;
        }

        /**
         * @brief Get the Next object - getter kolejnego elementu listy
         * 
         * @return Element* 
         */
        Element * getNext() const {return _next;}
        /**
         * @brief Destroy the Element object - destruktor elementu
         * 
         */
        ~Element()
        {  
            if(_arr != nullptr){
                delete [] _arr; 
                _count--;
            }
            _arr = nullptr;
            cout << "Destruktor Element" << endl;}

        static Element addElemRev(const Element & elem);



};

int getObjects();