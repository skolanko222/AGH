#pragma once
#include <string>

class Named
{
    private:
        std::string _nazwa = "None";
    public:
        std::string Name() const
        {
            return _nazwa;
        }       
        void nazwaSet(std::string str)
        {
            _nazwa=str;
        }
};

void operator>> (std::string str, Named& a);