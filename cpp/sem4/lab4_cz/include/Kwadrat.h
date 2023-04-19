#pragma once
#include "Ksztalt.h"
#include <iostream>


class Kwadrat : public Ksztalt
{
	private:
		int size;
	public:
		void wypisz(std::ostream &stream) const 
		{
			stream << "Kwadrat o boku: " << size << std::endl;
		}
		virtual std::string polePow() const override
		{
			return std::to_string(size*size);
		}
		Kwadrat(int s) : size(s) {}



};
