#ifndef _CREC_H_
#define _CREC_H_	

#include <iostream>
#include <string>

#include "Shape.h"

class Rec : public Shape {
public:
	Rec(double x = 0, double y = 0) : Shape(x, y)
	{ }

	Rec(const Rec& K) : Shape(K) {
		std::cout << __PRETTY_FUNCTION__ << std::endl; 

		ptr = new std::string;
		if(K.ptr)
			*ptr = *K.ptr;

	}

	Rec& operator=(const Rec& h){
		std::cout << __PRETTY_FUNCTION__ << std::endl; 
		if (this == &h)
			return *this;

		Shape::operator=(h);

		if(h.ptr) {
			if(!ptr)
				ptr = new std::string;
			*ptr = *h.ptr;
		}
		return *this;
	}

	~Rec(){
		delete ptr;
	}

	double Pole() const;

private:
	std::string *ptr = nullptr; //c++ 11

};


/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const
{
	return m_x * m_y;
}
#endif