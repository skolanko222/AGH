#include <iostream>
#include <string>
#include "MapPoint.h"

using namespace std;


int MapPoint::_count = 0;

int getObjects()
{
    return MapPoint::_count;
}

void MapPoint::print() const
{
    cout << "Punkt nr " << getObjects() << ": " << _name << " (" << _x << ", " <<_y << ")" << endl;
}

void MapPoint::setPoint(const double x, const double y) 
{
    setLatitude(x); 
    setLongitude(y);
}