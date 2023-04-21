#ifndef _LOZKO_H_
#define _LOZKO_H_

#include "Mebel.h"

class Lozko : virtual public Mebel
{
    public:
        Lozko ( const int& sz, const int& wys, const int& dl, const int& szer_spania);
        virtual ~Lozko() override;
        virtual void print ( std::ostream& os ) const override;
    protected:
        int _SzerSpania;
};

#endif // _LOZKO_H_