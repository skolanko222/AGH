#pragma once
#include <iostream>
#include <string>

class Mebel
{
	private:
		short _x, _y, _z;
		const static char * name;
	public:
	
		Mebel(short x = 0,short y= 0, short z= 0) : _x(x), _y(y), _z(z) {};
		virtual const char * getName() const {return name;}
		short getX() const {return _x;}
		short getY() const {return _y;}
		short getZ() const {return _z;}
		std::string mebelInfo() const
		{
			std::string temp = name;
			temp += " sz: ";
			temp += std::to_string(getX());
			temp += " wys: ";
			temp += std::to_string(getY());
			temp += " dl: ";
			temp += std::to_string(getZ());
			return temp;
		}
		virtual std::string getInfo() const{return "";}
		virtual ~Mebel() {std::cout << "~Mebel\n";}
		friend std::ostream & operator<<(std::ostream & o, const Mebel & obj)
		{
			std::string mebDel = obj.getName();
			if(mebDel == "Mebel")
				mebDel = "";
			return o << mebDel << ": " << obj.mebelInfo() << " " << obj.getInfo();
		}

};

std::ostream & operator<<(std::ostream & o, const Mebel & obj);