#include <stdio.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float  min (float *f, float *l)
{
	float a = *f++;
	while (f < l)
	{
	   if (a > *f) a = *f;
	   f++;
	}
return a;
}
float  max (float *f, float *l)
{
	float a = *f++;
	while (f < l)
	{
	   if (a < *f) a = *f;
	   f++;
	}
	return a;
}
float  avg (float *f, float *l)
{
	float sum = 0.;
	int i = l-f;
	while (f < l)
    	   sum += *f++;
	return sum/i;
}
float  mid (float *f, float *l)
{
return *(f+(l-f)/2);
}
struct fun
{ 
    char *nazwa;
    float (*fun_point)(float *, float *);
};
int rowG;
float (*dataG)[8];
float gapG;
typedef struct fun *tab_str;
tab_str fun_tab(float (*arr[4])(float *, float *), char *napis[], int q);
void fun_prn(struct fun * tab, int len_tab, float (*value)[8], int row);
int cmp(const void * a,const void * b);
void sort_fun(struct fun * tab, int len_tab, float (*value)[8], int row);
int cmp_bs(const void * key,const void * a);
tab_str find_fun(struct fun *tab, int len_tab, float (*value)[8], float row, float key);
int main(void)
{
	float data[4][8] = { { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 },
                             { 2.5, 3.1, 1.5, 4.2, 2.5, 3.0, 3.5, 4.2 },
                             { 1.5, 2.0, 0.5, 2.7, 2.5, 3.0, 1.5, 2.0 },
                             { 0.5, 3.0, 0.5, 2.0, 2.0, 3.0, 3.5, 1.0 }};
	char* name[]={"min", "max","avg","mid"};
	float (*TAB_FUN[])(float*, float*) = {min,max,avg,mid};
	struct fun * wsk_fun =  fun_tab(TAB_FUN,name,4);
	for(int i = 0; i < 4; i++)
		{fun_prn(wsk_fun,4,data,i);printf("\n");}
	printf("\n");
	for(int i = 0; i < 4; i++)
	{
	sort_fun(wsk_fun,4,data,i); //wow działa
	fun_prn(wsk_fun,4,data,i);
	printf("\n");
	}
	struct fun * wynik_bsearch = find_fun(wsk_fun,4,data,3,2.01);
	if (wynik_bsearch == NULL)
	{
		printf("\nnie zaleziono");
	}
	else
	printf("\nZNALEZNIONO: %s(3) = %f",wynik_bsearch->nazwa,(*(wynik_bsearch->fun_point))(data[3],data[3]+8));
	free(wsk_fun);
}
void sort_fun(struct fun * tab, int len_tab, float (*value)[8],int row)
{
	rowG = row;
	dataG = value;
	qsort(tab,len_tab,sizeof(tab[0]),cmp);
}
int cmp(const void * a,const void * b)
{
	float x = (*(*(struct fun *)a).fun_point)(dataG[rowG], dataG[rowG]+8);
	float y = (*(*(struct fun *)b).fun_point)(dataG[rowG], dataG[rowG]+8);
	if(x>y) return 1;
	if(x<=y) return -1;
}
void fun_prn(struct fun * tab, int len_tab, float (*value)[8],int row)
{
	for(int i = 0; i < len_tab; i++)
		printf("%s(%d) = %.2f ", tab[i].nazwa, row, (*tab[i].fun_point)(value[row],value[row]+8));
}
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
int cmp_bs(const void * key, const void * a)
{
	float x = (*(*(struct fun *)a).fun_point)(dataG[rowG], dataG[rowG]+8);
	if(fabs(x - *(float*) key) < 0.05) return 0;
	if(x > *(float*)key) return -1;
	if(x < *(float*)key) return 1;
}
tab_str find_fun(struct fun *tab, int len_tab, float (*value)[8],float row, float key)
{
	rowG = row;
	dataG = value;
	return bsearch(&key,tab,len_tab,sizeof(tab[0]),cmp_bs);
}