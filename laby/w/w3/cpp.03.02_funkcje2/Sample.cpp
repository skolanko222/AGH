#include <iostream>
using namespace std;

int min(int a, int b);
int max(int, int);
void zamien(int a, int b);

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

int min(int a, int b)
{
	return a < b ? a : b; 
}

int max(int a, int b)
{
	return b < a ? a : b; 
}

void zamien(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}