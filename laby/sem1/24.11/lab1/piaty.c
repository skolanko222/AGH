#include <stdio.h>
#include <limits.h>

int main(void){ 

	float a = 1.f;
	float b = 5.e-8;
	printf("a = %g, b = %g\n", a, b);
	printf("a + b + b = %g = %.25f\n", a + b + b, a + b + b);//czemu to nie dziala??
	printf("b + b + a = %g = %.25f\n", b + b + a, b + b + a);
	
	
	
	// Zgadniej co wysietli i czemu
	 
	float f1 =1.5;
	float f2=1.0;
	float f3=0.5;
	float f4;
	
	
	int i1=0;
	int i2=1;
	int i3=5;
	
	int x;
	
	
	 x = 5/2; //wartosc x wynosi 2.
	 x = 5.0/2.0; //wartosc x wynosi 2.
	double y = 5/2; //wartosc y wynosi 2.0.
	 y = 5.0/2; //wartosc y wynosi 2.5.
	 y = 5/(double)2; //wartosc y wynosi 2.5. 
	
	
	x = f1/f2; 
	printf("l1: x= %d \n",x);
	x = f2/f1; 
	printf("l2: x= %d \n",x);
	x = f2/f1 + f2/f1;  //0.66 +0.66
	printf("l3: x= %d \n",x);
	
	x = i1 + f2/f1 +i1 +f2/f1;
	printf("l4: x= %d \n",x); 
	
	f4 = f2/f3/f1;
	printf("l5: f4= %f \n",f4);
	
	f4 = f2/f1/f3;
	printf("l6: f4= %f \n",f4);
	
	f4 = i2/i3/f3;
	printf("l7: x= %f \n",f4);
	
	f4 = i2/f3/i3;
	printf("l8: x= %f \n",f4);
    
    return 0;
}
		
		
		
		
