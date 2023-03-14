#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ILOSC_KROKOW 1000

int rand_p(float min, float max, float pg, float pd, float pl, float pp)
{

    float k = (float)rand()/RAND_MAX;
    //  int h;
    float r = k*(max-min) + min;
    //printf ("losowa : %f  ",r);
    if(r>=0 && r<=pg)
    {
        return 0; //pierwszy przedzial dla: pg (0,pg)
        //h=0;
    }

    else if(r>pg && r<=pg+pd)
    {
        return 1; //drugi przedzial dla: pd (pg,pg+pd)
        //h=1;
    }
    else if(r>pg+pd && r<=pg+pd+pl)
    {
        return 2;
        //h=2;
    }

    else if(r>pg+pd+pl && r<=1)
    {
        return 3;
        //h=3;
    }
    //printf("%d \n",h);
    //return 999999;
}

void bladzenie(float *x, float *y,float pg, float pd,float pl,float pp);

int main()
{
    srand(time(0));
    float punkt_x[10] = {0,1,2,3,4,5,6,7,8,9};
    float punkt_y[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i = 1; i <= ILOSC_KROKOW; i++)
    {
        for(int k=0; k<=9; k++)
        {

            bladzenie(&punkt_x[k],&punkt_y[k],0.4,0.1,0.3,0.2);
            //printf("Polozenie czastki nr %d. to: %f,%f \n",k,punkt_x[k],punkt_y[k]);
        }
        //printf("\n");



    }

    for (int j = 0; j <=9; j++)
    {
         printf("Polozenie czastki nr %d. to: %f,%f \n",j,punkt_x[j],punkt_y[j]);
    }

    return 0;
}

void bladzenie(float *x, float *y, float pg, float pd, float pl, float pp)
{
    int kierunek = rand_p(0.,1.,pg,pd,pl,pp);

    if(kierunek == 0)      *y=*y+1;
    else if(kierunek == 1) *y=*y-1;
    else if(kierunek == 2) *x=*x-1;
    else if(kierunek == 3) *x=*x+1;
    //else *x=999999;
    //printf("%d \n",kierunek);
    //printf("%f %f \n",*x, *y);
}
