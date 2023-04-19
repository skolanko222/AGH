#include <stdio.h>
#include <stdlib.h>

void file_swap(FILE *file1, FILE *file2)
{
    FILE *file3 = fopen("temp.txt","wb+");
    if(!file3) {printf("ERROR");exit(-1);} 
    char c;
    while( (c = getc(file1)) != EOF)
    {
        putc(c,file3);
    }
    rewind(file1);
    rewind(file3);
    while( (c = getc(file2)) != EOF)
    {
        putc(c,file1);
    }
    rewind(file2);
    while( (c = getc(file3)) != EOF)
    {
        putc(c,file2);
    }
    fclose(file3);
}

int main (void)
{
    FILE *a = fopen("file1.txt","rb+");
    if(!a) {printf("ERROR");exit(-1);} 
    FILE *b = fopen("file2.txt","rb+");
    if(!b) {printf("ERROR");exit(-1);} 

    file_swap(a,b);
    fclose(a);
    fclose(b);

    return 0;
}