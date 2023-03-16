#include <iostream>
using namespace std;

int sum1(int t[], int size);
int sum2(int *t, int size);

int main()
{
	int t[10];
	int *w;
	
	w = t;

	for(int i = 0; i < 10; i++, w++)
		*w = i;

	cout << "Suma(t[]) = " << sum1(t, 10) << endl;
	cout << "Suma(*t) =  " << sum2(t, 10) << endl;
}

int sum1(int t[], int size)
{
	int sum = 0;
	
	for(int i = 0; i < size; i++)
		sum += t[i];
	return sum;
		
}

int sum2(int *t, int size)
{
	int sum = 0;
	
	for(int i = 0; i < size; i++, t++)
		sum += *t;
	return sum;
}
