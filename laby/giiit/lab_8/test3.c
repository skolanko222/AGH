#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    double X[4],(*Y)[6], *(*Z)[8], *A, **B;
    double tab1[6] = {1,2,3,4,5,6};
    double *tab2[8] = {tab1,tab1+1,tab1+2,tab1+3,tab1+4,tab1+5,};
    Y = &tab1;
    Z = &tab2;

    A = X;
    A = &(*Y)[0];
    A = (*Z)[2];

    //B = &(X[0]);
    //B = (*Y) huj kurwa wie

    int C[3];
    char NAP[4][5] = {"nap1", "nap2","nap3"};
    double T[][2] = {{1.0,1.0},{0.},{2.0,3.0}};

    int (*a)[3] = &C;
    char *b = NAP[2];
    char c = *NAP[1];
    //double d[2][2] = (double [][2]){1.0, 3.0, 4.0};
    char (*e)[5] = NAP;

    return 0;
}

