#pragma once
#include <iostream>
#include "Ksztalt.h"


class Kwadrat : public Ksztalt
{
	public:
		//konstruktor klasy Ksztalt
		Kwadrat(double bok) : _a(bok) {}
		virtual void wypisz(std::ostream &o) const override
		{
			o << "Kwadrat o boku: " << _a << '\n';
		}
		//metoda liczaca pole Trojkata
		virtual double polePow() const override
		{
			return _a*_a;
		}
	private:
		double _a;
};