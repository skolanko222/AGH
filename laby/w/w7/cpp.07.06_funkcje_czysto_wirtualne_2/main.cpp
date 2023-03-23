#include <iostream>
#include "Shape.h"
#include "Rec.h"
#include "Circ.h"
#include "Line.h"

int main(int argc, char* argv[])
{
	using namespace std;
	using namespace OOP;

	Rec aRec = Rec(0, 0, 2, 2);
	Line aLine;
	
	Shape* Shape;
	Shape = &aRec;
	cout << "Pole Shape* (aRec) = " << Shape->Pole() << endl;
	Shape->Rys();

	cout << "-------------------------------------\n";

	Shape = &aLine;
	cout << "Pole Shape* (aLine) = " << Shape->Pole() << endl;
	Shape->Rys();
}

