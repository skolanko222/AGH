#include <stdio.h>
#include <string.h>

char * strcombine(char *TEXT_1,char *TEXT_2,char *TEXT_3)
{
    char *temp = strtok(TEXT_1,TEXT_2);
    temp = strtok(TEXT_1,TEXT_2);
    return temp;

}

int main(void)
{
    char tab1[] = "Jak sie ne sie ma";
    char tab2[] = "sie";
    char tab3[] = "ma";
    puts(strcombine(tab1, tab2, tab3));

    return 0;
}