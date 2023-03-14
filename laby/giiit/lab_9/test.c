#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct liczba
{
    char z;
    union unia 
    {
        int n_c;
        double n_d;
    }u;
};
double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
void struct_prn(struct liczba *h, int size)
{
    for(int i = 0; i<size; i++)
    {
        if(h[i].z == 'd')
        printf("%d. %lf double \n",i,h[i].u.n_d);
        else
        printf("%d. %d int \n",i,h[i].u.n_c);
    }
}
int cmp_i(const void *a, const void *b)
{
    struct liczba * x = (struct liczba *)a;
    struct liczba * y = (struct liczba *)b;
    if(x->z == 'i' && x->z == 'i')
    {
        if(x->u.n_c < y->u.n_c) return -1;
        else if(x->u.n_c > y->u.n_c) return 1;
        else return 0;
    }
    
}
int cmp_d(const void *a, const void *b)
{
    struct liczba * x = (struct liczba *)a;
    struct liczba * y = (struct liczba *)b;
    if(x->z == 'd' && y->z == 'd' )
    {
        if(x->u.n_d < y->u.n_d) return -1;
        else if(x->u.n_d > y->u.n_d) return 1;
        else return 0;
    }
    
    
}
int lacz(const void *a, const void *b)
{
    struct liczba * x = (struct liczba *)a;
    struct liczba * y = (struct liczba *)b;
    if(x->z == 'i') return -1;
    if(x->z == 'd') return 1;

}

void fun_sort(struct liczba * huj, int size, int i_licz)
{
    qsort(huj,size,sizeof(huj[0]),lacz); //pierwsze ustawiamy int na początku
    qsort(huj,i_licz,sizeof(huj[0]),cmp_i); //sortujemy pierwszą część
    qsort(huj+i_licz,size-i_licz,sizeof(huj[0]),cmp_d); //sortujemy część z doublami
    
}
int cmp_i_bs(const void *a, const void *b)
{
    return *((int*)a) - ((struct liczba *)b)->u.n_c;
}
int cmp_d_bs(const void *a, const void *b)
{
    double *key = (double *)a;
    double y = (*((struct liczba *)b)).u.n_d;
    if(fabs(*key-y) < 0.1) return 0;
    else if(*key < y) return -1;
    else if(*key > y) return 1;

}

int main(void)
{
    srand(time(NULL));
    struct liczba arr[50];
    int d_licz = 0;
    int i_licz = 0;

    for(int i = 0; i < 50; i++)
    {
        int war = rand() % 2;
        if(war == 0)
        {
        arr[i].u.n_c = -5 + rand() % 11;
        arr[i].z = 'i';
        i_licz++;
        }
        if(war == 1)
        {
        arr[i].u.n_d = randfrom(-5.,5.);
        arr[i].z = 'd';
        d_licz++;
        }
    }
    
    //struct_prn(arr,50);
    printf("\nPosortowana:\n");
    fun_sort(arr,50,i_licz);
    struct_prn(arr,50);
    
    int key_i = 2; 
    char z = 'd';
    double key_d = 4.1;
    struct liczba * wynik = NULL;
    
    if(z == 'i')
    {
        wynik = bsearch(&key_i,arr,i_licz,sizeof(arr[0]),cmp_i_bs);
    }
    else if(z == 'd')
    {
        wynik = bsearch(&key_d,arr + i_licz,d_licz,sizeof(arr[0]),cmp_d_bs);  
    }
    if(wynik != NULL && z == 'i')
        printf("Znaleziono. %d",wynik->u.n_c);
    else if(wynik != NULL && z == 'd')
        printf("Znaleziono. %lf",wynik->u.n_d);
    else
        printf("nie ma");      
    return 0;
}