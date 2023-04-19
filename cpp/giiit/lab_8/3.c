#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
struct vector
{
    double x;
    double y;
    double z;

};

struct all_vector
{
    double x;
    double y;
    double z;
    double lenght;
    
};
double vect_len(struct vector a);

void fill_tab(struct all_vector * vector, int ile);

int cmp(const void * a, const void *b)
{
    double x = (*(struct all_vector *)a).lenght;
    double y = (*(struct all_vector *)b).lenght;

    if (x > y) return 1;
    else if (x < y) return -1;
    else return 0; 

}
int cmp2(const void * a, const void *b)
{
    double x = *(double *)a;
    double y = (*(struct all_vector *)b).lenght;

    return (x > y) - (x < y);

}

double rand_d( double min, double max )
{
    double scale = rand() / (double) RAND_MAX; 
    return min + scale * ( max - min );      
}
int main()
{
    srand(time(NULL));
    int argv; char *argc[] = {"5"};

    int l = atoi(argc[0]);
    struct all_vector *tab_vect = malloc(sizeof(struct all_vector)*l);

    for(int i = 0; i < l; i++ )
    {
        tab_vect[i].x = rand_d(-10,10);
        tab_vect[i].y = rand_d(-10,10);
        tab_vect[i].z = rand_d(-10,10);

    }
    fill_tab(tab_vect,l);
    //wypisz
    for(int i = 0; i < l; i++)
    {
        printf("%d. %3.2lf %3.2lf %3.2lf %3.3lf \n",i +1,tab_vect[i].x,tab_vect[i].y,tab_vect[i].z,tab_vect[i].lenght);
    }
    printf("\n");
    //sortowanie
    qsort(tab_vect, l, sizeof(tab_vect[0]), cmp);
    for(int i = 0; i < l; i++)
    {
        printf("%d. %3.2lf %3.2lf %3.2lf %3.3lf \n",i +1,tab_vect[i].x,tab_vect[i].y,tab_vect[i].z,tab_vect[i].lenght);
    }

    double key = tab_vect[0].lenght;
    struct all_vector * p = bsearch(&key,tab_vect,l,sizeof(tab_vect[0]),cmp2);
    int licznik = 0;
    int dl = 0;
    if(p == NULL)
        printf("Nie znaleziono ani jednego.");
    else
    {
        while(p)
        {
            licznik++;
            dl = l - (p - &tab_vect[0])/sizeof(tab_vect[0]) - 1;
            p = bsearch(&key,p,dl,sizeof(tab_vect[0]),cmp2);
        }
        
        printf("Znaleniono %d razy.",licznik);
    
    }


}
double vect_len(struct vector a)
{
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

void fill_tab(struct all_vector * vector, int ile)
{
    struct vector temp;
    for(int i = 0; i < ile; i++)
    {
        temp.x = vector[0].x;
        temp.y = vector[0].y;
        temp.z = vector[0].z;

        vector[i].lenght = vect_len(temp);
    }
       

}