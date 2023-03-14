#include <stdio.h>

int main(void){ 
    float a;
    double b;
    long double c;
    int calkowita;
    
    a = -1.71e-10;
    printf("Pojedyncza precyzja: %f = %.10f = %.20f\n", a, a, a);
    
    b = -1.71e-10;
    printf("Podwojna precyzja: %f = %.10f = %.20f\n", b, b, b);
    
    c = -1.71e-10;
    printf("long double: %Lf = %.10Lf = %.20Lf\n\n", c, c, c);
    
    printf("Notacja wykladnicza: %e = %e = %Le\n\n", a, b, c);
    
    b = 5/3;
    printf("5 dzielone przez 3 = %f\n\n", b);
    
    printf("Wpisz liczbe rzeczywista: ");
    scanf("%f", &a);   // co bedzie jesli wpisze cos niepoprawnego np litere 'a'?
    printf("Wpisales: %g.\n", a);  //czy mozna wpisac 0.000000000000000000000000001 ? 
    
    printf("Wpisz liczbe calkowita: ");
    scanf("%d", &calkowita);
    printf("Wpisales: %d\n", calkowita);
    
    return 0;
}