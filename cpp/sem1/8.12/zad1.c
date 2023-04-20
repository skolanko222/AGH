#include <stdio.h>


int odwracanie(double *n){
    
    float odwr;
    
    
    odwr=1/(*n);


    return odwr;

}



int main(void){

    double a;
    
    scanf("%f", &a);
    
    printf("%f",odwracanie(&a));


return 0;
}
