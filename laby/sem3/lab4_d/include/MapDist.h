#pragma once
#include <iostream>
#include "MapPoint.h"
#include <cmath>


const MapPoint& closestFrom(MapPoint* city1,MapPoint* city2,MapPoint* city3);/// zwraca *city2 lub *city3 w zaleznosci co jest blizej do city1

MapPoint inTheMiddle(MapPoint* city1,MapPoint* city2,std::string name);/// tworzy strukture o wspolzendnych pomiedzy city1 i city2 o nazwie name