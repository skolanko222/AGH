
#pragma once

#include "Operation.h"
#include <iostream>
#include <string>
#include <vector>

class VSum : public Operation
{
    public:
        VSum(double *a, int b) : Operation("Dodawaine",'+', std::vector<double>(b)) 
        {
            std::vector<double> num(a[0],a[b]);
            _arr = num;

        }

        virtual double eval() const 
        {
            double sum = 0;
            for(double i : _arr)
                sum+=i;
            return sum;
        }


};