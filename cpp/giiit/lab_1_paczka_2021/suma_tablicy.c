#include <stdio.h>

float suma(float t[], int n, float wyniki[]);

int main(void)
{
    float t[] = {10,11};
    float wyniki[5];

    printf("%f\n", suma(t,sizeof(t)/sizeof(float)-1,wyniki));
    printf("max: %f min: %f srednia: %f ", wyniki[0],wyniki[1],wyniki[2]);

    return 0;
}

float suma(float t[], int n, float wyniki[])
{
    float suma;
    for(int i=0; i<=n; i++)
        {
            suma+=t[i];         //suma

        }

    float temp1=t[0],
            temp2=t[0];
    for(int i=0; i<=n; i++)
        {
            if(t[i]>=temp1)
                temp1 = t[i];
            if(t[i]<=temp2)
                temp2 = t[i];
        }

    wyniki[0] = temp1;
    wyniki[1] = temp2;
    wyniki[2] = (suma/(n+1));

    return suma;
}