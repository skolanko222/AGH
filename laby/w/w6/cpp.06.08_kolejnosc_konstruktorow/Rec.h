#ifndef _CREC_H_
#define _CREC_H_	

#include <iostream>

#include "Shape.h"

namespace OOP {
class Rec: public Shape {
public:
	Rec()
	{std::cout << "Konstruktor Rec\n"; }

	~Rec()
	{std::cout << "Destruktor Rec\n"; }

	double Pole() const;
	void rys(void) const;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const {
	return _x * _y;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::rys(void) const {
	std::cout << "Rysuj CRrec\n";
}

}//end of namespace OOP
#endif