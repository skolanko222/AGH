#include <stdio.h>



int suma (int *t, int n, double wynik[]);


int main()
{
    int t[] = {1,10};
    double wynik[5];
    int size = sizeof(t)/sizeof(int);
    
    suma(t,size,wynik);
    
    printf("Min: %lf \n",wynik[0]);
    printf("Max: %lf \n",wynik[1]);
    printf("Srednia: %lf \n",wynik[2]);


    return 0;
}

int suma(int *t, int n, double wynik[])
{
    int min = t[0], max = t[0];
    double suma = t[0];
    
    for(int i = 1; i < n; i++)
    {
        if(t[i] >= max)
            max = t[i];
        if(t[i] <= min)
            min = t[i];
        suma += t[i];
    
    }
    
    //printf("%d %d %d", max, min);
    
    wynik[0] = min;
    wynik[1] = max;
    wynik[2] = suma/n;




}
