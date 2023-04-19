#pragma once

#include <iostream>
#include <string>

using namespace std;

class MapPoint
{
    private:
        double longitude;
        double latitude;
        string name;
    
    public:
        MapPoint(string n = "Empty", const double x = 0 , const double y = 0) : name(n), longitude(x), latitude(y) {};
        //MapPoint();
        void setPoint(string n, const double x, const double y);
        void setPoint(string n, const double x, char x_k, const double y, char y_k);
        //void print();
        void print() const;
        double getLongitude() const;
        double getLatitude() const;
        void move(const double x, const double y);
        string getName() const
        {
            return name;
        }



};   

double distance(MapPoint p1, MapPoint p2);
const MapPoint * closestPlace(const  MapPoint &ref,const  MapPoint &p1,const  MapPoint &p2);
MapPoint inTheMiddle(const MapPoint *ref, const MapPoint *p1, string name);