#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float arg_2[] = {1.0, 1.2, 1.2,1.2,1.2, 1.5, 1.5, 1.5, 1.6, 1.6, 1.8, 1.9, 1000.0};
    float arg_1[] = {1.0, 1.1, 1.1, 1.2};

    float *result = malloc(4*sizeof(float));
    if(!result)
    {
        printf("za malo pamieci");
        exit(-1);
    }

    int r_arg1 = sizeof(arg_1)/sizeof(float);
    int r_arg2 = sizeof(arg_2)/sizeof(float);
    int r_res = 0;
    float last=0.0;

    for(int i=0, j=0, k=0; i<r_arg1 && j<r_arg2; )
    {
        if(last==arg_1[i])
        {
            i++;
            continue;
        }
        if(last==arg_2[j])
        {
            j++;
            continue;
        }
        else if(arg_1[i]<arg_2[j])
        {
            result = realloc(result, (r_res += 1) * sizeof(float));
            result[k]=arg_1[i];
            last = arg_1[i];
            i++;
            k++;
        }
        else if(arg_1[i]>arg_2[j])
        {
            result = realloc(result, (r_res += 1) * sizeof(float));
            result[k]=arg_2[j];
            last = arg_2[i];
            j++;
            k++;
        }
        else if(arg_1[i]==arg_2[j])
        {
            result = realloc(result, (r_res += 1) * sizeof(float));
            result[k]=arg_1[i];
            last = arg_1[i];
            i++;
            j++;
            k++;
        }
    }

    for(int i=0; i<r_res-2; i++)
    {
        printf("%f ", result[i]);
    }
    
    free(result);
    
    return 0;
}