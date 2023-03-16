#include <iostream>

//Deklaracja wyprzedzaj¹ca. 
class PointCollection; 

class Point 
{ 
public: 
	friend class PointCollection; 

	Point()
	{_x = 0.0;  _y = 0.0; }

private: 
	double _x; 
	double _y; 
}; 
/////////////////////////////////////////////////////////////////////////
class PointCollection 
{ 
public: 
	PointCollection(const int nSize)
	{ f = new Point[nSize]; this->nSize = nSize; } 

	~PointCollection(void)
	{ delete [] f; }
	
	void Set(const double x, const double y); 
	void print(void);

private: 
	Point *f; 
	int nSize;
}; 
/////////////////////////////////////////////////////////////////////////
void PointCollection::Set(const double x, const double y) 
{ 
	for(int i=0; i < nSize; i++) 
	{ 
		(f+i)->_x = x*i;
		(f+i)->_y = y*i;
	} 
} 
/////////////////////////////////////////////////////////////////////////
void PointCollection::print(void) 
{ 
	for(int i=0; i < nSize; i++) 
		std::cout << "_x = " << (f+i)->_x << ", _y = " <<  (f+i)->_y << std::endl;
} 
/////////////////////////////////////////////////////////////////////////
int main()
{
	PointCollection aPointCollection(20);
	aPointCollection.Set(1, 2);
	aPointCollection.print();
}
