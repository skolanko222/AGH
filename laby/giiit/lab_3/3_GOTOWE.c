#include <stdio.h>
#include <time.h>

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
        printf ("\n");    
  }

int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;
 
}
int *find_max_wsk (int *T_F, int *T_L)
{
    int *max = T_F++;
    while (T_F <= T_L)
    {
        if(*max < *T_F) max = T_F;
        T_F++;
    }
    return max;
}

int row_number(int (*arr)[4])
{
    int minim = arr[0][4];
    int minim_w=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(arr[i][j]<minim)
            {
                minim=arr[i][j];
                minim_w=i;
            }
        }
    }
    return minim_w;  


}

int main(void)
{
    srand(time(0));

    int abc[5][4];
    int suma_abc[5] = {0};
    //inicjalizacja
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4; j++)
            abc[i][j] = rand() % 11 - 10;

    }

    for(int (*p)[4] = abc, i=0; p < abc + 5; p++, i++)
    {
        wypisz_i(*p,*p+4); //PRZEKAZUJEMY WIERSZE WIEC *
        suma_abc[i] = suma(*p,4);

    }
    printf("\n SUMA : ");
    wypisz_i(suma_abc,suma_abc + 5);

    int suma_all_1 = suma(*abc,sizeof(abc)/sizeof(int));
    printf("\n%d ",suma_all_1);

    int suma_all_2 = suma(suma_abc,sizeof(suma_abc)/sizeof(int));
    printf("\n%d ",suma_all_2);

    printf("\n%d", row_number(abc));


    return 0;
}