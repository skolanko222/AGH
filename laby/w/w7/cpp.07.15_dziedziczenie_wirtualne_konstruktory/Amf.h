#ifndef _CAMF_H_
#define _CAMF_H_

#include <iostream>

#include "Auto.h"
#include "Lodz.h"

namespace OOP 
{
class Amf : public Auto, public Lodz 
{
public:
  Amf(int d = 0) : Trans(d)
	{ std::cout << "Konstruktor Amf\n"; }

	~Amf()
  { std::cout << "Destruktor Amf\n"; }
	

	void printTraveled() 
	{
      std::cout << "Amfibia pokonala "
                << m_km << " km" << std::endl;
  }

	void travel(int d) 
	{	Auto::travel(d);	}

	virtual void travelAsAuto(int d) 
	{ Auto::travel(d); }

	virtual void travelAsLodz(int d) 
	{ Lodz::travel(d); }
};

}  // namespace OOP
#endif    // _CAMF_H_
