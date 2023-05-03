#include "ListaWektorow.h"

ListaWektorow::ListaWektorow() 
{ std::cout << "Nieposortowana" << std::endl; }

void ListaWektorow::Dodaj(Wektor2D* ptr)
{
    _list.emplace_back(ptr);
}

void ListaWektorow::Wypisz() const
{
    std::for_each(_list.begin(), _list.end(), 
                  [](const Wektor2D* ptr)
                  {std::cout << *ptr << std::endl;});
}

void ListaWektorow::PosortujWedlugX() 
{
    std::cout << "Posortowana wedlug wsprzednych X" << std::endl;
    _list.sort([](const Wektor2D *a, const Wektor2D *b) 
               {return a->getX() < b->getX();});
}

void ListaWektorow::PosortujWedlugY() 
{
    std::cout << "Posortowana wedlug wsprzednych Y" << std::endl;
    _list.sort([](const Wektor2D *a, const Wektor2D *b) 
               {return a->getY() < b->getY();});
}