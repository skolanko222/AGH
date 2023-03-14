#pragma once

#include "Operation.h"
#include <iostream>
#include <string>
#include <cmath>

class VSum : public Operation
{
    public:
        VSum(double a[], const int ilosc): Operation(a,ilosc,"Suma",'+') {}
        double eval() const
        {
            double suma=0;
            for(int i=0; i<_v.size(); i++)
            {
                suma+=_v[i];
            }
            return suma;
        }
};