#include <iostream>
using namespace std;

#define INIT_ERROR

struct test
{
	int s;
};

int main()
{
	double *f, *g;
	f = new double();
	g = new double (10.0);

	test* t = new test;
	t->s = 5;

	double* const ff = new double[10];


#ifdef INIT_ERROR
	cout << "*f = " << *f << endl;
#endif

	*f = 10.0;
	cout << "*f po inicjalizacji = " << *f << endl;
	
	for(int i = 0; i < 10; i++)
		*(ff + i) = (double)(i+1)/2;

	for(int i = 0; i < 10; i++)
		cout << *(ff + i) << endl;

	//g = f; //BLAD

	delete g;
	delete f;
	
	//*f = 10; //B£¥D

	delete [] ff;
}