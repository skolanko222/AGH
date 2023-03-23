#include <iostream>
#include "Shape.h"
#include "Rec.h"
#include "Circ.h"

int main(int argc, char * argv[])
{
	using namespace std;
	using namespace OOP;

	Shape aShape;
	Rec aRec;
	Circ aCirc;
	
	// cout << "Pole aRec = " << aRec.Pole() << endl;
	// cout << "Pole aCirc = " << aCirc.Pole() << endl;
	
	// cout << "-------------------------------------\n";
	
	// aRec.Rys();
	// aCirc.Rys();

	// cout << "-------------------------------------\n";

	Shape* Shape;
	Shape = &aShape;
	cout << "Pole aShape = " << Shape->Pole() << endl;
	Shape->Rys();

	cout << "-------------------------------------\n";
	
	Shape = &aRec;
	cout << "Pole Shape (aRec) = " << Shape->Pole() << endl;
	Shape->Rys();

	cout << "-------------------------------------\n";

	Shape = &aCirc;
	cout << "Pole Shape (aCirc) = " << Shape->Pole() << endl;
	Shape->Rys();
}
