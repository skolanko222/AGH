#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    float var;
}str;
int cmp2(const void*a, const void *b)
{
    float fa = *((const float*)a);
    float fb = ((const str*)b)->var;
    return ((fa>fb)-(fa<fb));
}
int main(void)
{
    str tab[4];
    tab[0].var=1.0;
    tab[1].var=2.0;
    tab[2].var=3.8;
    tab[3].var=4.7;

    float test = 3.8;

    //str *indeks = bsearch(&test, tab, 4, sizeof(str), cmp2);
    int i = bsearch(&test, tab, 4, sizeof(str), cmp2) - tab;

    printf("%d ", i);
    return 0;
}