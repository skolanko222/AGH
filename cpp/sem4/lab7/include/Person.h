#pragma once
#include <iostream>

//base class
class Person
{
	protected:
		std::string _name;
	public:
		//constructor of Person
		Person(const char * n) : _name(n) {}
		//virtual print function
		virtual std::ostream & print(std::ostream & o) const {return o << "Person: name: " << _name;}
		//virtual destructor
		virtual ~Person() {std::cout << "~Person ("<<_name<<")\n";}
		//globally overloaded << operator
		friend std::ostream & operator<<(std::ostream & o, const Person & obj)
		{
			return obj.print(o);
		}



};

std::ostream & operator<<(std::ostream & o, const Person & obj);