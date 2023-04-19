#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void file_copy(FILE *file1, FILE *file2)
{
    char c;
    while( (c = getc(file1)) != EOF)
    {
        putc(c,file2);
    }
    rewind(file1);
    rewind(file2);
    
}
int file_cmp (char *a, char *b)
{
    FILE *plikA = fopen(a,"rb");
    FILE *plikB = fopen(b,"rb");
    fseek(plikA , 0, SEEK_END);
    int a_len = ftell(plikA);
    fseek(plikB , 0, SEEK_END);
    int b_len = ftell(plikB);
    fclose(plikA);
    fclose(plikB);
    if(a_len == b_len) printf("Takie same!\n");
    else if(a_len > b_len) printf("Pierwszy jest wiekszy!\n");
    else printf("Drugi jest wiekszy!\n");
    return a_len - b_len;
}
void file_cat (char *a, char *b)
{
    FILE *plikA = fopen(a,"ab+");
    FILE *plikB = fopen(b,"rb");
    char c;
    while((c = fgetc(plikB)) != EOF)
        {
            fputc(c,plikA);
        }
    fclose(plikA);
    fclose(plikB);


}

int main(void)
{
    double test[] = {1.0,2.3,2.1,5.2,1.9,2.9,4.3,4.4,5.0,5.2,3.5};	
		
    FILE *ptr_bin ; //wskaznik do pliku binarnego
    int i;	
    size_t test_len = sizeof(test)/sizeof(*test);

    //zapis tablicy test do pliku binarnego 
    ptr_bin = fopen ("b_1","wb");	
    fwrite(test, 1, sizeof(test), ptr_bin);	
    fclose(ptr_bin);

    //copy
    FILE *ptr_copy = fopen("b_1copy","wb");
    ptr_bin = fopen ("b_1","rb");
    file_copy(ptr_bin,ptr_copy);
    fclose(ptr_copy);
    fclose(ptr_bin);
  
    
    //wczytanie z pliku binarnego
    ptr_bin = fopen ("b_1","rb");	
    double *tab_1 = malloc (sizeof(test));
    fread(tab_1, 1, sizeof(test), ptr_bin);	
    fclose(ptr_bin);
    
    puts("_______bin__________________") ;
    for (i = 0; i < test_len; i++)
        printf ( " tab_1[%d]  %.1f  \n",i, tab_1[i]);
    printf ("\n");  
    
    //wczytanie z pliku binarnego KOPIA
    ptr_bin = fopen ("b_1copy","rb");	
    double *tab_2 = malloc (sizeof(test));
    fread(tab_2, 1, sizeof(test), ptr_bin);	
    fclose(ptr_bin);
    
    puts("_______bin__________________") ;
    for (i = 0; i < test_len; i++)
        printf ( " tab_1[%d]  %.1f  \n",i, tab_2[i]);
    printf ("\n");  

    int size = file_cmp("zad2_A.txt","zad2_B.txt"); //pliki testowe
    printf(" %d\n",size);

    size = file_cmp("b_1","b_1copy");
    printf(" %d\n",size);

    file_cat("zad2_A.txt","zad2_B.txt"); //dzia
    FILE *fptr = fopen("zad2_A.txt", "r");
    char c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
  
    fclose(fptr);


    return 0;
}
