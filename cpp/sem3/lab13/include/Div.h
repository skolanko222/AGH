#pragma once

#include "Operation.h"
#include <iostream>
#include <string>
#include <vector>


class Div : public Operation
{
    public:
        Div(double a, double b) : Operation("Dzielenie",'/', std::vector<double>{a,b}) 
        {
            
        }
        virtual double eval() const 
        {
            return _arr[0]/_arr[1];
        }

};