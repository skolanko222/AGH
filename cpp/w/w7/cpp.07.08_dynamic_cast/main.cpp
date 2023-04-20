#include <iostream>
#include "Shape.h"
#include "RecLbl.h"

int main(int argc, char* argv[])
{
	using namespace std;
	using namespace OOP;

	RecLbl aRecLbl("Jeden");
	RecLbl bRecLbl("Dwa");

	Shape* ptrShape[2];
	ptrShape[0] = &aRecLbl;
	ptrShape[1] = &bRecLbl;

	RecLbl* ptrRecLbl;

	ptrRecLbl = dynamic_cast<RecLbl*>(ptrShape[0]);
	ptrRecLbl->printLbl();

	dynamic_cast<RecLbl*>(ptrShape[1])->printLbl();
	
	RecLbl cRecLbl("Trzy");
	Shape& refShape = cRecLbl;
	
	dynamic_cast<RecLbl&>(refShape).printLbl();
}

