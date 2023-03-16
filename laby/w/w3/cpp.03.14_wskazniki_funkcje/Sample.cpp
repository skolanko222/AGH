#include <iostream>
using namespace std;

int min(int a, int b);
int max(int a, int b);
void zamien(int &a, int &b);
//funkcja przyjmujπca jako ostatni argument wskaünik do funkcji
void print(int a, int b, int(*)(int, int));

int main(int argc, char *argv[])
{
	int a = 1, b = 2;
	int (*f1)(int, int);
	void (*f2)(int &, int &);

	cout << "a, b =      " << a << ", " << b << endl;

	f1 = min;
	cout << "f1(a, b) = " << f1(a, b)  << endl;
	f1 = max;
	cout << "f1(a, b) = " << f1(a, b)  << endl;

	cout << "Przed zamien a, b = " << a << ", " << b << endl;
	f2 = zamien;
	f2(a, b);

	cout << "Po zamien a, b =    " << a << ", " << b << endl;
	
	print(a, b, min);
	print(a, b, max);
} 

int min(int a, int b)
{
	return a < b ? a : b; 
}

int max(int a, int b)
{
	return b < a ? a : b; 
}

void zamien(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void print(int a, int b, int(*f)(int, int))
{
	cout << "Wynik dzialania funkcji na dane: " << a << ", " << b << " = " << f(a, b) << endl;
}