#pragma once
#include <string>
#include <iostream>

class Punkt
{
	private:
		std::string _str;
		int _x;
		int _y;
	
	public:
		friend std::ostream & operator<<(std::ostream & obj, const Punkt & pkt)
		{
			return obj << pkt._str << "(" << pkt._x << ", " << pkt._y << ")";
		}
		friend void swap(Punkt &a, Punkt &b);
		Punkt(const char * c, int x, int y) : _str(c), _x(x), _y(y) {}
		Punkt(const Punkt & o) = default;
		template <int i> int wsp() const
		{
			if(i == 0)
				return _x;
			else if(i == 1)
				return _y;
			else
				return 0;
		}
		template <int i> int set(int a)
		{
			if(i == 0)
				_x =a;
			else if(i == 1)
				_y =a;
			else
				return 0;
		}
		bool operator<(const Punkt & rhs)
		{
			return _x == rhs._x ? _y < rhs._y : _x < rhs._x;
		}

		template<typename T> static T min(T x, T y)
		{
			return x < y ? x : y;
		}
};
template<typename T> void swap(Punkt &a, Punkt &b)
{
	Punkt c(a);
	a.set<0>(b.wsp<0>());
	a.set<1>(b.wsp<1>());
	b.set<0>(c.wsp<0>());
	b.set<1>(c.wsp<1>());
}
template<typename T> void swap(T &a, T &b)
{
	T c(std::move(a));
	a = std::move(b);
	b = std::move(c);
}
std::ostream & operator<<(std::ostream & obj, const Punkt & pkt);