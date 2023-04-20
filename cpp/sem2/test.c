            /*QUICK SORT TEST*/

#include <stdio.h>
#include <time.h>
#include "tab.c"
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int *tab, int p, int r)
{
    int x = tab[r];
    int i = p - 1;

    for(int j = p; j <= r-1; j++)
    {
        if(tab[j] <= x)
        {
            i++;
            swap(tab + i, tab + j);
        
        }
    
    swap(tab + i + 1, tab + r);

    }

    return i + 1;
}


void quick_sort(int *tab, int p, int r)
{
    if(p < r)
    {
    int q = partition(tab, p, r);

    return quick_sort(tab, p, q-1);
    return quick_sort(tab, q+1, r);
    }
}


int main(void)
{
    clock_t t1, t2;
    //int byte_array_dec[] = {1,45,45,342,2346,23457,6,234566,346,7365,735,67,34567,356,7,5367,456,74,567,567,456,7,4567,34567,2357,25,72,51,25,62345,6234,56,34567};
    //int length_of_array  = sizeof byte_array_dec / sizeof(int);

    t1 = clock();
    
    quick_sort(byte_array_dec_1,0,length_of_array_1-1);

    t2 = clock() - t1;

    printf("Sortowanie %d liczbowej tablicy zajelo: %Lf", length_of_array_1, (long double)(t2 - t1) / CLOCKS_PER_SEC);
    getchar();


    return 0;
}