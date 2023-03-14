#include <iostream>
#include "Operation.h"


std::ostream &operator<<(std::ostream &o,const Operation &a)
{
    a.print();
    o << " = ";
    return o << a.eval() << std::endl;
    
}