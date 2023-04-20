#include <stdio.h>
#include <limits.h>

int main(void){ 
    char znak = '7';
    int D;
    
    printf("Zakres liczb typu char: od %d do %d.\n", CHAR_MIN, CHAR_MAX);

	for(int i=CHAR_MIN ;i<CHAR_MAX ;i++)
		printf("%d to %c\n", i, i);

	printf("----- \n");

    printf("%d to %c\n", znak, znak);
    
    znak = 7;
    printf("%d to %c\n\n", znak, znak);
    
    znak = 'A';
    printf("%d to %c\n", znak, znak);
    
    znak = znak+1;
    printf("%d to %c\n", znak, znak);
    
    D = 67;
    printf("%d to %c\n", D, D);
    
    znak = D;
    printf("%d to %c\n", znak, znak);
    

	
	
    return 0;
}