#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                //QSORT
int strcmp_1    (const void *, const void *);
int fcmpr       (const void *, const void *);
int icmpr       (const void *, const void *);

int main(void)
{
    char huj[][7] = { "slowo2",
                    "slowo1",
                    "slowo3"};
    huj[0][6] = '\0';
    huj[1][6] = '\0';
    huj[2][6] = '\0';
    
    int ps = sizeof ( huj )/ sizeof (* huj );

    //printf("%d", ps);

    qsort(huj,ps,sizeof (* huj ),strcmp_1);

    for(int i = 0; i < ps; i++)
        printf("%s ",huj[i]);

    return 0;
}

int strcmp_1(const void *a, const void *b )
{

    return strcmp( (const char *) a, (const char *) b);

}

int fcmpr ( const void *a, const void *b)
{

    float fa = *( const float *)a;
    float fb = *( const float *)b;
    return (fa > fb) - (fa < fb);

}

int icmpr ( const void *a, const void *b)
{
    return *( const int *)a - *( const int *)b;
}
