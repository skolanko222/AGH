#pragma once

#include <iostream>

using namespace std;


class Wymierne
{
    private:
        int _licznik;
        int _mianownik;
    
    public:
        Wymierne(int l, int m) : _licznik(l), _mianownik(m) {};
        Wymierne(int l) : _licznik(l), _mianownik(1) {};
        void setLicznik(int l) {_licznik = l;}
        void setMianownik(int m) {_mianownik = m;}
        operator double()
        {   
            return (double)_licznik/(double)_mianownik;
        }
        static double ToDouble(Wymierne temp)
        {
            return (double)temp._licznik/(double)temp._mianownik;
        }

        void print(bool t = true);


};