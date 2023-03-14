#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
    
void wypisz_i (int *poczatek, int *koniec) 
    { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;
  }
  
int main(void)
    {
    srand(time(0));
    
    int size;
    
    scanf("%d",&size);
    
    int *arr = malloc(size*sizeof(int));
    
    for(int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 11-5;
    
    }

    int *parzyste = malloc(sizeof(int));
    int *nieparzyste = malloc(sizeof(int));
    int size_p = 1,size_n = 1;


    for(int i = 0; i < size; i++)
     {
        if(arr[i]%2!=0) 
        {
            nieparzyste[size_n-1] = arr[i];
            size_n++;
            nieparzyste=realloc(nieparzyste,size_n*sizeof(int));
        }
        else if (arr[i]%2==0) 
        {
            parzyste[size_p-1] = arr[i];
            size_p++;
            parzyste = realloc(parzyste ,size_p*sizeof(int));
        }
    
    }
    
    wypisz_i(arr,arr+size);
    
    printf("Parzyste: ");
    wypisz_i(parzyste ,parzyste + size_p-1);
    
    printf("Nieparzyste: ");
    wypisz_i(nieparzyste,nieparzyste + size_n - 1);

    return 0;	
}