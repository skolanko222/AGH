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

int main(void)
{
    srand(time(NULL));
    struct liczba arr[50];
    

    for(int i = 0; i < 50; i++)
    {
        int war = rand() % 2;
        if(war == 0)
        {
        arr[i].u.n_c = -5 + rand() % 11;
        arr[i].z = 'i';
        }
        if(war == 1)
        {
        arr[i].u.n_d = -5. + rand() % 10 + drand48();
        arr[i].z = 'd';
        }
    }

    
    struct_prn(arr,50);

    return 0;
}