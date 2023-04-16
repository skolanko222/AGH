#include <stdio.h>
#include <stdlib.h>
typedef struct {int a; float var;} str;
int cmp(const void *a, const void *b)
{

    return ((*(float *)a) > ((str *)b)->var) - ((*(float *)a) < ((str *)b)->var);

}


int main(void)
{
    //zad1
    int i;
    char p1[] = "Miki";
    char p2[] = "Tola";
    
    struct 
    {
        int len;
        char *str;
    }var[2] = {{6,p1},{4,p2}}, *p;
    p = var;

    *p->str++;
    *p++->str++;
    (*p->str)++;

    printf("zad1: \n%d %s \n",var[0].len,var[0].str);
    printf("%d %s \n",var[1].len,var[1].str);
    printf("%s \n",p1);
    printf("%s \n\nzad2: hujj",p2);

    //zad2
    struct {
        char tytul[15];
        char autor[15];
        float cena;
        int ilosc;

    }pierwsza,druga;
    struct ksiazka{
        char tytul[15];
        char autor[15];
        float cena;
        int ilosc;

    }trzecia,czwarta;

    //trzecia ==  czwarta;
    druga.cena = trzecia.ilosc;
    //pierwsza.tytul = druga.tytul;
    czwarta.cena = pierwsza.cena / trzecia.ilosc;
    //pierwsza = trzecia;

    //zad 4
    //typedef struct {int a; float var;} str;
    str a, b, c, d,e,f;
    a.var = 1.1;
    b.var = 4.1;
    c.var = 6.9;
    d.var = 7.1;
    e.var = 7.2;
    f.var = 7.3;
    printf("\nzad4:");
    str tab[] = {a,b,c,d,e,f};
    float key = 6.9;
    str * huj = bsearch(&key, tab, sizeof(tab)/sizeof(str),sizeof(str),cmp);
    int index = huj - tab;
    printf("index: %d\n",index);
    printf("%f\n",huj->var);

    //zad3
    struct data{
        float point_A[3];
        float point_B[3];
        char name[2][10];        
    };
    struct graph{
        char name[10];
        struct data edges[3];

    };
    struct graph Tab[5][3];
    struct graph *wsk = Tab[3];
    (wsk - 3)[2].name[0] = 'p'; /// ja pierdole
    ((wsk - 2)[2]).edges->point_A[0] = 69.69;
    ((wsk - 2)[2]).edges->point_B[0] = 430.69;
    ((wsk - 2)[2]).edges->name[0][0] = 's';

    printf("\nzad3:%c ",Tab[2][2].name[0]);// źle


    //zad5

    typedef struct 
    {
        char dl_elast;
        int elastyna[];

    }typ_str;

    int size =69; //???????
    typ_str *ARR = malloc(3*(sizeof(typ_str) + size*sizeof(int) ));
}