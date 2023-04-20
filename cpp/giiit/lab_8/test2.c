#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int compare_char2(const void *a, const void *b)
{
    return *(const char*)a > *(const char*)b ? 1 : -1;

}
int compare_char1(const void *a, const void *b)
{
    int x = *(const char *)a; 
    int y = *(const char *)b; 
    if(x > 96 && y < 91)
        return -1;
    else if( x < 91 && y > 96)  
        return 1;
    else
    {
            return compare_char2(a,b);
    }
}
int compare_char3(const void *a, const void *b)
{
    int x = *(const char *)a; 
    int y = *(const char *)b;

    if(x > 96 && y == x - 32)
        return -1;
    else if(x < 91 && y == x + 32)
        return -1;
    else if(x > 96 && y == x - 32)
        return -1;
    else if(x < 91 && y > x + 32)
        return -1;
    else
    {
            //return compare_char2(a,b);
    }

}
int main(void)
{
    char tab[15] = "eEEFfabABiikKl";
                // "HKjrLiKgdERtHu"
    tab[14] = '\0';
    qsort(tab,14,sizeof(char), compare_char3 );

    puts(tab);


    
    return 0;
}