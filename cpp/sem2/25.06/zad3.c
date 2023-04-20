#include <stdio.h>
#include <stdlib.h>

int main(){
double test[] = {1.0,2.3,2.1,5.2,1.9,2.9,4.3,4.4,5.0,5.2,3.5};	
		
FILE *ptr_txt ;	//wskaznik do pliku tekstowego
FILE *ptr_bin ; //wskaznik do pliku binarnego
int i;	
size_t test_len = sizeof(test)/sizeof(*test);

//zapis tablicy test do pliku binarnego 
ptr_bin = fopen ("b_1","wb");	
fwrite(test, 1, sizeof(test), ptr_bin);	
fclose(ptr_bin);

//zapis tablicy test do pliku tekstowego 
ptr_txt = fopen ("t_1","w");	
for (i = 0; i < test_len; i++)
   fprintf (ptr_txt, "%.1f ", test[i]);
fclose(ptr_bin);

ptr_bin = fopen ("b_1","wb");

fseek(ptr_bin, 0L, SEEK_END);
long int size = ftell(ptr_bin);
double x = 0;
//printf("%d",size);
rewind(ptr_bin);
for(long int i = 1; i < size; i=i+2)
{
    fwrite (&x, sizeof (double), 1, ptr_bin);
    fseek(ptr_bin, 3L, SEEK_CUR);
}
fclose(ptr_bin);


//sprawdzenie
//wczytanie z pliku binarnego
ptr_bin = fopen ("b_1","rb");	
double *tab_1 = malloc (sizeof(test));
fread(tab_1, 1, sizeof(test), ptr_bin);	
fclose(ptr_bin);
 
puts("_______bin__________________") ;
for (i = 0; i < test_len; i++)
   printf ( " tab_1[%d]  %.1f  \n",i, tab_1[i]);
printf ("\n");   

//wczytanie z pliku tekstowego
ptr_txt = fopen ("t_1","r");	
double *tab_2 = malloc (sizeof(test));
for (int i = 0; i < test_len; i++)
   fscanf (ptr_txt, "%lf", tab_2 + i);
    
fclose(ptr_txt);
puts("_______text__________________") ;
for (i = 0; i < test_len; i++) 
  printf ( " tab_2[%d]  %.1f  \n",i, tab_2[i]);

}