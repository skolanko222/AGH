#include <stdio.h>

void write_binar(unsigned n, char * wsk);
int binary_size(int number);
unsigned bits(unsigned x, unsigned n);

int main()
{

    unsigned result, number, bit_num;
    
    printf("Podaj liczbe: ");
    scanf(" %d ", &number);
    
    printf("Podaj liczbe bitow: ");
    scanf(" %d ", &bit_num);
    
    int size = binary_size(number);
    
    //printf("%d ", size);
    
    char number_string[size];
    
    write_binar(number, number_string+size-1);
    
    printf("liczba wczytana %d : %s\n", number, number_string);
    
    result = bits(number, bit_num);
    
    char res[2];
    write_binar(result, res);
    
    
    printf("%u najstarszych bitow %s \n", bit_num, res);
    


}

void write_binar(unsigned n, char * wsk)
{
    *wsk = '\0';
    n<<=32;
    n>>=32;
   
    do
    {
    if(n & 1)
        *wsk = '1';
    else
        *wsk = '0';
    n>>=1;
    wsk--;
    }while(n);


}

int binary_size(int number)
{

    int i=0;
    while(number)
    {
        
        number >>= 1;
        i++;
    
    }

    return i;
}

unsigned bits(unsigned x, unsigned n)
{
    x<<=32;
    x>>=32;
    
    
    int maska = 1;
    for(int j = 1; j <= n; j++)
    {
    
        maska<<=1;
    
    }
    
    
    return (x & (maska-1));

}
