#pragma once
#include "Wymierne.h"

#include <iostream>

class Wektor
{
    public:
        /**
         * @brief Construct a new Wektor object - konstruuje wektor zlozony z 3 obiektow typu Wymierne 
         * 
         */
        Wektor() : _x(), _y(), _z() {};
        /**
         * @brief setter _x - ustawia pierwsza wspolrzedna wektora
         * 
         * @param l 
         * @param m 
         * @return Wektor& 
         */
        Wektor &SetX(int l, int m)
        {
            Wymierne ret(l,m);
            _x = ret;
            return *this;
        }
        /**
         * @brief setter _x - ustawia druga wspolrzedna wektora
         * 
         * @param l 
         * @param m 
         * @return Wektor& 
         */
        Wektor &SetY(int l, int m)
        {
            Wymierne ret(l,m);
            _y = ret;
            return *this;
        }
        /**
         * @brief setter _x - ustawia trzecia wspolrzedna wektora
         * 
         * @param l 
         * @param m 
         * @return Wektor& 
         */
        Wektor &SetZ(int l, int m)
        {
            Wymierne ret(l,m);
            _z = ret;
            return *this;
        }
        /**
         * @brief funkcja wypisujaca wektor
         * 
         */
        void print();
        /**
         * @brief getter pierwszej wspolrzednej wektora
         * 
         * @return Wymierne& 
         */
        Wymierne & getX() {return _x;}
        /**
         * @brief dziala jako konwerter int -> wektor
         * 
         * @param x 
         */
        Wektor(int x) : _x(x), _y(x), _z(x) {};
        /**
         * @brief dziala jako konwerter Wymierne -> wektor
         * 
         * @param x 
         */
        Wektor(Wymierne x) : _x(x), _y(x), _z(x) {};
        /**
         * @brief getter pierwszego elementu wektora
         * 
         * @return Wymierne 
         */
        Wymierne X() {return _x;}

    private:
        Wymierne _x;
        Wymierne _y;
        Wymierne _z;

};