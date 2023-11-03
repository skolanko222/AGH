#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_set>
#include <map>

#include <algorithm>

using namespace std;


#pragma once

class Point2D
{
    private:
        int xVal;
        int yVal;

    public:
        //default and two-args constructor
        Point2D(int x = 0, int y = 0) : xVal(x), yVal(y) {};
        
        //getter of first coordinate
        inline int x() const {return xVal;} 
        //getter of first coordinate, returning reference
        inline int & x() {return xVal;} 
        //getter of second coordinate
        inline int y() const {return yVal;}
        //function allowing adding to first coordinate
        Point2D * addToX(int x)  {xVal += x; return this; }

};
int main()
{
    using std::cout;
  using std::endl;

  Point2D point_1(11, 12);
  cout << "1 x: " << point_1.x() << endl; // 1 x: 11
  cout << "1 y: " << point_1.y() << endl; // 1 y: 12

  const Point2D point_2(21, 22);
  cout << "2 x: " << point_2.x() << endl; // 2 x: 21
  cout << "2 y: " << point_2.y() << endl; // 2 y: 22

  Point2D point_3(31, 32);
  point_3.x() = 33;
  cout << "3 x: " << point_3.x() << endl; // 3 x: 33

  Point2D *point_4 = new Point2D(41, 42);
  point_4->addToX(3);
  cout << "4_1 x: " << point_4->x() << endl; // 4_1 x: 44
  point_4->addToX(1)->addToX(8)->addToX(7);
  cout << "4_2: " << point_4->x() << endl; // 4_2: 60

  delete point_4;

  return 0;
}