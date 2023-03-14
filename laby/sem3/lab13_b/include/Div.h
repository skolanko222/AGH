#pragma once

#include "Operation.h"
#include <iostream>
#include <string>
#include <cmath>

class Div : public Operation
{
    public:
        Div(int a, int b): Operation(a , b, "Dzielenie", '/') {}
        double eval() {return _v[0]/_v[1];}
};