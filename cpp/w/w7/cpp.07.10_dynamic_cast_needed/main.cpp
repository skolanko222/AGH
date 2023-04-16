#include <iostream>
#include <typeinfo>
#include "Circ.h"
#include "Rec.h"
#include "ShapeGrup.h"

int main(int argc, char* argv[])
{
	using namespace std;
	using namespace OOP;

	Rec aRec(1,1,1,1), bRec(2,2,2,2);
	Circ aCirc(3,3,3), bCirc(4,4,4);
	
	ShapeGrup g;

	g.Add(aRec);
	g.Add(bRec);

	Shape& ref = g;
	dynamic_cast<ShapeGrup&>(ref).Add(aCirc);
	dynamic_cast<ShapeGrup&>(ref).Add(bCirc);
	
	g.Rys();
}

