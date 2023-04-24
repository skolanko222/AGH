#pragma once
#include <iostream>
#include <string>
#include "Person.h"


class Faculty : virtual public Person
{
	private:
		std::string _faculty;
	public:
		//constructor of Faculty
		Faculty(const char * n, const char * f) : Person(n), _faculty(f) {}
		//overrided print function
		virtual std::ostream & print(std::ostream & o) const override{o << "Faculty: "; Person::print(o); return o << " spec: " << _faculty;}
		//overrided destrucor
		~Faculty() {std::cout << "~Faculty\n";}

};