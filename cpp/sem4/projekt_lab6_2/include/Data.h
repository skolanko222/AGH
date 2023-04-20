#pragma once
#include <iostream>

class Data
{
    public:
        virtual ~Data() {}
        virtual void print(std::ostream& out) const = 0;
        virtual void setNext(Data *a) =0;
        virtual Data * getNext() const =0;
};

class IntData : public Data
{
    private:
        int _data;
        Data * _next;

    public:
        IntData(int a, Data *b = nullptr): _data(a) 
        {
            _next = b;
        }
        
        ~IntData() 
        {
            std::cout << "~IntData()" << std::endl;
        }

        void print(std::ostream& out) const override 
        {
            out << _data << ", ";
            if(_next)
                _next->print(out);
        }
        
        void setNext(Data *a) override {_next = a;}

        int getValue() const {return _data;}

        Data * getNext() const override {return _next;}

};

class StringData : public Data
{
    private:
        std::string _data;
        Data * _next;

    public:
        StringData(std::string a, Data *b = nullptr): _data(a) 
        {
            _next = b;
        }
        
        ~StringData()
        {
            std::cout << "~StringData()" << std::endl;
        }

        void print(std::ostream& out) const override 
        {
            out <<"\"" << _data << "\", ";
            if(_next)
                _next->print(out);
        }

        void setNext(Data *a) override {_next = a;}

        std::string getValue() const {return _data;}
        
        Data * getNext() const override {return _next;}
};
