#include <stdio.h>
#include <stdlib.h>
int  *flooor(double *a, double *b)
{
    int *p = malloc(sizeof(int));

    *p = (int)*a * (int)*b;
    
    return p;

}

int main(void)
{
    double x = 1.9, y = 2.97;

    int *q = flooor(&x,&y);

    printf("Dwie zmienne: %lf %lf\nPodloga ich iloczynu: %d", x, y, *q);
    
    free(q);
    
    return 0;
}