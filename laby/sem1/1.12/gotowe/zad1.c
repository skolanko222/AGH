#include <stdio.h>


int main(void){
    
    int licznik=0;
    
    for(int i=1;i<=100;i++){
    
    if(i%2==0 && i%5!=0 && i%4!=0){
        printf("%d ",i);
        licznik+=1;
    
        }
    }
    
    printf("\nTakich liczb jest: %d\n",licznik);


    return 0;
}
