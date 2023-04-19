#include <stdio.h>
#include <stdlib.h>

/*Proszę napisać i przetestować funkcję/procedurę  razem , która dwie dowolnie długie posortowane rosnąco tablice łączy w jedną tablicę posortowaną rosnąco (bez sortowania).*/

void razem(int a[], int b[],int wynik[],int a_w, int b_w);


int main()
{

    int tab1[] = {77,88,88,99,100};
    int tab2[] = {3,4,13,45,54,55,56,66};

    int w1 = sizeof(tab1)/sizeof(tab1[0]);
    int w2 = sizeof(tab2)/sizeof(tab2[0]);
    
    int zloczona[w1+w2];

    razem(tab1,tab2,zloczona,w1,w2);
    
    for(int i=0; i<w1+w2; i++)
    {
        
        printf("%d ",zloczona[i]);
    
    }


    return 0;
}

void razem(int a[], int b[],int wynik[],int a_w, int b_w)
{
    int i=0, j=0, licznik=0; 

    while(i<a_w && j<b_w)
    {

        if(a[i]<b[j])
        {
            wynik[licznik]=a[i];
            i++;
        }
        else
        {
            wynik[licznik]=b[j];
            j++;
        }

        licznik++;
    }
   
    while(i < a_w)
    {
        wynik[licznik] = a[i];
        licznik++;
        i++;
    }

    while(j < b_w)
    {
        wynik[licznik] = b[j];
        licznik++;
        j++;
    }
    
    
}
