#include <iostream>
#include "Named.h"

void operator>> (std::string str, Named& a)
{
    a.nazwaSet(str);  
}