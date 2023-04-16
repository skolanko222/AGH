#pragma once
#include <iostream>

using namespace std;


class Element
{
    friend class MyList;
    private:
        const int * _arr;
        int _size;
        Element * _next;
    public:
        Element(const int * new_arr, int size) : _size(size), _arr(new_arr), _next(nullptr) { };
        void printElem() const;
        ~Element(){cout << "Destruktor Element: "; printElem();}


};