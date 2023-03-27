#ifndef _RecLBL_H_
#define _RecLBL_H_
	
#include <iostream>
#include "Rec.h"

#include <iostream>

namespace OOP
{
class RecLbl : public Rec
{
public:
	RecLbl(double x = 0, double y = 0, double a = 1, double b = 1) : Rec(x, y, a, b)
	{}

	RecLbl(const std::string& s) : RecLbl() //c++11
	{ m_ptrOpis = s ; }

	void printLbl(){
		std::cout << m_ptrOpis << "\n";
	}

protected:
	std::string m_ptrOpis;
};
} //namespace OOP
#endif