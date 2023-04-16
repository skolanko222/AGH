#pragma once

#include <iostream>

class Wymierne
{
    public:
        /**
         * @brief Construct a new Wymierne object - uniwersalny
         * 
         * @param l 
         * @param m 
         */
        Wymierne(int l = 0, int m = 1) : _licznik(l), _mianownik(m) {};
        /**
         * @brief funkcja wypisujaca ulamek w postaci: "1/2"
         * 
         */
        void print();
        /**
         * @brief konwertor jawny z obiektu Wymiernego do doubla
         * 
         * @return double 
         */
        explicit operator double () {return ((double)_licznik )/((double)_mianownik );}
        /**
         * @brief statyczna metoda konwertujaca obiekt typu Wymierne do doubla
         * 
         * @param x 
         * @return double 
         */
        static double ToDouble(Wymierne x) {return ((double)x._licznik )/((double)x._mianownik );}
        
    private:
        int _licznik;
        int _mianownik;

};