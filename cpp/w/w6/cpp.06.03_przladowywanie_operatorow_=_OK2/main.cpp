#include <iostream>

class Point
{
public:
  friend int main();

  Point(double aa = 0, double bb = 0) : a(new double(aa)), b(new double(bb))
  {
  }
  Point(const Point &K)
  {
    ctor(K);
  }
  ~Point()
  {
    dtor();
  }
  Point &operator=(const Point &K)
  {
    // sprawdzenie czy nie jest wywo³anie np: a = a;
    if (&K == this)
      return *this;

    dtor();
    ctor(K);

    return *this;
  }

private:
  void ctor(const Point &p)
  {
    a = new double(*p.a);
    b = new double(*p.b);
  }

  void dtor()
  {
    delete a;
    delete b;
  }

  double *a;
  double *b;
};

/////////////////////////////////////////////////////////
int main()
{
  using namespace std;

  const Point aPoint(10, 10);
  Point bPoint;
  Point cPoint;

  cPoint = bPoint = aPoint; // Point.operator=(bPoint.operator=(aPoint));

  cout << "aPoint = " << (*aPoint.a) << ", " << (*aPoint.b) << endl;
  cout << "bPoint = " << (*bPoint.a) << ", " << (*bPoint.b) << endl;
  cout << "cPoint = " << (*cPoint.a) << ", " << (*cPoint.b) << endl << endl;

  (*aPoint.a) = (*aPoint.b) = 20;

  cout << "aPoint = " << (*aPoint.a) << ", " << (*aPoint.b) << endl;
  cout << "bPoint = " << (*bPoint.a) << ", " << (*bPoint.b) << endl;
  cout << "cPoint = " << (*cPoint.a) << ", " << (*cPoint.b) << endl;
}
