#pragma once

#include "Wrapper.h"
#include <vector>
#include <iostream>


class PVec
{
private:
   
    std::vector<Wrapper *> v;

public:
   
    PVec &push_back(Wrapper *w)
    {
        v.push_back(w);
        return *this;
    };
	
    ~PVec()
    {
        for (int i = 0; i < size(); i++)
            delete v[i];
    };

   
    void printType() const
    {
        std::cout << "[ ";

        for (int i = 0; i < size(); i++)
            std::cout << v[i]->type() << " ";

        std::cout << "]" << std::endl;
    };
	
	PVec &operator<<(Wrapper *w) { return push_back(w); };
    Wrapper &operator[](size_t i) const { return *v[i]; };
    
    size_t size() const { return v.size(); };

    

    friend std::ostream &operator<<(std::ostream &os, const PVec &l)
    {
        os << "[";

        for (int i = 0; i < l.size(); i++)
        {
            l.operator[](i).print(os);
            os << " ";
        }

        os << "]" << std::endl;

        return os;
    };
};
