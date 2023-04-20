#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////
class Point {
public :
	double *b;
	double *a;

	Point();
	~Point();
};
/////////////////////////////////////////////////////////
Point::Point()
{
	b = new double[100000];
	a = new double[100000];

	for(int i = 0; i < 100000; i++)
	{
		b[i] = 0; 
		a[i] = 0;
	}
}
/////////////////////////////////////////////////////////
Point::~Point()
{
	delete [] b;
	delete [] a;
}
/////////////////////////////////////////////////////////
int main()
{
	for(int i = 0; i < 100; i++)
	{
		cout << "i = " << i << "\r";
		Point a;
	}
}
