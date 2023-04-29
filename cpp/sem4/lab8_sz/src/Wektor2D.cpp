#include "Wektor2D.h"

Wektor2D::Wektor2D(const char* name, const int& x, const int& y) :
_name(name), _x(x), _y(y) {}

Wektor2D::Wektor2D(const std::string& name, const int& x, const int& y):
_name(name), _x(x), _y(y) {}

std::string Wektor2D::getName() const
{
    return _name;
}

int Wektor2D::getX() const
{
    return _x;
}

int Wektor2D::getY() const
{
    return _y;
}

std::ostream& operator<<(std::ostream& strm, const Wektor2D& vec)
{
    return strm << vec.getName() << " (" << vec.getX() << ", " << vec.getY() << ")";
}

bool Wektor2D::operator<(const Wektor2D& b) const
{
    return getX() < b.getX();
}