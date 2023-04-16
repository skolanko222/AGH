#include <iostream>
using namespace std;

//! Return min value
int min(const int &a, const int &b);
//! Return max value
int max(const int &, const int &);
//! Swap two values
void zamien(int &a, int &b);

int main(int argc, char *argv[])
{
	int a = 1, b = 2;

	cout << "a, b =      " << a << ", " << b << endl;

	cout << "min(a, b) = " << min(a, b)  << endl;
	cout << "max(a, b) = " << max(a, b)  << endl;

	cout << "min(b, a) = " << min(b, a)  << endl;
	cout << "max(b, a) = " << max(b, a)  << endl << endl;

	cout << "Przed zamien a, b = " << a << ", " << b << endl;
	
	zamien(a, b);

	cout << "Po zamien a, b =    " << a << ", " << b << endl;
} 

int min(const int &a, const int &b)
{
	return a < b ? a : b; 
}

int max(const int &a, const int &b)
{
	return b < a ? a : b; 
}

void zamien(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}