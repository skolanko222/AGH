#include <stdio.h>
#include <time.h>
#define N 10

int suma(const int *arr, const int s);

int i_rand(int min, int max)
    {
    return rand() % (max-min+1) + min;
    }


int main(void)
{
    
    srand(time(NULL));
    
    int *p = NULL;
    
    int tab[N];
    
    for(p=tab; p < tab + N; p++)
    {
        *p = i_rand(7,35);
         printf("p[%d] = %d \n",p-tab,*p);
   
    }
    
    int su = suma(tab,sizeof(tab)/sizeof(int));

    printf("Suma: %d \n ", su);

    return 0;
}

int suma(const int *arr, const int s)
{
    int size = s;
    int *arrr; arrr = arr;
    
    if(size--)
        return suma(arrr++, size) + *arrr;
    else
        return *arrr;


}
