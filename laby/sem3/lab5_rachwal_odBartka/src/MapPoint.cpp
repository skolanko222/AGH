#include <iostream>
#include <string>
#include <cmath>
#include "MapPoint.h"

int MapPoint::NMapPoint=0;

void MapPoint::print() const
{
    std::cout << "Print: (" << _longitude << " ," << _latitude << ")" << std::endl;
    return;
}

double MapPoint::distanceVal(const MapPoint & punkt) const
{
    double x=punkt._longitude - _longitude;
    double y=punkt._latitude - _latitude;
    MapPoint mapdistant(x, y);
    return sqrt((x*x) + (y*y));
}
