#include <iostream>
#include <typeinfo>
#include "Circ.h"
#include "Rec.h"
// #include "../util.h"

int main(int argc, char* argv[])
{
	using namespace std;
	using namespace OOP;

	Rec aRec, bRec;
	Circ aCirc;
	Shape* ptr[2];

	cout << "Nazawa klasy obiektu aRec:  " << typeid(aRec).name() << endl;
	cout << "Nazawa klasy obiektu aCirc: " << typeid(aCirc).name() << endl;

	ptr[0] = &aRec;
	ptr[1] = &bRec;

	if(typeid(*ptr[0]) == typeid(*ptr[1]))
		cout << "Obiekty naleza do tej samej klasy.\n";
	else
		cout << "Obiekty naleza do roznych klas.\n";

	ptr[1] = &aCirc;

	if(typeid(*ptr[0]) == typeid(*ptr[1]))
		cout << "Obiekty naleza do tej samej klasy.\n";
	else
		cout << "Obiekty naleza do roznych klas.\n";

}