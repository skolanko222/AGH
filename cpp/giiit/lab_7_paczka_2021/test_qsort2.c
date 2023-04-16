#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strcmp_1(const void *, const void * );

int main(void)
{

    return 0;
}

int strcmp_1(const void *a, const void *b )
{

    return strcmp( (const char *) a, (const char *) b);

}