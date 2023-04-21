#include "Kanapa.h"

Kanapa::Kanapa(const int& sz, const int& wys, const int& dl, const int& szer_siedziska, const int& szer_spania) : 
    Mebel ( sz, wys, dl ), Sofa ( sz, wys, dl, szer_siedziska ), Lozko ( sz, wys, dl, szer_spania )
{}

Kanapa::~Kanapa() 
{
    std::cout << "~Kanapa" << std::endl;
}

void Kanapa::print(std::ostream& os) const 
{
    os << "jako "; Mebel::print ( os ); std::cout << std::endl;
    os << "jako "; Sofa::print ( os ); std::cout << std::endl;
    os << "jako "; Lozko::print ( os );
}

