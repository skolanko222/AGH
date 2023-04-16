typedef struct
{
    int a;
    float var;
}str;
int cmp(const void*a, const void *b)
{
    float fa = ((const str*)a)->var;
    float fb = ((const str*)b)->var;
    return ((fa>fb)-(fa<fb));
}
int cmp2(const void*a, const void *b)
{
    float fa = *((const float*)a);
    float fb = ((const str*)b)->var;
    return ((fa>fb)-(fa<fb));
}
int main(void)
{
    str tab[4];
    tab[0].a=0;
    tab[1].a=8;
    tab[2].a=5;
    tab[3].a=10;
    tab[0].var=1.0;
    tab[1].var=10.0;
    tab[2].var=6.8;
    tab[3].var=0.7;
    qsort(tab, 4, sizeof(str), cmp);
    const float test = 0.7;
    int indeks = (str*)bsearch(&test, tab, 4, sizeof(str), cmp2) - tab;
    printf("%d ", indeks);
    return 0;
}