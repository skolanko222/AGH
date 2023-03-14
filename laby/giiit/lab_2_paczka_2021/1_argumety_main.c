#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    
    char *word = "slowo";
    if(argc < 2)
        printf("Nie podano argumentow!");
    else
        for(int i = 1; i < argc; i++)
        {

            printf("%s \n", argv[i]);
            strcat(word, argv[i]);

        }

    printf("%s ", word);

}