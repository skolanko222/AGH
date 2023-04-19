#include <iostream>
#include "Wymierne.h"

using namespace std;



void Wymierne::print(bool t)
{
    if(t)
        cout << _licznik << "/" << _mianownik << endl;
    if(!t)
        cout << _licznik << "/" << _mianownik;
}