#include <stdio.h>
#include <stdlib.h>
void wypisz_f (float *poczatek, float *koniec) 
{ 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;
}

void swap(float*a, float*b){
         float temp = *a;
         *a = *b;
         *b = temp;
         return;}

int main(void)
{
    float TAB_2[7] = {1,2,3,4,5,6,7};
    float *TAB_1[7] = {TAB_2,TAB_2+1,TAB_2+2,TAB_2+3,TAB_2+4,TAB_2+5,TAB_2+6};

    float **WSK, **WSK_1;

    WSK = WSK_1 = TAB_1;

    wypisz_f(*WSK,*WSK+7);

    //printf("%p", TAB_2);

    for(;*WSK > *(WSK_1 + 7); WSK++)
    {

        printf("TAB_1[%ld] = %p \n",  WSK  - WSK_1, *WSK);

    }

    WSK = WSK_1 = TAB_1;

    for(int i = 0; i<3; i++)
    {

        swap(WSK_1[i], WSK_1[6-i]);

    }

    wypisz_f(*WSK_1,*WSK_1 + 7);

    for(;*WSK > *(WSK_1 + 7); WSK++)
    {

        printf("TAB_1[%ld] = %p \n",  WSK  - WSK_1, *WSK);

    }

    
    float *temp = WSK_1[0];

    for(int j = 0; j <= 5; j++)
    {

        WSK_1[j] = WSK_1[j+1]; 

    }
    WSK_1[6] = temp;

    wypisz_f(TAB_2, TAB_2 + 7);
    
    WSK = WSK_1 = TAB_1;
    for(;*WSK > *(WSK_1 + 7); WSK++)
    {

        printf("TAB_1[%ld] = %p \n",  WSK  - WSK_1, *WSK);

    }

    return 0;
}