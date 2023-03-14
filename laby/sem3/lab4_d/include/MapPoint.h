#include <iostream>

struct MapPoint{
    std::string city;
    double longitude;
    double latitude;
};


MapPoint* construct(std::string name, const double longitude,const double latitude);

void print(const  MapPoint* point); 

void print(const  MapPoint & point); 

void movePoint ( MapPoint* point, const double longitudeShift, const double latitudeShift); 

void clear(const  MapPoint* point);

void clear(const MapPoint* city1,const MapPoint* city2,const MapPoint* city3); 