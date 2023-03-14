#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int fcmpr ( const void *a, const void *b)
{
    double fa = *( const double *)a;
    double fb = *( const double *)b;
    return (fa > fb) - (fa < fb);
}
double drand ( double low, double high)
{
    return ( (double)rand() * ( high - low ) ) / (double)RAND_MAX + low;
}
int main(void)
{
    int A[3];
    char NAP[4][5] = {"nap1", "nap2","nap3"};
    double T[][2] = {{1.0,1.0},{0.},{2.0,3.0}};

    int (*a)[3] = &A;
    char *b = NAP[2];
    char c = (*NAP[1])++;
    putc(c,stdout);
    //double d[][2] = (double [][2]){1.0, 3.0, 4.0}//?????????????/////???/??
    char (*e)[5] = NAP;