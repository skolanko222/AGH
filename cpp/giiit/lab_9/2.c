#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    if(x->z == 'i' && x->z == 'd')
    {
        if(x->u.n_c < y->u.n_d) return -1;
        else if(x->u.n_c > y->u.n_d) return 1;
        else return 0;
    }
    if(x->z == 'd' && x->z == 'i')
    {
        if(x->u.n_d < y->u.n_c) return -1;
        else if(x->u.n_d > y->u.n_c) return 1;
        else return 0;
    }
    //else return 1;
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
    if(x->z == 'd' && y->z == 'i' )
    {
        if(x->u.n_d < y->u.n_c) return -1;
        else if(x->u.n_d > y->u.n_c) return 1;
        else return 0;
    }
    if(x->z == 'i' && y->z == 'd' )
    {
        if(x->u.n_c < y->u.n_d) return -1;
        else if(x->u.n_c > y->u.n_d) return 1;
        else return 0;
    }
    
}

void fun_sort(struct liczba * huj, int size, int i_licz)
{

    qsort(huj,size,sizeof(huj[0]),cmp_i);
    qsort(huj+i_licz,size-i_licz,sizeof(huj[0]),cmp_d);

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
    
    struct_prn(arr,50);
    printf("\nPosortowana:\n");
    fun_sort(arr,50,i_licz);
    struct_prn(arr,50);
    
    int key_i = 5; 
    char z = 'i';
    double key_d = 5.;
    
    if(z == 'i')
    {
        struct liczba * wynik = bsearch(&key_i,arr,i_licz,sizeof(arr[0]),cmp_i);
    }
    else if(z == 'd')
    {
        struct liczba * wynik = bsearch(&key_d,arr + i_licz,d_licz,sizeof(arr[0]),cmp_d);  
    }    

    return 0;
}