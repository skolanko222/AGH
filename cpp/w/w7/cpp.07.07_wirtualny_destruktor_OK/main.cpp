#include <iostream>
#include "Shape.h"
#include "RecLbl.h"

int main(int argc, char* argv[])
{
	using namespace std;
	using namespace OOP;
	Shape* ptrShape;

	for(long i = 0; i < 10000000; i++)
	{
		if(i % 10000 == 0)
			cout << "i = " << i << "               \r";
		ptrShape = new RecLbl;
		delete ptrShape;
	}
}

