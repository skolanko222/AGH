#pragma once
#include <iostream>
#include "Ksztalt.h"

class Kolo : public Ksztalt
{
	public:
		//konstruktor klasy Kolo
		Kolo(double r) : _r(r) {}
		virtual void wypisz(std::ostream &o) const override
		{
			o << "Kolo o promieniu: " << _r << '\n';
		}
		//metoda liczaca pole Kola
		virtual double polePow() const override
		{
			return 3.1415 * _r *_r;
		}
	private:
		double _r;

};