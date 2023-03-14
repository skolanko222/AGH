#pragma once

#include <vector>
#include <iostream>

class Operation
{
    protected:
        
        std::string _s;
        char _z;
        std::vector<double> _v;
    
    public:
        Operation(double v1, double v2,  std::string s, char z)
        {
            _v.push_back(v1);
            _v.push_back(v2);
            _s = s;
            _z = z;
        }
        Operation(double * v1, int v2,  std::string s, char z)
        {
            for(int i=0; i<v2; i++)
            {
                _v.push_back(v1[i]);
            }
            _s = s;
            _z = z;

        }

        std::string name() const {return _s;}
        char op() const {return _z;}
        virtual double eval() const {return 0.0;}
        void print(std::ostream &o = std::cout) const 
        {
            for(int i=0; i<_v.size(); i++)
            {
                o << _v[i] << op();
            }
            o << '\b';
        }

        Operation &operator[](int i) const 
        {

        }
        Operation &operator=(double i) const 
        {
            
        }

};

std::ostream &operator<<(std::ostream &o,const Operation &a);
