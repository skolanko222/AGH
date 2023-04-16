#include <iostream>
#include "Wymierne.h"

using namespace std;

void wymierne::Wymierne::print(const char * n) const
{
        cout << n << _licznik << "/" << _mianownik << endl;

}

int wymierne::Wymierne::simplify(const int x, const int y) const
{

        return 0;

}

wymierne::Wymierne wymierne::pomnoz(const wymierne::Wymierne &x, const wymierne::Wymierne &y)
{
        //wymierne::Wymierne ret(x._licznik*y._licznik, x._mianownik*y._mianownik);
        return x ;

}
wymierne::Wymierne wymierne::Wymierne::pomnoz(const wymierne::Wymierne &x, const wymierne::Wymierne &y)
{

        return x;
}


int nwd(int m, int n)
{
  int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
      m = oldn;
      n = oldm % oldn;
  }
    return n;
} 
