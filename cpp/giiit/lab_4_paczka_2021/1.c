#include <stdio.h>
void wypisz_i (int *poczatek, int *koniec)
{ 
    while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
    printf ("\n");    
}
void wypisz_p (int **poczatek, int **koniec)
{ 
    for(int i = 0; i < 7; i++){
    printf ("TAB[%d] = %p ",i, *poczatek++ );   
    printf ("\n");}    
}
void swap_pointer(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;

}


int main(void)
{
    int TAB[7] = {2, 1, 0, 3, 4, 5, 6};

    int *TAB_P[7] = {TAB, TAB+1, TAB+2, TAB+3, TAB+4, TAB+5, TAB+6};
 
    int **WSK, **MIN;

    WSK = MIN = TAB_P;

    wypisz_i(*WSK, *WSK + 7);
    
    printf("\n");
    
    wypisz_p(WSK, WSK + 7);

    for(int k = 0; k < 6; k++ )
    {
        if(**MIN > *(*WSK + k))
        {
            MIN = WSK + k;
        }

    }

    printf("Minimum: %d indeks: %ld \n", **MIN, MIN - WSK);
    swap_pointer(*WSK, *MIN);

    wypisz_i(*WSK, *WSK + 7);
    wypisz_p(WSK, WSK + 7); //ok

    int **temp = WSK;
    *WSK = *(WSK + 6);
    *(WSK + 6) = *temp;

    wypisz_i(*WSK, *WSK + 7);
    wypisz_p(WSK, WSK + 7);


    return 0;
}