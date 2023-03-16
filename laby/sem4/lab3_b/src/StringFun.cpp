#include <iostream>
#include <vector>
#include <algorithm>
#include "StringFun.h"

void PrintNames(std::vector<MyString> names)
{
    for(int i=0; i<names.size(); i++)
    {
        std::cout << names[i].str() << " ";
    }
    std::cout << std::endl;
}