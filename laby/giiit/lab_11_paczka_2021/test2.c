#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int (*FF(int T[], int k))[2]
{
    return NULL;
}
int f1(int (*f)(int))
{
    int n=6;
    while((*f)(--n)) printf("! %d !",n);
    return f(n);
}
int f2(int n)
{
    static int i = 5;
    return n*n -6*n + i--;

}
int cmp(const void *a,const void *b)
{

    return strcmp((char*)a,(char *)b);

}

int main(void)
{
    //zad 1
    int TAB[4][6];
    int (*(*a_1)(int *, int ))[2] = FF + 1;

    int (*a_2)[2] = FF(*TAB,6);
    int *a_3 = FF(TAB[0],6)[1];

    //zad2
    char NAP[][5] = {"gap1","nap2","nap3"};

    char *b_1 = *NAP + 1;
    char b_2 = (*NAP[0])++;
    char (*b_3)[][5] = &NAP;

    //zad3
    int TABB[4][6];
    int (*c_1) = TABB[1]; //int (*c_1)[6] = TABB[1];
    int (*c_2)[6] = TABB + 1; //int ((*c_2)[4][6]) = TABB + 1;
    int c_3 = *(TABB + 1)[1];

    //zad4
    //printf("%d",f1(f2));

    //zad5
    char TABBB[][7] = {"Ala","Tola","Lolek","Reksio","Bolek"};
    //printf("%d",sizeof(TABBB)/sizeof(*TABBB));
    qsort(TABBB,sizeof(TABBB)/sizeof(*TABBB),sizeof(*TABBB),cmp);
    for(int i = 0; i < 5; i++)
        printf("%s\n",TABBB[i]);

}











