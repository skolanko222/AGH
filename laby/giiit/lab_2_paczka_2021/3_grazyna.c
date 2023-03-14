#include <stdio.h>

int main(void)
{
    int TAB[7] = {11,22,33,44,55,66,77};
    int *TAB_P[7];

    TAB_P[0] = TAB+0;
    TAB_P[1] = TAB+1;
    TAB_P[2] = TAB+2;
    TAB_P[3] = TAB+3;
    TAB_P[4] = TAB+4;
    TAB_P[5] = TAB+5;
    TAB_P[6] = TAB+6;

    int ***WSK;
    int **MIN;

    MIN=TAB_P;
    WSK=&MIN;

    for(int i = 0; i<=6; i++)
    {
         
    printf("%d %p \n", *(*(*(WSK)+i)),*(*WSK));

    }
   


    return 0;
}