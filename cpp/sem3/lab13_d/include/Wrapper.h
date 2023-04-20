#pragma once

#include <cstring>
#include <iostream>

class Wrapper
{
	protected:

		char *title;
		
		Wrapper(const char *t)
		{
			title = new char [sizeof(t) + 1];
			strcpy(title,t);
		};

	public:
	
		virtual void print(std::ostream &os) const = 0;

		virtual const char *type() const { return title; };

		virtual void operator++(int) = 0;

		virtual ~Wrapper() { delete[] title; };
};

class IntWrapper : public Wrapper
{
private:

    int v;

public:

    IntWrapper(int v) : IntWrapper::Wrapper("Int"), v(v){};
   
    void print(std::ostream &os) const { os << v; };

    void operator++(int) { v++; };
};

class StringWrapper : public Wrapper
{
private:
  
    char *name;

public:
  
    StringWrapper(const char *v) : IntWrapper::Wrapper("String")
	{ 
		name = new char [sizeof(v) + 1];
		strcpy(name,v);
	};

    void print(std::ostream &os) const { os << name; };

    void operator++(int) 
    {
        for (int i = 0; i < strlen(title); i++)
            title[i] -= 32;
    };

    ~StringWrapper() 
    {
        delete[] name;
    };
};


class FloatWrapper : public Wrapper
{
private:

    float v;

public:

    FloatWrapper(float v) : IntWrapper::Wrapper("Float"), v(v){};

    void operator++(int) { v++; };
	
    void print(std::ostream &os) const { os << v; };
};
