#include <iostream>
#pragma once
using namespace std;


class Element
{

    private:
        char * data;
        Element * next;

    public:
        Element(char * new_data) : data(new_data), next(nullptr) {};
        ~Element();
        char * getName();
        void printName();
        Element * getNext();




};