#include <stdio.h>

int zamiana(int *, int *);

int odwroc(int *, int );

int wymien_tablice(int *, int *, int);

int main()
{
    int a=10, b=20;
    
    int tab[] = {1,2,3,4,5,6,7,8,9,23};
    int tab2[] = {34,667,345,234,34,645,2144,5634,54,23};
    
    zamiana(&a,&b);
    
    //printf("%d %d \n\n", a, b); //ok
    
    printf("Tablica przed odwroceniem: ");
    
    for(int i = 0; i < sizeof(tab)/sizeof(int); i++)
        printf("%d ", tab[i]);

    printf("\n");
    
    odwroc(tab,sizeof(tab)/sizeof(int));
    
    printf("Tablica po odwroceniem: ");
    
    for(int i = 0; i < sizeof(tab)/sizeof(int); i++)
        printf("%d ", tab[i]);

    
    
    printf("\n");
    printf("\n");
    
    printf("Tablice przed wymiana: \n");
      
    for(int i = 0; i < sizeof(tab)/sizeof(int); i++)
        printf("%d ", tab[i]);
    
    printf("\n");  
     
    for(int i = 0; i < sizeof(tab2)/sizeof(int); i++)
        printf("%d ", tab2[i]);
    
    printf("\n");

    wymien_tablice(tab,tab2,sizeof(tab)/sizeof(int));
    
    printf("Tablice po wymianie: \n");
    
    for(int i = 0; i < sizeof(tab)/sizeof(int); i++)
        printf("%d ", tab[i]);
    
    printf("\n");
     
    for(int i = 0; i < sizeof(tab2)/sizeof(int); i++)
        printf("%d ", tab2[i]);
    

    return 0;
}

int zamiana(int *x, int *y)
{

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    
}

int odwroc(int *arr, int size)
{

    for(int i = 0; i <= size/2; i++)
    {
      
    zamiana(arr+i,arr+size-i-1);
       
    }

}

int wymien_tablice(int *arr1, int *arr2, int size)
{
    for(int i=0; i<=size; i++)
    {
        zamiana(arr1+i,arr2+i);
    
    }

}

