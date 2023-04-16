#include <stdio.h>

void swap(int *, int *);

int * find_min_wsk(int *, int *);

void sort(int *, int );

int main(void)
{
    
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};

    int size = sizeof(tab_A)/sizeof(int)-1;

    int *p = find_min_wsk(tab_A, &size);

    //printf("%d ", *p);

    sort(tab_A, size);

    for(int i = 0; i <= size; i++)
        {
            printf("%d ",tab_A[i]);

        }

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;

    return;

}

int * find_min_wsk(int *tab, int *siz)
{
    int min_wartosc = *tab;
    int min_licznik = 0;
    int i;

    for(i = 1; i <= *siz; i++)
    {
        if(*(tab+i) <= min_wartosc)
        {
            min_wartosc = *(tab+i);
            min_licznik = i;
        }
    }

    //printf("%d ", min_licznik);

    return (tab+min_licznik);

}

void sort(int *tab, int n)
{
    int *min_wart=NULL;
    int temp;
    
    for(int i = 0; i <= n; i++)
    {
        temp = n - i;
        min_wart = find_min_wsk(tab+i, &temp);
        //printf("%d ", *min_wart);
        swap(tab+i, min_wart);
    }


}