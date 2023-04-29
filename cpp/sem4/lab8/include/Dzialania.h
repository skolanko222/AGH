#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <set>

class DzialaniaNaZbiorach
{
	private:
		std::set<Wektor2D> &_set;
	public:
		// konstruktor
		DzialaniaNaZbiorach(std::set<Wektor2D> &o) : _set(o) {}
		// metda wypisujaca elementy zbioru wieksze od x
		void WypiszXWiekszeOd(int x) 
		{
			Wektor2D temp("",x-1,0);
			std::for_each(_set.upper_bound(temp),_set.end(),print2);
		}

		void ZamienX(int x, int y) 
		{
			auto result = std::find(_set.begin(), _set.end(),Wektor2D("",x));
			if(result != std::end(_set))
			{
				Wektor2D temp(result->_str,y,result->_y);
				_set.erase(result);
				_set.emplace(temp);
			}
		}

};