 #include <stdio.h>

void swap_tab(int *a, int *b, int size);
void swap_row(int n, int (*TAB)[n], int x, int y);
void swap(int *a, int *b);
int  suma(int *poczatek, int *koniec);
int *find_min(int *arr, int size);
void wypisz_i (int *poczatek, int *koniec);

void sort(int row, int col, int arr[][col]);

int main(void)
{
    int tab_1[8][5] = {{1,334,1,34,1},{2,2,2,2,2},{3,3,-232343,3,3},{4,4,345,-78,4},{1,334,1,34,1},{2,2,2,2,2},{3,3,-232343,3,3},{4,4,4,-78,4}};
    sort(8,5,tab_1);
    for(int i = 0; i < 8; i++)
        wypisz_i(tab_1[i], tab_1[i]+5);


    return 0;
}

void sort(int row, int col, int arr[][col])
{
    int suma_w[row];
    int min_licznik;

    for(int i = 0; i < row; i++)
    {
        suma_w[i] = suma(arr[i], arr[i] + col);

    }

    for(int i = 0; i < row; i++)
    {
        min_licznik = find_min(suma_w + i, row - i) - suma_w;
        swap_row(col, arr, i, min_licznik);
        swap(suma_w + i,suma_w + min_licznik);
        
        //printf("%d ",min_licznik);

    }
    

}

int *find_min(int *arr, int size)
{
    int *temp = arr;
    
    for(int i = 1; i < size; i++)
        if(arr[i] < *temp)
            temp = arr + i;

    return temp;
}

void swap_tab(int *a, int *b, int size)
{
    for(int i = 0; i < size; i++)
        swap(a+i,b+i);

}
void swap_row(int n, int (*TAB)[n], int x, int y)
{

    swap_tab( *(TAB+x), *(TAB+y), n);

}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

int suma(int *poczatek, int *koniec) 
{
    int ss = 0;
    while (poczatek < koniec)
    ss+= *poczatek++;
    return ss;
}

void wypisz_i (int *poczatek, int *koniec) 
{ 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
        printf ("\n");    

}