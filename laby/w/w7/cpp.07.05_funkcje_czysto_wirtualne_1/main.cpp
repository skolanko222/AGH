#include <iostream>
#include "Shape.h"
#include "Rec.h"
#include "Circ.h"

int main(int argc, char * argv[])
{
	using namespace std;
	using namespace OOP;

	//Nie mo¿na stworzyæ obiektu klasy abstrakcyjnej
	// Shape aShape;
	Rec aRec;
	Circ aCirc;
	
	//mo¿emy u¿yæ referencji
	Shape& RefShape = aCirc;

	cout << "Pole RefShape (aCirc) = " << RefShape.Pole() << endl;
	RefShape.Rys();

	cout << "-------------------------------------\n";
	
	//mo¿emy u¿yæ wskaznika
	Shape* Shape;
	Shape = &aRec;
	cout << "Pole Shape* (aRec) = " << Shape->Pole() << endl;
	Shape->Rys();

	cout << "-------------------------------------\n";

	Shape = &aCirc;
	cout << "Pole Shape* (aCirc) = " << Shape->Pole() << endl;
	Shape->Rys();
}

