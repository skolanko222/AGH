#include <stdio.h>


void swap(int *a, int *b)
    {
     int temp = *a;
     a = *b;
     b = temp;
     return;
    }
    
    
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

int * find_min_wsk(int *, int);

void sort (int *, int *);

int main()
{
    
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};

    int size = sizeof(tab_A)/sizeof(int);
    int *p = find_min_wsk(tab_A, size);
    
    //printf("Najmniejsza wartosc tab_A: %d, adres: %p, index: %d ", *p, p, p-tab_A+1);

    sort(tab_A, tab_A+size);    
    
    wypisz_i(tab_A, tab_A+size-1);
    
    return 0;
}

int * find_min_wsk(int *arr, int size)
{
    int min = *arr, min_licznik = 0;
    
    for(int i = 1; i < size; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            min_licznik = i;    
               
        }
        
 
    }
    

    return arr+min_licznik;
}

void sort (int *arr_start, int *arr_end)
{
   
    int size = arr_end-arr_start, *min;
      
    for(int i = 1; i < size; i++)
    {
        min = find_min_wsk(arr_start+i, size);
        swap(min, arr_start+i-1);
        
    }
    
 
}
