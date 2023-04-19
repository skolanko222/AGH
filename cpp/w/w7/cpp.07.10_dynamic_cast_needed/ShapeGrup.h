#ifndef _Shape_GRUP_H_
#define _Shape_GRUP_H_
		
#include <iostream>
#include <vector>
#include <algorithm>
#include "Shape.h"

namespace OOP
{
class ShapeGrup : public Shape
{
public:
	virtual void Add(Shape& K)
	{ elem.push_back(&K); }

	virtual void Remove(Shape& K);
	
	virtual void Rys() const;

	virtual double Pole() const
	{ return Shape::Pole(); }

protected:
	std::vector<Shape*>elem;
};

void ShapeGrup::Remove(Shape& K)
{ 
	std::vector<Shape*>::iterator pos;
	pos = std::find(elem.begin(), elem.end(), &K);
	if(pos != elem.end())
		elem.erase(pos);
}

void ShapeGrup::Rys() const
{
	for(unsigned i=0; i < elem.size(); ++i)
		elem[i]->Rys();
}
} //namespace OOP
#endif
