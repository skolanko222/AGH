#include <iostream>
#include <string>
#pragma once

using namespace std;

class Element
{
    friend class MyList;
    private:
        int * _arr;
        Element * _next;
        int _size;
        static int _count;
        int _count2 = 0;

    public:
        static int getObjects();
        //konstruktor domyslny klasy, inicjalizuje wartosci domsle
        Element() : _arr(nullptr), _next(nullptr), _size(0) {_count++; _count2=_count;}
        //konstruktor klasy, ustawia przekazany wskaznik i rozmiar tablicy
        Element(const int * new_arr, int size) : _arr(new int [size]), _size(size),_next(nullptr) 
        {
            for(int i = 0; i < size; i++) 
                _arr[i] = new_arr[i];_count++; 
            _count2=_count;
        }
        //kopiując
        Element(const Element & cpy) : _arr(new int [cpy._size]), _size(cpy._size),_next(nullptr) 
        {
            for(int i = 0; i < _size; i++) 
                _arr[i] = cpy._arr[i]; 
            _count++; 
            _count2=_count;
        }
        //odwrócony
        static Element addElemRev(const Element & cpy);
        //funkcja wypisujaca tablice bedaca elementem klasy
        void printElem() const;
        //getter prywatnego wskaznika _next
        Element * getNext() const {return _next;}
        //destruktor Elementu
        ~Element() {cout <<"Destruktor Element: "; printElem(); cout << endl; delete [] _arr; }



};