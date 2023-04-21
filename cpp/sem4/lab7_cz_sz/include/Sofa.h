#ifndef _SOFA_H_
#define _SOFA_H_

#include "Mebel.h"

class Sofa : virtual public Mebel
{
    public:
        Sofa ( const int& sz, const int& wys, const int& dl, const int& szer_siedziska);
        virtual ~Sofa () override;
        virtual void print ( std::ostream& os ) const override;
    protected:
        int _SzerSiedziska;
};

#endif // _SOFA_H_