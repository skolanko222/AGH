#pragma once

#include <iostream>
#include <string>
#include <vector>

class Operation
{
    protected:
        std::string _name;
        char _op;
        std::vector<double> _arr;
    public:

    Operation(std::string nam, char op, std::vector<double> arr) 
    {
        _name = nam;
        _op = op;
        _arr = arr;
    }
    virtual double eval() const 
    {
        return 0.0;
    }
    std::string name() const {return _name;}
    char op() const {return _op;}
    void print(std::ostream &o = std::cout) const
    {
        for(int i = 0; i < _arr.size(); i++)
        {
            if(i != _arr.size() -1 )
                o << _arr[i] << _op;
            else
                o << _arr[i];
            
        }
        
    }
    double & operator[](int n){return _arr[n];}
};

std::ostream &operator<<(std::ostream &o, const Operation & x);