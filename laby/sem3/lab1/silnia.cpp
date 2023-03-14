#include "silnia.h"

int silnia(int x)
{
    if(x < 0)
        return -1;
    int ret = 1;
    for(int i = x; i > 0; i--)
        ret *= i;

    return ret;
}
int silnia_recur(int x)
{
    if(x < 0)
        return -1;
    if(x == 0 || x == 1)
        return 1;
    return x*silnia_recur(x-1);
    
}

int dwumian(int m, int n)
{
    if(m < 0 || n < 0)
        return -1;
    return silnia_recur(m)/(silnia(n)*silnia(m-n));

}