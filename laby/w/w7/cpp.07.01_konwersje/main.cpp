#include <iostream>
#include <string>
#include "Shape.h"
#include "Rec.h"

using namespace std;
using namespace OOP;

/////////////////////////////////////////////////////////////////////////
void funRef(Shape& K) {
	cout << K.GetX() << ", " << K.GetX() << endl;
}
/////////////////////////////////////////////////////////////////////////
Shape& funRef(Shape& K, double x, double y) {
	K.SetX(x);
	K.SetY(x);
	return K;
}
/////////////////////////////////////////////////////////////////////////
void funPtr(Shape* K) {
	cout << K->GetX() << ", " << K->GetX() << endl;
}
/////////////////////////////////////////////////////////////////////////
Shape* funPtr(Shape* K, double x, double y) {
	K->SetX(x);
	K->SetY(x);
	return K;
}
/////////////////////////////////////////////////////////////////////////
void funTab(Shape K[], int size) {
	for(int i = 0; i < size; i++)
		cout << K[i].GetX() << ", " << K[i].GetX() << endl;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
	Rec aRec;
	Rec* ptrRec;

	aRec.SetX(1);
	aRec.SetY(1);

	cout << "----------------------------------\n";
	funRef(aRec);
	funRef(funRef(aRec, 2, 2));
	cout << "----------------------------------\n";
	
	Shape& aShape = aRec;
	funRef(aShape);

	ptrRec = &aRec;
	funPtr(ptrRec);
	funPtr(funPtr(ptrRec, 3, 3));
	cout << "----------------------------------\n";

	Shape bShape = *ptrRec;
	funRef(bShape);

	Shape tabShape[2] = {Shape(1, 1), Shape(2, 2)};
	Rec tabRec[2] = {Rec(3,3), Rec(4,4)};

	funTab(tabShape,2);
	cout << "----------------------------------\n";
	funRef(tabRec[0]);
	funRef(tabRec[1]);
	cout << "----------------------------------\n";
	//powoduje problem
	funTab(tabRec,2);
}
