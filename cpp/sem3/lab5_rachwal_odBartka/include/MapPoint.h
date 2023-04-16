#pragma once
#include <string>

class MapPoint
{
    protected:
        std::string _nazwa;
        double _longitude;
        double _latitude;

    public:
        static int NMapPoint;
        MapPoint(double x=0.0, double y=0.0) : _longitude(x), _latitude(y) {NMapPoint++;}
        MapPoint(const MapPoint & point) :  _longitude(point._longitude), _latitude(point._latitude) {NMapPoint++;}
        //~MapPoint() {NMapPoint--;}
        void print() const;
        double distanceVal(const MapPoint & punkt) const;    
};