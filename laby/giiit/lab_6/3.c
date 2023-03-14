#include <stdio.h>
#include <stdlib.h>

int comp2(int *a, int *b)
{
    return *a-*b;
}

int add2(int *a, int *b)
{
    return *a+*b;
}

int add2_or_comp2(int a, int b, int (*f)(int*, int*))
{
    return f(&a,&b);
}

int main(void)
{
    int x = 2, y = 6;
    printf("Suma: %d\n",add2_or_comp2(x,y,add2) );
    printf("Roznica: %d",add2_or_comp2(x,y,comp2) );

    return 0;
}