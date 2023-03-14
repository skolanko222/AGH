#include <stdio.h>
#include <time.h>
void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.1f,", *poczatek++); 
  printf ("\n");    
  return;}

double suma (double *tab, int len) {
  int i; 
  double ss = 0.0;
  for (i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}

double *find_min_wsk (double *T_F, double *T_L){  
   double *min = T_F++;
  
   while (T_F < T_L){
      if(*min > *T_F) min = T_F;
      T_F++;
   }
   return min;}


int row_number(double (*arr)[4], int dl);

double *fun_find(double (*arr)[4]) ;   

int main(void)
{
    srand(time(0));
    double abc[5][4] = {
                {1,-1,1,9},
                {1,1.34,1,1},
                {-1,-6,3,3},
                {4,4,4,4},
                {1,1,1,1},
    };
    double suma_abc[5];
    for(int i = 0; i < 5; i++){
        wypisz_d(*(abc+i),*(abc + i) +4);
        suma_abc[i] = suma(*(abc+i),4);
    }
    printf("\n Sumy wierszy: ");
    wypisz_d(suma_abc, suma_abc+5);

    double suma_all_1 = suma(*abc,20);
    double suma_1_2 = suma(*abc+10,10);
    printf("\nSuma calej i polowy: %lf %lf ",suma_all_1,suma_1_2);
    
    int max_wiersz = row_number(abc, 5);
    
    printf("\nWiersz zawierajacy max: %d",max_wiersz);
    printf("\n");
    wypisz_d(*abc+max_wiersz,*abc+max_wiersz+4);





    return 0;
}
int row_number(double (*arr)[4], int dl)
{
    int max = arr[0][0], wiersz =0;
    for(int i = 0; i< dl; i++)
        for(int j = 0; j<4; j++)
        {

            if(arr[i][j] > max)
            {
                
                max = arr[i][j];
                wiersz = i;

            }

        }

    return wiersz;

}

double *fun_find(double (*arr)[4])
{


    
}