#include <stdio.h>
#include <stdlib.h>
float  min (float *f, float *l){
	float a = *f++;
	while (f < l){
	   if (a > *f) a = *f;
	   f++;
	}
return a;
}

float  max (float *f, float *l){
	float a = *f++;
	while (f < l){
	   if (a < *f) a = *f;
	   f++;
	}
return a;
}

float  avg (float *f, float *l){
	float sum = 0.;
	int i = l-f;
	while (f < l)
    	   sum += *f++;

return sum/i;
}

float  mid (float *f, float *l){
return *(f+(l-f)/2);
}

struct fun
{
    char *nazwa;
    float (*fun_point)(float *, float *);
};

typedef struct fun *tab_str;

tab_str fun_tab(float (*arr[4])(float *, float*), char *napis[], int q)
{
    struct fun *p = malloc(sizeof(struct fun)*q);
    for(int i = 0; i < q; i++)
    {
        (p+i)-> fun_point = arr[i];
        (p+i)-> nazwa = napis[i];

    }

    return p;
}
void fun_prn(struct fun* tab, int len_tab, float (*value)[8], int row)
{
    


}

int main(void)
{
    char* name[]={"min", "max","avg","mid"};

    float data[4][8] = { { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 },
                             { 2.5, 3.1, 1.5, 4.2, 2.5, 3.0, 3.5, 4.2 },
                             { 1.5, 2.0, 0.5, 2.7, 2.5, 3.0, 1.5, 2.0 },
                             { 0.5, 3.0, 0.5, 2.0, 2.0, 3.0, 3.5, 1.0 }}; 

    float (*TAB_FUN[])(float*,float*) = { min, max, avg, mid}; 

    struct fun (*wsk_fun) = fun_tab(TAB_FUN,name,4);
    //fun_prn(wsk_fun,4,data,1);

    free(wsk_fun);
}