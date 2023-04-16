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
	{ m_ptrOpis = new std::string; }

	~RecLbl()
	{ delete m_ptrOpis; }

protected:
	std::string* m_ptrOpis;
};
} //namespace OOP
#endif