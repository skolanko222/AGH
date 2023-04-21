#pragma once
#include <iostream>
#include "Sofa.h"
#include "Lozko.h"

class Kanapa : public Sofa, public Lozko
{
	private:
		const static char * name;
	public:
		Kanapa(short x,short y, short z, short si, short sp) : Sofa(x,y,z,si),  Lozko(x,y,z,sp), Mebel(x,y,z) {}
		virtual const char* getName() const  {return name;} 
		virtual std::string getInfo() const 
		{
			// no i przypał
			std::string jako1 = "\njako ";
			jako1 += Sofa::getName();
			jako1 += " ";
			jako1 += mebelInfo();
			jako1 += Lozko::getInfo();
			jako1 += " ";
		    std::string jako2 = "\njako ";
			jako2 += Sofa::getName();
			jako2 += " ";
			jako2 += mebelInfo();
			jako2 += Lozko::getInfo();
			jako1 += jako2;
			return jako1;
		}

		~Kanapa() {std::cout << "~Kanapa\n";};


};