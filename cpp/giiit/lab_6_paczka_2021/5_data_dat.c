#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read()
{
    char *str;
    int ch;
    int size = 1;

    unsigned len = 0;
    str = malloc(sizeof(char)*size);

    while((ch = fgetc(stdin)) != '\n')
    { 
        if(ch == EOF)
            return NULL;
        str[len++] = ch;
        str = realloc(str, sizeof(char) * (len+1));
        
    }

    str[len++] = '\0';

    return str;

}

int main(int argv, char *argc[]){
    
    char *str;
    short unsigned licznik = 0;    
    while( ( str = read() ) != NULL)
    {
        char *str1 = strtok(str, " \n");
        if(!strcmp(argc[1], str1))
        {
            puts(str);
            licznik++;
        }
            
    }

    printf("W pliku data.dat slowo \"%s\" wystepuje %d razy.",argc[1], licznik);
	
    free(str);

    return 0;
}