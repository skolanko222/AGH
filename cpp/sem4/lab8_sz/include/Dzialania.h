#ifndef _DZIALANIA_H_
#define _DZIALANIA_H_

#include "Wektor2D.h"

class DzialaniaNaZbiorach
{
    public:
        DzialaniaNaZbiorach(const std::set<Wektor2D>& set);
        void WypiszXWiekszeOd(const int& x) const;
        void ZamienX(const int& to_change, const int& val);
    private:
        std::set<Wektor2D> _set;
};

#endif