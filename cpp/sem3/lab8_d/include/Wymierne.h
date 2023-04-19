#pragma once

#include <iostream>
namespace rls
{
    class Wymierne
    {
        public:
            friend class Double;
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
            void print(const char * n) const; 
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
            int simplify(const int x, const int y) const;
            friend Wymierne pomnoz(const Wymierne &x, const Wymierne &y);
            //explicit operator double() {return _licznik/_mianownik;}
            static Wymierne pomnoz(const Wymierne &x, const Wymierne &y);
            void setM(int x){_licznik = x;}
            int getL(){return _licznik;}
            int getM(){return _mianownik;}

            
            
        private:
            int _licznik;
            int _mianownik;

    };
    Wymierne pomnoz(const Wymierne &x, const Wymierne &y);
}

int nwd(int m, int n);