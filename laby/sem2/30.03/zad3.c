#include <stdio.h>
#include <string.h>

int main(int argv, char *argc[])
{
    char *napis = argc[1];
    char *spr = argc[2];

    //puts(napis);
    int i=0, j=0;

    char *napis2 = strtok(napis, " ,;.:");
    while (napis2 != NULL)
    {
        napis2 = strtok(NULL, " ,;.:");
        if(!strcmp(napis2, spr))
            i++;
    }
    printf("%d",i);
   // while(*napis)
    {
        //napis = strstr(napis, spr);
        //puts(napis);
        //j++;

    }

    return 0;
}