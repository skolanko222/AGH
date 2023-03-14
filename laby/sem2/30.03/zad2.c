#include <stdio.h>

void wypisz_d (double *poczatek, double *koniec) 
{ 
    while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
    printf ("\n");    
    return;
}

double suma (double *tab, int len) 
{ 
    double ss = 0.0;
    for (int i = 0; i < len; i++)  
        ss+= tab[i]; 
    return ss;
}

double *find_min_wsk (double *T_F, double *T_L)
{  
    double *min = T_F++;
      while (T_F < T_L)
      {
        if(*min < *T_F) min = T_F;
        T_F++;
      }
   return min;
}

double **find_tab(double **TAB, int wiersze, int *SIZE_ARR)
{
    double suma_d[wiersze];
    for(int i = 0; i < wiersze; i++)
    {

        suma_d[i] = suma(TAB[i], SIZE_ARR[i]);

    }

    //printf("%lf",suma_d[4]);
    
    double *p = find_min_wsk(suma_d, (suma_d + wiersze));
    int i = suma_d + wiersze - p;

    return TAB + i;

}
void swap(int* a, int* b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}
void swap_pointer(double **ar1, double **ar2)
{
    double *temp = *ar1;
    *ar1 = *ar2;
    *ar2 = temp;

}

void sort (double **TAB, int wiersze, int *SIZE_ARR)
{

    for(int i = 0; i < wiersze; i++)
    {
        double **p = find_tab(TAB+i, wiersze-i, SIZE_ARR+i);
        swap_pointer(p,TAB+i);
        //printf("%d",(*TAB+wiersze-*p));
        swap(SIZE_ARR + (p-TAB), SIZE_ARR+i); //zle
    }


}


int main(void)
{

    double  T_0[ ] = {1.0, 3.0, 2.0, 1.5, 1.5};
    double  T_1[ ] = {1.8, 2.0, 1.2};
    double  T_2[ ] = {5.6, 1.0, 3.3, 3.3};
    double  T_3[ ] = {1.1, 2.1, -6.5, 1.7, 0.4, 1.7};
    double  T_4[ ] = {6.7, 7.8, -9.1, 0.1};

    double *TAB[5] = {T_0, T_1, T_2, T_3, T_4};

    int T_size [] = {sizeof(T_0)/sizeof(double),
                    sizeof(T_1)/sizeof(double),
                    sizeof(T_2)/sizeof(double),
                    sizeof(T_3)/sizeof(double),
                    sizeof(T_4)/sizeof(double),};

    for (int i = 0; i < sizeof(TAB)/sizeof(double); i++){
       for (int j = 0; j < T_size[i]; j++)
	    printf("TAB[%d][%d] = %.1lf ",i, j, TAB[i][j]);
        printf ("\n");
    }

    double **p = find_tab(TAB, 5, T_size);
    //int size = sizeof(*p)/sizeof(double); 
    printf("Wiersz z suma min: ");
    wypisz_d(*p,*p + T_size[p-TAB]);

    sort(TAB,5,T_size);
    
    for (int i = 0; i < sizeof(TAB)/sizeof(double); i++){
       for (int j = 0; j < T_size[i]; j++)
	    printf("TAB[%d][%d] = %.1lf ",i, j, TAB[i][j]);
        printf ("\n");
    }

    return 0;
}