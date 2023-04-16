#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char sen[] = "The sun did not shine. It was too wet to play. So we sat in the house, All that cold, cold, wet day."; //23 slowa
    char sen2[strlen(sen)+1];
    char spr[] = "we";

    strcpy(sen2,sen);

    char *temp = strtok(sen,", ;.:");
    int i_word = 0;
    int i_let = 0;

    while(temp)
    {
        //puts(temp);
        if(!strcmp(temp,spr))
            i_word++;
        temp = strtok(NULL,", ;.:");

    }
    puts(spr);
    printf("Jako slowo: %d\n", i_word);

    int spr_len = strlen(spr);

    char temp2[spr_len+1];
    for(int i = 0; i < strlen(sen2)-1; i++)
    {
        strncpy(temp2, sen2 + i, spr_len);
        temp2[spr_len+1] = '\0';
        //puts(temp2);
        if(!strncmp(temp2,spr,spr_len))
           i_let++;




    }  
    printf("Jako ciag: %d", i_let);
    //for ( size_t n = 0; n < sizeof sen ; ++n) 
    //{
    //char c = sen [n];
    //c ? printf (" '%c' ", c): printf (" '\\0' ");
    //}
    
    return 0;
}