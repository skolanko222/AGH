#include <iostream>

class Point 
{ 
public: 
	Point(double x = 0.0, double y = 0.0)
	{_x = x;  _y = y; }
	
	void SetX(double x)
		{_x = x;}

	void SetY(double y)
		{_y = y;}

	double GetX() const
		{ return _x; }

	double GetY() const
		{ return _y; }

	void printOut() const
		{std::cout << _x << ", " << _y;}

private: 
	double _x; 
	double _y; 
}; 
/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;
	
	unsigned n;
	cout << "Podaj liczbe elementow klasy do stworzenia: ";
	// cin >> n;

	n = 5;
	if (n < 1)
		return 0;

/* Nie moøna w ten sposÛb
	Point *f = new Point = {Point(1, 1),
										Point(2, 2),
										Point(3, 3)};
*/
	
	//wskaønik do nowych obiektÛw Point
	Point *fPoint = new Point[n];

	//ustawienie wartoúci
	for(unsigned i = 0; i < n; ++i)
		(fPoint+i)->SetX(i), (fPoint+i)->SetY(i+1);

	//wypisanie
	for(unsigned i = 0; i < n; ++i)
		cout << i << "; ", (fPoint+i)->printOut(), cout << endl;

	//nowy obiekt Point
	cout << "---------- fPointA -----------------\n";
	Point *fPointA = new Point(2, 2);

	fPointA->printOut();
	//Zapis oznaczajπcy dok≥adnie to samo
	//(*fPointA).printOut();

	cout << endl;

	//kasacja obiektu pokazywanego przez fPointA
	delete fPointA;

	cout << "----- fPointA = fPoint -------------\n";

	//przypisanie wskaünikÛw
	fPointA = fPoint;

	//uzycie innego wskaünika 
	for(unsigned i = 0; i < n; ++i)
		cout << i << "; ", (fPointA+i)->printOut(), cout << endl;

	delete [] fPointA;
	//fPoint->SetX(1); //BLAD

	unsigned Row = 4;
	unsigned Col = 2;

	//Tablica wskaünikÛw do wskaünika typu Point
	Point **fPointTab = new Point*[Row];

	//Wype≥nienie tablicy wskaünikÛw tablicami 'Col' elementowymi
	for(unsigned i = 0; i < Row; i++)
		fPointTab[i] = new Point[Col];

	for(unsigned i = 0; i < Row; i++)
		for(unsigned j = 0; j < Col; j++)
		{
			fPointTab[i][j].SetX(i);
			fPointTab[i][j].SetY(j);
		}

	//wypisanie
	cout << "----- **fPointTab ----------------\n";
	for(unsigned i = 0; i < Row; i++)
	{
		cout << i << ": ";
		for(unsigned j = 0; j < Col; j++)
		{
//			cout << i << "," << j << ": ";
			cout << "(";
			fPointTab[i][j].printOut();
			cout << ")\t";
		}
		cout << endl;
	}

	//usuniÍcie tablic
	for(unsigned i = 0; i < Row; i++)
		delete [] fPointTab[i];

	delete [] fPointTab;
}
