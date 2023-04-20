
#pragma once

#include "Operation.h"
#include <iostream>
#include <string>
#include <cmath>


class Power : public Operation
{
    public:
        Power(double a, double b) : Operation("Potega",'^', std::vector<double>{a,b}) {}
        virtual double eval() const 
        {
            return pow(_arr[0],_arr[1]);
        }


};