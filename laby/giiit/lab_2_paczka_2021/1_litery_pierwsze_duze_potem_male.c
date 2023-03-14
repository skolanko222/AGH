#include <stdio.h>


void insert_sort(char *tab, int size)
{
    char key;
    int i;
    for(int j = 1; j <= size; j++)
    {
        key = tab[j];
        i = j - 1;
        while(i >= 0 && tab[i] > key)
        {
            tab[i+1] = tab[i];
            i = i - 1;
        }
        tab[i+1] = key;
    }
}

int main(void)
{
    char tab[] = {'g','f','e','D','E','w','U'};

    int size = sizeof(tab)/sizeof(char)-1;

    insert_sort(tab, size);

    for(int i = 0; i <= size; i++)
    {
        printf("%c ", tab[i]);
    }

    getchar();


    return 0;
}