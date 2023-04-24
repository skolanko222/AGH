#pragma once
#include <iostream>
#include <string>
#include "Person.h"


class Student : virtual public Person
{
	private:
		unsigned int _id;
	public:
		//constructor of student
		Student(const char * n, unsigned int id) : Person(n), _id(id) {}
		//overrided print function
		virtual std::ostream & print(std::ostream & o) const override {o << "Student: "; Person::print(o);return o <<" id: " << _id;}
		//overrided destrucor
		~Student() {std::cout << "~Student (" << _name <<", " << _id << ")\n";}
};