#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct vector
{
    double x;
    double y;
    double z;

};
struct all_vect
{
    double x;
    double y;
    double z;
    double lenght;
};

double rand_d(double min, double max);
double vect_len( struct vector );
void fill_tab ( struct all_vect *, int );

int main(int argv, char *argc[])
{
    srand(time(NULL));
    int ile = 5;//atoi(argc[1]);
    struct all_vect tab_vect[ile];

    for(int i = 0; i < ile; i++)
    {     
        tab_vect[i].x = rand_d(-100.,100.);
        tab_vect[i].y = rand_d(-100.,100.);
        tab_vect[i].z = rand_d(-100.,100.);
    }
    
    fill_tab(tab_vect, ile);
    printf("Wylosowane: \n");
    for(int i = 0; i < ile; i++)
    {
        printf("%d. %.2lf %.2lf %.2lf %.2lf \n",i,tab_vect[i].x,tab_vect[i].y,tab_vect[i].z,tab_vect[i].lenght);
    }
    printf("\nPosortowane:\n");

    int mn_index;
    struct all_vect temp;

    for(int i = 0; i < ile - 1; i++)
    {
        mn_index = i;
        for(int j = i + 1;j < ile; j++) 
            if(tab_vect[j].lenght < tab_vect[mn_index].lenght)
                mn_index = j;
        //swap
        temp = tab_vect[i];
        tab_vect[i] = tab_vect[mn_index];
        tab_vect[mn_index] = temp;
    }
    
    for(int i = 0; i < ile; i++)
    {
        printf("%d. %.2lf %.2lf %.2lf %.2lf \n",i,tab_vect[i].x,tab_vect[i].y,tab_vect[i].z,tab_vect[i].lenght);
    }
    return 0;
}

double rand_d(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
double vect_len( struct vector st )
{
    return sqrt(st.x*st.x + st.y*st.y + st.z*st.z);
}
void fill_tab ( struct all_vect *vect, int size)
{
    struct vector temp;
    for(int i = 0 ; i < size; i++)
    {
        temp.x = vect[i].x;
        temp.y = vect[i].y;
        temp.z = vect[i].z;
        vect[i].lenght = vect_len(temp);
    }
}