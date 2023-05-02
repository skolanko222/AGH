#include "Dzialania.h"

DzialaniaNaZbiorach::DzialaniaNaZbiorach(const std::set<Wektor2D>& set) :
 _set(set) {}

void DzialaniaNaZbiorach::WypiszXWiekszeOd(const int& x) const
{
    std::for_each(_set.upper_bound(Wektor2D("", x-1, 0)), _set.end(), 
                  [](const Wektor2D& p) 
                  { std::cout << p << std::endl; });
}

void DzialaniaNaZbiorach::ZamienX(const int& to_change, const int& val)
{
    auto it = m_Zbior.find(X);
    try
    {
        Wektor2D tmp = *it;
        tmp.SetX(nX);
        m_Zbior.erase(it);
        m_Zbior.insert(tmp);
    }
    catch(const std::bad_alloc& e) { }
 }