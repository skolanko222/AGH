#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
double (*matrix(int rows, int col, FILE *fp))[]
{
    double (*arr)[col] = malloc(sizeof(double)*rows*col); 
    fread(arr,sizeof(double ),rows*col,fp);
    return arr;
}
void wypisz(int row, int col, double arr[row][col])
{
    printf("Tablica %d x %d:\n",row,col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            printf("%lf ",arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));
    int count = 25;
    double arr[count];
    FILE * fp = fopen("data.dat","wb+");
    for(int i = 0; i < count; i++)
        arr[i] = randfrom(0.,100.);

    fwrite(arr,sizeof(arr)/sizeof(double),sizeof(double),fp);
    rewind(fp);
    
    double (*arr2)[5] = matrix(5,5,fp);
    wypisz(5,5,arr2);
    rewind(fp);
   
    arr2 = matrix(6,6,fp);
    wypisz(6,6,arr2);
    rewind(fp);

    double (*arr3)[4] = matrix(2,4,fp);
    wypisz(2,4,arr2);
    rewind(fp);

    return 0;
}
