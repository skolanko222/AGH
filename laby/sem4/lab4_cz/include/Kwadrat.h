#pragma once
#include "Ksztalt.h"
#include <iostream>


class Kwadrat : public Ksztalt
{
	private:
		int size;
	public:
		virtual void wypisz(std::ostream &stream) const override
		{
			stream << "Kwadrat o boku: " << size << std::endl;
		}
		virtual std::string polePow() const override
		{
			return std::to_string(size*size);
		}
		Kwadrat(int s) : size(s) {}



};
