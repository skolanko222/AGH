/*
The following code example is taken from the book
Object-Oriented Programming in C++
by Nicolai M. Josuttis, Wiley, 2002
*/

// header file for I/O
#include <iostream>

// header files for used classes
#include "line.hpp"
#include "circle.hpp"
#include "geogroup.hpp"

using namespace Geo;

// draw any geometric object
template <typename GeoObj>
void myDraw (const GeoObj& obj)
{
    obj.draw();
}

// calculate distance between two geometric objects
template <typename GeoObj1, typename GeoObj2>
Coord distance (const GeoObj1& x1, const GeoObj2& x2)
{
    Coord a = x1.position() + (-x2.position());
    // return a.abs();
    return a;
}

// output homogenous set of geometric objects
template <typename GeoObj>
void drawElems (const std::vector<GeoObj>& elems)
{
    for (unsigned i=0; i<elems.size(); ++i) {
        elems[i].draw();
    }
}

int main()
{
    Line l(Coord(0,1),Coord(0,1));
    Circle c(Coord(1,1),1);
    Circle c1(Coord(0,1),2), c2(Coord(0,1),3);

    myDraw(l);          // myDraw<Line>(GeoObj&) => Line::draw()
    myDraw(c);          // myDraw<Circle>(GeoObj&) => Circle::draw()

    distance(c1,c2);    // distance<Circle,Circle>(GeoObj&,GeoObj&)
    distance(l,c);      // distance<Line,Circle>(GeoObj&,GeoObj&)

    // std::vector<GeoObj*> coll;  // ERROR: no inhomogenous collection possible
    std::vector<Line> coll;      // OK: homogenous collection
    coll.push_back(l);           // insert line
    drawElems(coll);             // draw collection
}