#pragma once
#include <list>
#include <iostream>
#include <algorithm>
class Wektor2D;

bool cmpX(const Wektor2D * a,const Wektor2D * b)
{
	return a->getX() < b->getX();
}
bool cmpY(const Wektor2D * a,const Wektor2D * b)
{
	return a->getY() < b->getY();
}

class ListaWektorow
{
	private:
		std::list<Wektor2D*> _vec;

	public:
		ListaWektorow() {}
		void Dodaj(Wektor2D * v) {_vec.push_back(v);}
		void Wypisz() 
		{
			std::for_each(_vec.cbegin(),_vec.cend(),print);
		}
		void PosortujWedlugX() {_vec.sort(cmpX);}
		void PosortujWedlugY() {_vec.sort(cmpY);}

};