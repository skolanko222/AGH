#include <stdio.h>

#include <limits.h>
/*

http://www.cplusplus.com/reference/climits/

*/

int main(void){ 
	printf("Zakres liczb typu int: od %d do %d.\n", INT_MIN, INT_MAX);
    printf("Zakres liczb typu short int: od %hd do %hd.\n", SHRT_MIN, SHRT_MAX);
    printf("Zakres liczb typu long int: od %ld do %ld.\n", LONG_MIN, LONG_MAX);
    printf("Zakres liczb typu long long int: od %lld do %lld.\n", LLONG_MIN, LLONG_MAX);
	
	printf("Zakres liczb typu unsigned int: od %d do %d.\n", 0, UINT_MAX);
    printf("Zakres liczb typu unsigned int: od %u do %u.\n", 0, UINT_MAX);

    return 0;
}