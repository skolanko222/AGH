#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char * va_cat (int ile, ...) 
{
    va_list argptr; // zmiennna na stos argumentów funkcji
    
    va_start(argptr,ile); //inicjacia - po zmiennej ile
    char *c;
    char *ret;
    short int dl = 1;
    for(int i = 0; i < ile; i++)
    {
        c = va_arg(argptr, char*); 
        dl += strlen(c);
        if(i == 0) 
        {
            ret = malloc(sizeof(char) * dl); 
            ret[0] = '\0';
        }
        else 
        ret = realloc(ret,sizeof(char) *dl);
        strcat(ret,c);   
       
    }
    va_end ( argptr );
    return ret;

}

int main(void)
{

    char *c = va_cat(5,"jebac ", "pis ", "kurwo", " je ba ", "seks");
    puts(c);
    free(c);
    return 0;
}
