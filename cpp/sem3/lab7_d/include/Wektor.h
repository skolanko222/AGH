#pragma once

#include <iostream>
#include "Wymierne.h"

using namespace std;


class Wektor
{
    private:
        Wymierne _x;
        Wymierne _y;
        Wymierne _z;
    public:

        Wektor() : _x(0), _y(0), _z(0) {};
        Wektor SetX(int l, int m) 
        {
            this->_x.setLicznik(l);
            this->_x.setMianownik(m);
            return *this;
        }
        Wektor SetY(int l, int m) 
        {
            this->_y.setLicznik(l);
            this->_y.setMianownik(m);
            return *this;
        }
        Wektor SetZ(int l, int m) 
        {
            this->_z.setLicznik(l);
            this->_z.setMianownik(m);
            return *this;
        }
        Wymierne getX()
        {
            return _x;
        }
        void print();

};