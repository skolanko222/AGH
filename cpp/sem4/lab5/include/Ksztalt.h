#pragma once
#include <iostream>

class Ksztalt
{
	public:
		//wirtualny destruktor klasy bazowej
		virtual ~Ksztalt() {}
		//funkcja czysto wirtualna polimorficznie wypisujaca wymiary ogolnie ksztaltow
		virtual void wypisz(std::ostream &o) const = 0;
		//funkcja czysto wirtualna polimorficznie liczaca pola ksztaltow
		virtual double polePow() const = 0;

};
void wypisz(const Ksztalt & obj)
{	
	obj.wypisz(std::cout);
}