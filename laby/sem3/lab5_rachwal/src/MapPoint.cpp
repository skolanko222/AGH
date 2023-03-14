#include "MapPoint.h"
#include "cmath"


int MapPoint::NMapPoint = 0;

void MapPoint::print() const
{
    cout << "Point: (" << longitude << ", " << latitude << ")" << endl;
}

double MapPoint::distanceVal(const MapPoint & punkt) const
{   
    double x = punkt.longitude - longitude;
    double y = punkt.latitude - latitude;
    MapPoint mapdistant(x, y);
    return sqrt((x*x) + (y*y));
    return 0;
}
