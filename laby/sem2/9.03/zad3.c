#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char * slowa[argc-1];
    int k=0;

    if(argc<1)
        printf("Brak argumentow!");
    else
    for(int i = 1; i < argc; i++)
    {
    
        printf("%s \n", argv[i]);
        strcat(argv[1],argv[i]);
   
    }
    
    printf("%s ", argv[1]);
    
    


}
