#ifndef _WEKTOR2D_H_
#define _WEKTOR2D_H_

#include <iostream>
#include <string>
#include <initializer_list>
#include <set>
#include <algorithm>

class Wektor2D
{
    public:
        Wektor2D() = default;
        Wektor2D(const char* name, const int& x, const int& y);
        Wektor2D(const std::string& name, const int& x, const int& y);
        
        std::string getName() const;
        int getX() const;
        int getY() const;

        bool operator<(const Wektor2D& b) const;

        friend std::ostream& operator<<(std::ostream& strm, const Wektor2D& vec);
    private:
        std::string _name;
        int _x;
        int _y;
};

#endif