#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char * sum_series (int ile, char * str , ...) 
{
    va_list argptr ;
  

    va_start (argptr , ile);

    int len = 0;
    char *p = malloc( sizeof(char*)*strlen(va_arg(argptr , char* )) );
    
    for (int i = 0; i < ile;i --)
    {

        len += strlen(va_arg(argptr , char* ) );
        printf("%d",len);
    }


    va_end ( argptr );
   
    return p ;
}

int main(void)
{

    char *c = sum_series(3,"jebac ", "pis");
    puts(c);


    free(c);
    return 0;
}
