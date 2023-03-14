#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void wypisz_d (float *poczatek, float *koniec) 
{ 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;
}

int main(void)
{
    float arg_1[] = {1.5};
    float arg_2[] = {1.2,1.4};
    float *result = malloc(sizeof(float));

    int len_1 = sizeof(arg_1)/sizeof(float);
    int len_2 = sizeof(arg_2)/sizeof(float);

    int len_r = 0;

    int k=0;
    int i = 0, j = 0;
    while(j < len_1 && i < len_2)
    {
        printf("%d ",len_r);
        if((arg_1[i] < arg_2[j]) && (arg_1[i] != arg_1[i+1]))
        {
            len_r += 2;
            result = realloc(result, len_r * sizeof(float));
            result[k] = arg_1[i];
            result[k+1] = arg_2[j];
            k+=2;
            i++;
            j++;

        }
        else if((arg_1[i] > arg_2[j]) && (arg_2[j] != arg_1[j+1]))
        {
            len_r += 2;
            result = realloc(result, len_r * sizeof(float));
            result[k+1] = arg_1[i];
            result[k] = arg_2[j];
            k+=2;
            i++;
            j++;

        }
        else if(arg_1[i] == arg_2[j])
        {
            len_r += 1;
            result = realloc(result, len_r * sizeof(float));
            result[k] = arg_1[i];
            k++;
            i++;
            j++;

        }
        else if(arg_1[i] == arg_1[i+1])
        {
            len_r += 1;
            result = realloc(result,len_r * sizeof(float));
            result[k] = arg_1[i];
            k++;
            i++;
            
        }
        else if(arg_2[j] == arg_2[j+1])
        {
            len_r += 1;
            result = realloc(result,len_r * sizeof(float));
            result[k] = arg_2[j];
            k++;
            j++;
            
        }


    }


    wypisz_d(result, result + len_r);


    return 0;
}

