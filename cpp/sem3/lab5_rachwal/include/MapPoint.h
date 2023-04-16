#include <iostream>

using namespace std;

class MapPoint
{
    private:
        double longitude; 
        double latitude;
    public:
        static int NMapPoint;
        MapPoint() : longitude(0), latitude(0) {NMapPoint++; };
        MapPoint(double new_lon, double new_lat) : longitude(new_lon), latitude(new_lat) {NMapPoint++; };
        void print() const;
        double distanceVal(const MapPoint & punkt) const;
        MapPoint(const MapPoint &copy) : longitude(copy.longitude), latitude(copy.latitude) {NMapPoint++;};


};
