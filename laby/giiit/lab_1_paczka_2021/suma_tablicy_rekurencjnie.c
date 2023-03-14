#include <stdio.h>
#include <time.h>
#define N 10

int suma(const int *arr, const int count);

int main(void){

    int tab[N]={1,2,3,4,5,6}, i=0;
    int *p = NULL;

    srand(time(NULL));

    for(p=tab; p < tab + N; p++){
       *p=rand()%29+7;
      printf("p[%d] = %d\n", i++, *p);
    }

    printf("\n");

    int su = suma(tab,sizeof(tab)/sizeof(int)-1);

    printf("su=%d\n",su);

    return 0;
   
}

int suma(const int *arr, const int count) // działa
{
  
    if(count)
        return suma(arr, count-1) + *(arr+count);
    else 
        return *arr;


}
