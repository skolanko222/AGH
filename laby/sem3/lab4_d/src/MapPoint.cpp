#include <iostream>
#include <cstdlib>
#include <cmath>

#include "MapPoint.h"
using namespace std;

MapPoint* construct(std::string name, const double x,const double y) 
{
    MapPoint* wsk= new MapPoint;
    wsk->city = name;
    wsk->longitude = x;
    wsk->latitude = y;

    return wsk;
}

void print(const  MapPoint* point)
{
    cout << "Wspolrzedne dla " << point->city << ": ";
    cout << fabs(point->longitude) << (point->longitude > 0 ? "E" : "W") << ' ';
    cout << fabs(point->latitude) << (point->latitude > 0 ? "N" : "S") << endl;
}
void print(const  MapPoint & point)
{
    cout << "Wspolrzedne HUJ dla " << point.city << ": ";
    cout << fabs(point.longitude) << (point.longitude > 0 ? "E" : "W") << ' ';
    cout << fabs(point.latitude) << (point.latitude > 0 ? "N" : "S") << endl;


}


void movePoint(MapPoint* point, const double longitudeShift, const double latitudeShift)
{
    point->longitude += longitudeShift;
    point->latitude += latitudeShift;

}

void clear(const  MapPoint* point)
{
    cout << "Usuwanie: " << point->city << endl;
    delete point;
    point = nullptr;

}

void clear(const MapPoint* p1,const MapPoint* p2,const MapPoint* p3)
{
    clear(p1);
    clear(p2);
    clear(p3);


}