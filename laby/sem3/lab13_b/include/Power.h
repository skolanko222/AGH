#pragma once

#include "Operation.h"
#include <iostream>
#include <string>
#include <cmath>

class Power : public Operation
{
    public:
        Power(int a, int b): Operation(a,b,"Potega",'^') {}
        double eval() {return pow(_v[0],_v[1]);}
};