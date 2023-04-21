#include "Lozko.h"

Lozko::Lozko(const int& sz, const int& wys, const int& dl, const int& szer_spania) :
    Mebel(sz, wys, dl), _SzerSpania(szer_spania)
{}

Lozko::~Lozko()
{
    std::cout << "~Lozko" << std::endl;
}

void Lozko::print(std::ostream& os) const
{
    os << "Lozko: ";
    Mebel::print(os);
    os << "sz.pania: " << _SzerSpania;
}