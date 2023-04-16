#include <stdio.h>

#define ZERO 0 //zastapi ZERO na 0 TO NIE JEST ZMIENNA - SZYBSZE OD CONST // int const zero=0g

int main(void){
    printf("Size of int:%d",sizeof(int));


    int i1 = -100, i2 = -200;
    int i3;

    short s1;
    short int s2; //to samo co short

    long l1;
    long int l2; //to samo

    long long L1;
    long long int L2; //to samo

    unsigned u1;
    unsigned int u2; //to samo co unisgned


    i3 = 2*i2-i1;
    printf("Przykladowe liczby calkowite: %d, %d, %d oraz %d, %d.\n\n", i1, i2, i3, i1/i2, -600);
    i3 = 64;
    printf("Dziesietne %d to w systemie osemkowym %o, a w systemie szesnastkowym: %x.\n", i3, i3, i3);
    printf("Dziesietne %d to w systemie osemkowym %#o, a w systemie szesnastkowym: %#x.\n", i3, i3, i3);
    printf("Adres zmiennej i3: %p\n", i3); // wartosc w systemie 16
    printf("Adres zmiennej i3: %p\n", &i3); // to jest adres

    s1 = 32767;
    s2 = s1+1+ZERO;
    printf("s1+1 = %d+1 = %d\n\n", s1, s2);





	//printf
	// https://www.cplusplus.com/reference/cstdio/printf/


	printf("out1 %f \n",4.0);
	printf("out2 %f \n",4);//wypisze dobrze bo ... w rejestrze print f jest 4.0
	printf("------------------ \n");
	printf("out1 %f \n",5.0);//w nastepnej wypisal to co znal wczesniej, bo nie znalazl floata w 46
	printf("out2 %f \n",4);//wypisze dobrze bo ... w rejestrze print f jest 5.0   // zle choc kompilator nie wyisze bledu
	printf("------------------ \n");
	printf("out3 %f \n",4000);//wypisze dobrze bo ...
	printf("out4 %d \n",4); //tu ok
	printf("out5 %d \n",4.0); // tu zle ale niezaleznie do tego co bylo w %d poprezdnim razem
	printf("------------------ \n");
	printf("out3 %f \n",4000);//wypisze dobrze bo ...
	printf("out4 %d \n",5); //tu ok
	printf("out5 %d \n",4.0); // tu zle ale niezaleznie do tego co bylo w %d poprezdnim razem
	printf("------------------ \n");
	printf("out5 %f \n",0); // tu zle ale niezaleznie do tego co bylo w %d poprezdnim razem

	#define pi 3.14159265358979323846264338327950288419716939937510582097494459230781
	printf("------------------ \n");
	printf("---- PRINTF ------ \n");
	printf("------------------ \n");
	printf("out1 %f +\n",(float)pi);
	printf("out2 %g +\n",(float)pi);
	printf("out3 %4.2f +\n",(float)pi);// 4 - przed przecinkem 2 - po przecinku
	printf("out4 %6.2f +\n",(float)pi);// zrobi puste miejsca przed 3
	printf("out5 %-6.2f +\n",(float)pi);// do lewej strony
	printf("out6 %-6.*f +\n",(float)pi,3);//*f jako 3 miejsca po przecinku!!!
	printf("------------------ \n");
	printf("out7 %0.10f +\n",(float)pi);
	printf("out8 %-10.5f +\n",(float)pi);
	printf("out9 %10.5f +\n",(float)pi);
	printf("------------------ \n");
	printf("out10 %10.15lf +\n",(float)pi);  //dziala choc nie poprawnie //float ucina do 6 miejsca po przecinku ale wypisuje jako double
	printf("out11 %10.15lf +\n",(double)pi); //dziala choc ie poprawnie

	printf("------------------ \n");
	printf("out12 %10.25f +\n",(float)1.000000001);//8zer //nie miesci sie we float
	printf("out13 %10.25f +\n",1.000000001f);//8zer //nie miesci sie we float
	printf("out13 %10.25lf +\n",(double)1.000000001);//8zer // double nie potrzebny bo w domysle jest to double
	printf("out14 %10.25Lf +\n",(long double)1.0000000000001f);//12zer   //float zamienione na long double - nie ma szans
	printf("out15 %10.25Lf +\n",(long double)1.0000000000001000);//12zer    //double  zamienione na long double - niby ok
	printf("out16 %10.25Lf +\n",1.0000000000001L); //12zer   prawdziwy long double

	printf("------------------ \n");
	printf("out17 %d +\n",(int)pi*200);
	printf("out18 %d +\n",(int)(pi*200)); //kolejnosc dzialan🤯️
	printf("out18 %2d +\n",(int)(pi*200));
	printf("out19 %14d +\n",(int)(pi*200));
	printf("out20 %-14d +\n",(int)(pi*200));
	printf("out21 %-04d +\n",(int)(pi*200));
	printf("out22 %04d +\n",(int)(pi*200)); // zawsze na 4 miejscach
	printf("out23 %12.9d +\n",(int)(pi*200));
	printf("out24 %*d +\n",5,(int)(pi*200));





    return 0;
}
