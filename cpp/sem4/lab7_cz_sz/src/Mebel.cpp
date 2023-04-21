#include "Mebel.h"

Mebel::Mebel(const int& sz, const int& wys, const int& dl) : 
    _W(sz), _H(wys), _L(dl)
{}

Mebel::~Mebel() 
{
    std::cout << "~Mebel" << std::endl;
}

void Mebel::print(std::ostream& os) const 
{
    os << "Mebel: sz: " << _W << " wys: " << _H << " dl: " << _L << " ";
}

std::ostream& operator<<(std::ostream& os, const Mebel& m) 
{
    m.print(os);
    return os;
}