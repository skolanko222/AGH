#pragma once
#include "Ksztalt.h"
#include <iostream>
#include <cmath>

class Trojkat : public Ksztalt
{
	public:
		//konstruktor klasy Trojkat
		Trojkat(double a, double b, double c) : _a(a), _b(b), _c(c) {}
		//metoda wypisujaca boki Trojkata
		virtual void wypisz(std::ostream &o) const override
		{
			o << "Trojkat o bokach: " << _a << ' ' << _b << ' ' << _c << '\n';
		}
		//metoda liczaca pole Trojkata
		virtual double polePow() const override
		{
			double x = (_a+_b+_c)/2.;
			return sqrt(x*(x-_a)*(x-_b)*(x-_c));
		}
	private:
		double _a;
		double _b;
		double _c;
};