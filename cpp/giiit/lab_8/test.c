#include <stdio.h>

struct book
    {
       unsigned page;
       int id;
       float price;
    };

struct book build_struck(unsigned a, int b, float c)
{
    struct book temp;

    temp.id = a;
    temp.page = b;
    temp.price = c;    

    return temp;
}

int main(void)
{
    struct book temp2 = build_struck(69, 567,21.37);

    printf("Id: %u Pages: %d Price: %.2f\n",temp2.id,temp2.page,temp2.price);
    

    return 0;
}