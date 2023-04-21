#ifndef _MEBEL_H_
#define _MEBEL_H_

#include <iostream>
#include <string>

class Mebel
{
    public:
        Mebel ( const int& sz, const int& wys, const int& dl);
        virtual ~Mebel();
        virtual void print(std::ostream& os) const;
    protected:
        int _W;
        int _H;
        int _L;
};

std::ostream& operator<<(std::ostream& os, const Mebel& m);

#endif // _MEBEL_H_