#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class MyString
{
    private:
     std::string _str;
     
     public:
        MyString(const char* s) : _str(s){}
        ~MyString(){}
        bool operator < (MyString x)const
        {
            return _str < x._str ? 1 : 0;
        }
         bool operator > (MyString x)const
        {
            return _str > x._str ? 1 : 0;
        }
        std::string str()const
        {
            return _str;
        }
        int length()const
        {
            return _str.length();
        }
};

class Less{
    public:
    bool operator() (const MyString a,const MyString b)const
    {
        return a < b;
    }
};

class Greater{
    public:
    bool operator() (const MyString a,const MyString b)const
    {
        return a > b;
    }
};

void PrintNames(std::vector<MyString> n) 
{
    for(const MyString x : n)
    {
        std::cout<<x.str()<<' ';
    }
    std::cout<<' ';
}


class Length{
    public:
    bool operator () (const MyString a,const MyString b)
    {
        return a.length() < b.length();
    }
};