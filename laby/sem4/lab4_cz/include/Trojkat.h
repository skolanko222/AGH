#pragma once
#include "Ksztalt.h"
#include <iostream>
#include <cmath>


class Trojkat : public Ksztalt
{
	private:
		int A;
		int B;
		int C;
	public:
		virtual void wypisz(std::ostream &stream) const override
		{
			stream << "Trojkat o bokach:" << A << ' ' << B << ' '<< C  << std::endl;
		}
		virtual std::string polePow() const override
		{
			float x = static_cast<float>(A + B + C)/2.;
			return std::to_string(std::sqrt( x*(x-A)*(x-B)*(x-C) ) );
		}
		Trojkat(int a, int b, int c) : A(a), B(b), C(c) {}


};