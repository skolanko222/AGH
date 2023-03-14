#include "MapDist.h"

const MapPoint& closestFrom(MapPoint* city1,MapPoint* city2,MapPoint* city3){
    double distance2 = sqrt((city1->longitude-city2->longitude)*(city1->longitude-city2->longitude)
    +(city1->latitude-city2->latitude)*(city1->latitude-city2->latitude));
     double distance3 = sqrt((city1->longitude-city3->longitude)*(city1->longitude-city3->longitude)
    +(city1->latitude-city3->latitude)*(city1->latitude-city3->latitude));
    if(distance2>distance3)
    {
        return *city3;
    }
    else
    {
        return *city2;
    }
}

MapPoint inTheMiddle(MapPoint* city1,MapPoint* city2,std::string name){

    MapPoint newMapPoint;
    newMapPoint.name = name;
    newMapPoint.latitude = (city1->latitude + city2->latitude)/2;
    newMapPoint.longitude = (city1->longitude + city2->longitude)/2;
    return newMapPoint;
}