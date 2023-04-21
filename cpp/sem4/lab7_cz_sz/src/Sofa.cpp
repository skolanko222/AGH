#include "Sofa.h"

Sofa::Sofa(const int& sz, const int& wys, const int& dl, const int& szer_siedziska) : 
    Mebel(sz, wys, dl), _SzerSiedziska(szer_siedziska)
{}

Sofa::~Sofa() 
{
    std::cout << "~Sofa" << std::endl;
}

void Sofa::print(std::ostream& os) const 
{
    os << "Sofa: ";
    Mebel::print(os);
    os << "siedzisko: " << _SzerSiedziska;
}
