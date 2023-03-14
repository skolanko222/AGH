#include <iostream>
#include "MapPoint.h"
#include <string>
#include <cmath>

using namespace std;

// MapPoint::MapPoint()
// {
//    longitude = 0;
//     latitude = 0;
//    name = "Empty";

// }

void MapPoint::setPoint(string n, const double x, const double y)
{
    longitude = x;
    latitude = y;
    name = n;

}

void MapPoint::setPoint(string n, const double x, char x_k, const double y, char y_k) 
{
    x_k == 'W' ? longitude = -x : longitude = x;
    y_k == 'S' ? latitude = -y : latitude = y;
    name = n;

}

void  MapPoint::print() const
{
    char a,b;
    longitude < 0 ? a = 'W' : a = 'E';
    latitude  < 0 ? b = 'S' : b = 'N';
    cout << "Wspolrzedne dla " << name << ": " << fabs(longitude) << " " << a << " " << fabs(latitude) << " " << b << endl;

}


double MapPoint::getLongitude() const 
{
    return longitude;

}
double MapPoint::getLatitude() const 
{
    return latitude;

}
void MapPoint::move(const double x, const double y)
{
    longitude += x;
    latitude += y;

}

double distance(MapPoint p1, MapPoint p2) 
{
    const double longitude1 = p1.getLongitude();
    const double latitude1 = p1.getLatitude();
    const double longitude2 = p2.getLongitude();
    const double latitude2 = p2.getLatitude();

    return sqrt((longitude1 - longitude2)*(longitude1 - longitude2) 
                + (latitude1 - latitude2)*(latitude1 - latitude2));

}
const MapPoint * closestPlace(const MapPoint &ref, const  MapPoint &p1, const  MapPoint &p2)
{
    double distance1 = distance(ref, p1);
    double distance2 = distance(ref, p2);
    
    if(distance1 < distance2)
        return &p1;
    else
        return &p2;
    
}

MapPoint inTheMiddle(const  MapPoint * ref, const  MapPoint *p1, string name)
{

    return MapPoint(name,(ref->getLongitude() + p1->getLongitude() ) / 2, (ref->getLatitude() + p1->getLatitude()) / 2 );

}