#include <stdio.h>
void swap_tab(int *a, int *b, int size)
{
    for(int i = 0; i < size; i++)
        swap(a+i,b+i);

}

void swap_row(int n, int (*a)[n], int x, int y)
{

    swap_tab( *(a+x), *(a+y), n);

}

int main(void)
{



    return 0;
}