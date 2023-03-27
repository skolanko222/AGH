#pragma once
#include <iostream>


class Ksztalt
{
	public:
		virtual void wypisz(std::ostream &stream) const=0;
		virtual std::string polePow() const = 0;


};
void wypisz(const Ksztalt &a)
{
	a.wypisz(std::cout);
}