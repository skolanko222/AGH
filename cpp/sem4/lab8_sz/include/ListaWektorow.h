#ifndef _LISTA_WEKTOROW_H_
#define _LISTA_WEKTOROW_H_

#include "Wektor2D.h"
#include <list>

class ListaWektorow
{
    public:
        ListaWektorow();
        void Dodaj(Wektor2D* ptr);
        void Wypisz() const;
        void PosortujWedlugX();
        void PosortujWedlugY();
    private:
        std::list<Wektor2D*> _list;
};

#endif