#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

#define n 4

float d_rand(float min, float max){
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;

}

float srednia(float tab[] ){
   
   float suma;
   
   for(int i=0; i<n; i++){
        suma = tab[i];   
  
   }
   
   
   return suma/n;


    
}



int main(void){

    int i[n];
    srand(time(0));
    
    
    for(int l=0; l<n-1; l++){
        
        i[l]=d_rand(-3.0,3.0);
        
    
    }
    
    printf("%f",srednia(i));
    
    
    
  
    


return 0;
}
