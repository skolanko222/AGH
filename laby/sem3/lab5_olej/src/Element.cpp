#include "Element.h"
#include <iostream>

using namespace std;


Element::~Element()
{
    cout << "Destruktor Element: " << data << endl;
}

char * Element::getName() 
{
    return data;
}

void Element::printName() 
{
    cout << data << endl;
}

Element * Element::getNext()
{
    return next;
}