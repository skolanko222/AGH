#pragma once
#include<iostream>
#include<stdlib.h>

//forward declaration
class LPrint;
class LArray;

//class representing a line
class Line{

public:
    //friendships
    friend class LPrint;
    friend class LArray;
    //2 param constructor
    Line(double a, double b ):_a{a},_b{b}{}
    //converting constructor
    Line(double a=1):_a{a},_b{a}{}
    //get value
    inline double operator()(double x) const {return _a*x+_b;}
    //find cross point
    inline double X0()const{return -_b/_a;}
private:
    double _a;
    double _b;
};

//class to print Line
class LPrint{
public:
    //get info about Line
    inline void operator()(const Line& line)
    {
        std::cout <<"y = "<<line._a<<"* x + "<<line._b<<"\tx0 = "<<line.X0()<<std::endl;
    }
    
};
//class for array of Line
class LArray{
public:
    //constructor
    LArray(unsigned int s):_size{s},_array{new Line[s]}{}
    //destructor
    ~LArray();
    //add element to array
    inline void Add(const Line& line){
        if(_n<_size) _array[_n++]=line;
    }
    //get access to element
    Line& operator[](unsigned int index);
private:
    unsigned int _n=0;
    unsigned int _size=0;
    Line *_array;
};

