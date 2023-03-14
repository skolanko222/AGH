#include <iostream>
#include "Point.h"

std::ostream& operator<<(std::ostream& out, const Point& a)
{
    return out << a.Name() << " ["<< a.xGet() << "," <<a.yGet() << "]";
}

void operator>> (std::string str, Point& a)
{
    a.nazwaSet(str);  
}
