#include "Operation.h"

std::ostream &operator<<(std::ostream &o, const Operation & x)
{

    x.print();
    o << std::endl;

}
