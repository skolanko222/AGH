#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
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
            return compare_char2(a,b);
    }

}
int compare_char4(const void *a, const void *b)
{
    char *x = (const char *)a;
    char *y = (const char *)b;

    return strcmp(x,y);

}
int main(void)
{
    srand((unsigned)time(NULL));
    
    char tab[20][15];
    int arr[] = {345,23,4,45,45,356,3,45,2345,345};
    char a, b;

    for(int i = 0; i < 20; i++)
    {  
        for(int j = 0; j < 14; j++)
        {
            a=rand() % (91 - 65) + 65;
            b=rand() % 2;
            if(b) // duze
                tab[i][j] = a;
            else //male
                tab[i][j] = a + 32;
        }
        tab[i][14] = '\0';
        puts(tab[i]);
    }
    printf("\n");
    //qsort(arr,sizeof(arr)/sizeof(int),sizeof(int),compare_int);
    //for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
      //  printf("%d ",arr[i]);
    for(int i = 0; i < 20; i++)
    {

        qsort(tab[i],14,sizeof(char), compare_char1 );
        puts(tab[i]);

    }
    
    printf("\n");

    for(int i = 0; i < 20; i++)// b nie działa
    {

       // qsort(tab[i],14,sizeof(char), compare_char3 );
       // puts(tab[i]);

    }

    qsort(tab,20,sizeof(tab[0]), compare_char4 );

    for(int i = 0; i < 20; i++)// b nie działa
    {

        //qsort(tab[i],14,sizeof(char), compare_char3 );
        puts(tab[i]);

    }

    
    return 0;
}