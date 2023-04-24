#include <iostream>
#include <string>
#include "Student.h"
#include "Faculty.h"

class Grade : public Student, public Faculty
{
	public:
		//constructor of Grade
		Grade(const char * n, unsigned int id, const char * f) : Person(n), Student(n, id), Faculty(n, f) {}
		//overrided print function
		virtual std::ostream & print(std::ostream & o) const override
		{
			o << "jako "; Person::print(o);
			o << "\njako "; Student::print(o);
			o << "\njako "; Faculty::print(o);
			return o;
		}
		//overrided destrucor
		virtual ~Grade() override {std::cout << "~Grade\n";}

};