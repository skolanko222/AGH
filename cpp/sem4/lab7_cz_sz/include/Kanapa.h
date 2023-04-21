#ifndef _KANAPA_H_
#define _KANAPA_H_

#include "Mebel.h"
#include "Lozko.h"
#include "Sofa.h"

class Kanapa final: public Sofa, public Lozko
{
    public:
        Kanapa ( const int& sz, const int& wys, const int& dl, const int& szer_siedziska, const int& szer_spania);
        ~Kanapa() override;
        void print ( std::ostream& os ) const override;
};

#endif // _KANAPA_H_