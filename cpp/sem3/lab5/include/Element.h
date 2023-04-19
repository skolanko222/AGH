#include <iostream>
#include <string>
#pragma once

using namespace std;

class Element
{
    friend class MyList;
    int getObjects(){return _count;}
    private:
        int * _arr;
        Element * _next;
        int _size;
        static int _count;

    public:
        //konstruktor domyslny klasy, inicjalizuje wartosci domsle
        Element() : _arr(nullptr), _next(nullptr), _size(0) {};
        //konstruktor klasy, ustawia przekazany wskaznik i rozmiar tablicy
        Element(const int * new_arr, int size): _arr(new int [size]), _size(size),_next(nullptr) {for(int i = 0; i < size; i++) _arr[i] = new_arr[i];}
        //funkcja wypisujaca tablice bedaca elementem klasy
        void printElem() const;
        //getter prywatnego wskaznika _next
        Element * getNext() const {return _next;}
        //destruktor Elementu
        ~Element() {cout <<"Destruktor Element: "; printElem(); cout << endl;}



};