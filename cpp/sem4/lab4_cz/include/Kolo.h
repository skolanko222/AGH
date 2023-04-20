#pragma once
#include "Ksztalt.h"
#include <iostream>


class Kolo : public Ksztalt
{
	private:
		int radius;
	public:
		virtual void wypisz(std::ostream &stream) const override
		{
			stream << "Kolo o promieniu: " << radius << std::endl;
		}
		virtual std::string polePow() const override
		{
			return std::to_string(3.1415*radius*radius);
		}
		Kolo(int s) : radius(s) {}


};