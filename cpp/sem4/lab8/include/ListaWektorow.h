#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>


class Wektor2D;

//bool cmpX(Wektor2D * a, Wektor2D * b) { return a->_x < b->_x; }


class ListaWektorow
{
	private:
		std::list<Wektor2D *> _arr;
		static struct
		{
			bool operator()(Wektor2D * a, Wektor2D * b) { return a->_x < b->_x; }
		}cmpX;
		static struct
		{
			bool operator()(Wektor2D * a, Wektor2D * b) { return a->_y < b->_y; }
		}cmpY;
	
	public:
		ListaWektorow() {}
		void Dodaj(Wektor2D * temp) {_arr.push_back(temp);}
		void Wypisz() 
		{
			std::for_each(_arr.begin(),_arr.end(),print);
		}
		void PosortujWedlugX()
		{
			_arr.sort(cmpX);
		}
		void PosortujWedlugY()
		{
			_arr.sort(cmpY);
		}


};