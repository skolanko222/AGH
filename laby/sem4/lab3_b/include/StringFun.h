#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>


class MyString
{
    private:
        std::string _str;

    public:
        MyString(const char * str): _str(str) {}
        
        ~MyString() {}

        std::string str() const {return _str;}

        void* operator new(size_t size)
        {
            std::cout << "[MyString] Overloading new operator with size: " << size << std::endl;
            void *temp = ::operator new(size);
            return temp;
        }

        void operator delete(void* temp)
        {
            std::cout << "[MyString] Overloading delete operator\n";
            free(temp);
        }

        bool operator<=(const MyString b) const
        {
            return this->_str <= b.str() ? 1 : 0;
        }

        bool operator>(const MyString b) const
        {
            return this->_str > b.str() ? 1 : 0;
        }
};

class Less
{
    public:
        bool operator()(const MyString a, const MyString b) const {return a <= b ? 1 : 0;}
};

class Greater
{
    public:
        bool operator()(const MyString a, const MyString b) const {return a > b ? 1 : 0;}
};

class MyStringContainer
{
    private:
        std::vector<MyString*> _ptr;
        std::vector<std::function<bool(const MyString, const MyString)>> _fun = {Less(), Greater()};

    public:
        MyStringContainer() {}
        ~MyStringContainer()
        {
            for(int i=0; i<_ptr.size(); i++)
            {
                delete _ptr[i];
            }
        } 

        MyStringContainer(const MyStringContainer &a)
        {
            for(int i=0; i<a._ptr.size(); i++)
            {
                auto namePtr = new MyString(*(a._ptr[i]));
                _ptr.push_back(namePtr);
            }
        }

        void AddMStr(MyString* a) 
        {
            _ptr.push_back(a);
        }
        
        void AddMStr(const char * a)
        {
             auto temp = new MyString(a);
             this->AddMStr(temp);
        }

        std::vector<MyString> GetSorted(std::string str)
        {
            std::vector<MyString> wtr;
            for(int i=0; i<_ptr.size(); i++)
            {
                wtr.push_back(*(_ptr[i]));
            }
             if(str=="ASC")
                 std::sort( wtr.begin(), wtr.end(), _fun[0]);
             else
                 std::sort( wtr.begin(), wtr.end(), _fun[1]);
             return wtr;
        }

        std::vector<std::function<bool(const MyString, const MyString)>> SortFunc()
        {
            return _fun;
        }

};


void PrintNames(std::vector<MyString> names);