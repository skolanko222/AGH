#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//! Factorial function with recurrence 
unsigned long silnia1(const unsigned int n);
//! Factorial function without recurrence 
unsigned long silnia2(const unsigned int n);

int main(int argc, char *argv[])
{
	int n = 25;

	time_t start, finish;
  time(&start);
  
	for(long loop = 0; loop < 5000000; ++loop)
    silnia1(n);
  
	time(&finish);

	cout << "silnia1 czas obliczen = " << difftime(finish, start) << endl;
  time(&start);
  
	for(long loop = 0; loop < 5000000; ++loop)
    silnia2(n);
  
	time(&finish);
	cout << "silnia2 czas obliczen = " << difftime(finish, start) << endl;
} 

unsigned long silnia1(const unsigned int n)
{
	if (n<2) 
		return 1;
	else 
		return n*silnia1(n-1);
}

unsigned long silnia2(const unsigned int n)
{
	unsigned long wynik = 1;

	for(unsigned int i = 2; i <= n; ++i)
		wynik *= i;
	
	return wynik;
}
