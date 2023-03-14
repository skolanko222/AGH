#include <stdio.h>
void wypisz_i (int *poczatek, int *koniec) { 
    int i=0,j=0;
    while (poczatek <= koniec)
    {

        printf ("TAB[%d][%d] = %d  ",j,i, *poczatek++);

        
        i==4 ? printf("\n") && ++j && (i=0) : i++; //XD
    } 
           
        printf ("\n");    
  }

void transponowanie(int start[5][5])
{
    int temp,i = 1,j = 0 ,k= 0;
    while(i<=4 && j<=4)
    {
        temp = start[i][j];
        start[i][j] = start[j][i];
        start[j][i] = temp;

        i==4 ? ++j && (i=1+k) && ++k : i++;

    }


}

void pod(int start[5][5])
{
    int temp,i=1,j=0,k=0;
    while(i<=4 && j<=4)
    {
        printf ("TAB[%d][%d] = %d ",i,j, start[i][j] );

        i==4 ? ++j && (i=2+k) && ++k : i++;

    }



}

void wypelnij(int (*abc)[5], int wiersze)
{

    for(int i = 0; i < wiersze; i++)
    {

        for(int j = 0; j < 5; j++)
        {
            
            abc[i][j] = i;

        }

    } 


}

int main(void)
{
    int abc[5][5] = {0};
    int ile_wierszy = sizeof(abc) / sizeof(int) / 5;

    wypelnij(abc,ile_wierszy);
   
    wypisz_i(*abc, *abc + 24);
    
    transponowanie(abc);
    
    wypisz_i(*abc, *abc + 24);
    
    pod(abc);


    return 0;
}