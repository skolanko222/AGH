#ifndef _REC_H_
#define _REC_H_	

#include <iostream>
#include "Shape.h"

class Rec: public Shape
{
public:
	double Pole() const;
	void rys(void) const;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const
{
	std::cout << "Pole_z_Rec ";
	return _x * _y;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::rys(void) const
{
	std::cout << "Rysuj CRrec\n";
}

/////////////////////////////////////////////////////////////////////////
#endif