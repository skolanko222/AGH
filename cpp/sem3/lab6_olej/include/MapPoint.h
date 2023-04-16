#include <iostream>
#include <string>
#pragma once

using namespace std;

class MapPoint
{   
    friend int getObjects();
    public:
        MapPoint() : _x(0), _y(0), _name("Punkt") {_count++;}
        void print() const;
        void setName(string n) {_name = n;}
        void setLatitude(const double n) {_x = n;}
        void setLongitude(const double n) {_y = n;}
        void setPoint(const double x, const double y);
        MapPoint makePoint(const double x, const double y, string n)

    private:
        double _x;
        double _y;
        string _name;
        static int _count;
};

int getObjects();
