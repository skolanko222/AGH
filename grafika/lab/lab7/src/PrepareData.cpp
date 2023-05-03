#include <cmath>
#include <array>
#include <vector>
#include <algorithm>
#include "PrepareData.h"
float FunctionData[100][3];
int   NoPoints;
void PrepareData(int fun)
{
 int i;
 float x,y;
 srand(376257);

 switch (fun)
  {
   case 0: NoPoints=5;
        FunctionData[0][0]=-1.0; FunctionData[0][1]= 1.0;	FunctionData[0][2]= 0.0;
	       FunctionData[1][0]= 1.0;	FunctionData[1][1]= 1.0;	FunctionData[1][2]=25.0;
	       FunctionData[2][0]= 1.0;	FunctionData[2][1]=-1.0;	FunctionData[2][2]= 5.0;
	       FunctionData[3][0]=-1.0;	FunctionData[3][1]=-1.0;	FunctionData[3][2]=25.0;
	       FunctionData[4][0]= 0.0;	FunctionData[4][1]= 0.0;	FunctionData[4][2]=15.0;
	      break;
   case 1: NoPoints=20;
           for (i=0; i<NoPoints; i++)
            {
             x=4.8*(float(rand())/RAND_MAX)-2.4;
             y=4.8*(float(rand())/RAND_MAX)-2.4;
             FunctionData[i][0]=x;
             FunctionData[i][1]=y;
             FunctionData[i][2]=200*(float(rand())/RAND_MAX);
            }
          break;
   case 2: NoPoints=100;
           for (i=0; i<NoPoints; i++)
            {
             x=4.8*(float(rand())/RAND_MAX)-2.4;
             y=4.8*(float(rand())/RAND_MAX)-2.4;
             FunctionData[i][0]=x;
             FunctionData[i][1]=y;
             FunctionData[i][2]=x*(2*x-7)*(2*y+1)+2*y;
            }
          break;
   case 3: NoPoints=10;
           for (i=0; i<NoPoints; i++)
            {
             x=4.8*(float(rand())/RAND_MAX)-2.4;
             y=4.8*(float(rand())/RAND_MAX)-2.4;
             FunctionData[i][0]=x;
             FunctionData[i][1]=y;
             FunctionData[i][2]=x*sin(2*y);
            }
          break;
   case 4: NoPoints=100;
           for (i=0; i<NoPoints; i++)
            {
             x=2*(float(rand())/RAND_MAX)-1;
             y=2*(float(rand())/RAND_MAX)-1;
             FunctionData[i][0]=x;
             FunctionData[i][1]=y;
             FunctionData[i][2]=sin(8*(x*x+y*y));
            }
          break;
    }
}
float f_wag(float x, float y, float x_w, float y_w)
{
        return 1./std::pow(std::sqrt(std::pow(x-x_w,2) + std::pow(y-y_w,2)),2);
}

float interpolacja(float x, float y, const float (*arr)[3], const int wezly)
{
        //przeprowadź interpolację Sheparda dla punktu (x,y) i zbioru punktów (arr) o liczbie wezly (wezly) i funkcji wagowej f_wag
        //zwróć wartość interpolacji
        float licznik = 0;
        float mianownik = 0;
        for(int i = 0; i < wezly; i++)
        {
                licznik += arr[i][2] * f_wag(x, y, arr[i][0], arr[i][1]);
                mianownik += f_wag(x, y, arr[i][0], arr[i][1]);
        }
        return licznik / mianownik;
}