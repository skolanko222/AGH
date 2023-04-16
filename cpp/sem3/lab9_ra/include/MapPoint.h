#pragma once
#include <string>
using std::string;

namespace MP{}

namespace MTH{
    class Point{
        private:
            double _x;
            double _y;
        public:
            Point(double x, double y) : _x(x), _y(y) {};
            double get_x()const{
                return _x;
            }
            double get_y()const{
                return _y;
            }
			Point& operator=(const Point &p);
			Point(const MP::Point& x) {};	
	};
    void Print(const Point &);
    
}

namespace MP{
    class Point{
            private:
                double _lattitude;
                double _longitude;
                string _label;
            public:
                Point(string label, double lat, double lot) : _label(label), _lattitude(lat), _longitude(lot) {};
                Point(string, MTH::Point &);
                double get_lattitude() const{
                    return _lattitude;
                }
                double get_longitude() const{
                    return _longitude;
                }
                string get_label() const{
                    return _label;
                }
				//explicit operator MP::Point() {};
    };
    void Print(const Point&);
}