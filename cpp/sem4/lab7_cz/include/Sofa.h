#pragma once
#include <iostream>
#include "Mebel.h"

class Sofa : virtual public Mebel
{
	private:
		short _seat;
		const static char * name;
	public:
		Sofa(short x,short y, short z, short s) : Mebel(x,y,z), _seat(s) {};
		Sofa(short s) : _seat(s) {};
		const char * getName() const override {return name;}
		virtual std::string getInfo() const override
		{
			std::string temp = " siedzisko: ";
			temp += std::to_string(_seat);
			return temp;
		}
		~Sofa() {std::cout << "~Sofa\n";};


};