#pragma once
#include <iostream>
#include "Mebel.h"

class Lozko : virtual public Mebel
{
	private:
		short _sleepSize;
		const static char * name;
	public:
		Lozko(short x,short y, short z, short s) : Mebel(x,y,z), _sleepSize(s) {};
		const char * getName() const override {return name;}
		virtual std::string getInfo() const override
		{
			std::string temp = " szer_spania: ";
			temp += std::to_string(_sleepSize);
			return temp;
		}
		~Lozko() {std::cout << "~Lozko\n";};


};