#include <stdio.h>

void zamiana(int *i, int *j);
void odwroc(int *tab, int n);
void wymien_tablice(int *tab1, int *tab2, int dlugosc);

 int main(void){

    int a=10;
    int b=20;

    zamiana(&a,&b);

    printf("a=%d, b=%d \n", a, b); //git 

    int arr1[] = {10,50,34,3443};

    int lenght1=sizeof(arr1)/sizeof(int)-1;

    odwroc(arr1,lenght1);
    
    for(int l=0; l<=lenght1;l++)
        printf("%d ",arr1[l]);
    
    int arr2[] = {1,2,3,4,5},
        arr3[] = {11,12,13,14,15},
        lenght2 = sizeof(arr2)/sizeof(int)-1;

    wymien_tablice(arr2,arr3,lenght2);
    
    printf("\n");
    printf("ARR2 = ");

    for(int k=0; k<=lenght2; k++)
        printf("%d ",arr2[k]);
    printf("\n");
    printf("ARR3 = ");

    for(int k=0; k<=lenght2; k++)
        printf("%d ",arr3[k]);
    
    return 0;
}

void zamiana(int *i, int *j)
{
    int k = *j; 
    *j=*i;
    *i=k;
}

void odwroc(int *tab, int n)
{
    for(int i=0; i<=n/2; i++)
        {
            zamiana(tab+i,tab+n-i);
        }
}

void wymien_tablice(int *tab1, int *tab2, int dlugosc)
{
    for(int i=0; i<=dlugosc; i++)
    {
        zamiana(tab1+i,tab2+i);
    }

}