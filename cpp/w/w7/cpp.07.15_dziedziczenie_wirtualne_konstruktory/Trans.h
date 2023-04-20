#ifndef _CTRANS_H_
#define _CTRANS_H_

#include <iostream>

namespace OOP 
{
class Trans
{
public:
	Trans(int d = 0) : m_km(d)
	{ std::cout << "Konstruktor Trans\n"; }
	virtual ~Trans()
	{ std::cout << "Destruktor Trans\n"; }

	virtual void travel(int d) = 0;
	virtual void printTraveled() = 0;
protected:
	int m_km;
};
}//namespace OOP 
#endif