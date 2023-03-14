#include <iostream>
#pragma once


    
    class Double
    {
        private:
            double _x;
            static int _licz;
        public:
            Double (double x): _x(x) {}
            friend void print (const Double &x);

            void print()
            {
                
            }
            void setx(const Double &x)
            {

            }
            Double(wymierne::Wymierne x) : _x(x.getL()/x.getM()) {}
            


    };
    int Double::_licz=0;

    void print (const Double &x)
    {
        Double::_licz++;
        std::cout << Double::_licz << std::endl;
    }




