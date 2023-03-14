#include <stdio.h>

int main(void){

    char c,d;
    int sr=0;
    
    do{
        printf("Podaj litere: ");
        scanf("%c",&c);
      
    }while(c<64 || c>91);
    d=c;
    
    
    if(!(sr+64==c)){
    
            for(int i=c; i>64+sr; i--){
                
                printf("%c",d);
                d=d-1;
            
            }
            d=d+2;
            for(int i=d; i<=c; i++){
                
                printf("%c",d);
                d=d+1;
            
            }
            printf("\n");
            
            sr++;logout
    
    }

return 0;
}
