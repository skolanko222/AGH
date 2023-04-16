#include <iostream>
using namespace std;

int main()
{
	int t[20];
	int *w1, *w2;

	w1 = w2 = t;

	for(int i = 0; i < 20; i++)
		*(w2++) = i+1;

	cout << "Liczba elementow miedzy poczatkiem a koncem tablicy = " << w2 - w1 << endl << endl;

	w1 = t + 2;
	w2 = t + 19;

	cout << "w1 = t + 2; w2 = t + 19;" << endl;

	if(w1 == w2)
		cout << "Wskazniki pokazuja na ten sam element\n";
	else if(w1 > w2)
		cout << "w1 pokazuja na dalszy element tablicy niz w2\nOdleglosc miedzy nimi = " << w1 - w2 << endl;
	else if(w1 <= w2)
		cout << "w1 pokazuja na blizszy element tablicy niz w2\nOdleglosc miedzy nimi = " << w2 - w1 << endl;
}
