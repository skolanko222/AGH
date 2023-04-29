#pragma once
#include <list>
#include <iostream>
#include <algorithm>

class DzialaniaNaZbiorach
{
	private:
		std::set<Wektor2D> & _set;
		void zamien(const Wektor2D & a)
		{

		}
	public:
		DzialaniaNaZbiorach(std::set<Wektor2D> & obj) : _set(obj) {}
		void WypiszXWiekszeOd(int x) 
		{
			std::for_each(_set.upper_bound(Wektor2D("", x-1, 0)), _set.end(), print);
		}
		void ZamienX(int x, int y) 
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


};