#ifndef pesel_h
#define pesel_h

#include <iostream>
#include <cstring>

//fukcja oblicza rok urodzenia osoby o przekazanym peselu
int getYear(int *pesel_arr)
{
    if(pesel_arr[2] == 0 || pesel_arr[2] == 1)
        return  1900 + pesel_arr[0]*10 + pesel_arr[1];
    if(pesel_arr[2] == 2 || pesel_arr[2] == 3)
        return  2000 + pesel_arr[0]*10 + pesel_arr[1];
    if(pesel_arr[2] == 4 || pesel_arr[2] == 5)
        return  2100 + pesel_arr[0]*10 + pesel_arr[1];
}
//funkcja wypisuje skonwertowany pesel
void printPesel(int *pesel_arr)
{
    for(int i = 0; i < 11; i++)
        std::cout << pesel_arr[i];
}

//funkcja sprawdza czy rok przestępny
bool leapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));}

//funkcja zwraca cyfrę kontrolną
int getCtrlNumber(int *pesel_arr)
{
    int wagi[] = {1,3, 7, 9, 1, 3, 7, 9, 1, 3}; //tabela wag
    int suma =0 ;
    for(int i = 0; i < 11; i++)
        suma += pesel_arr[i]*wagi[i];
    suma %=10;
    suma = 10 - suma;

    return suma %10;
}

//funkcja zwraca dzień urodzenia z podanego peselu
int getDay(int *pesel_arr)
{
    if(pesel_arr[2] == 0 && pesel_arr[3] == 2 && pesel_arr[4] == 2 && pesel_arr[5] == 9 && !leapYear(getYear(pesel_arr)))
        return 1;
    return pesel_arr[4]*10 + pesel_arr[5];
}

//funkcja oblicza miesiąc urodzenia
int getMonth(int *pesel_arr)
{
    int year = getYear(pesel_arr);
    if(pesel_arr[2] == 0 && pesel_arr[3] == 2 && pesel_arr[4] == 2 && pesel_arr[5] == 9 && !leapYear(year))
        return 3;
    if(year < 2000)
        return pesel_arr[2]*10 + pesel_arr[3];
    if(year >= 2000 && year < 2100)
        return pesel_arr[2]*10 + pesel_arr[3]-20;
    if(year >= 2100)
        return pesel_arr[2]*10 + pesel_arr[3]-40;
    

}
//funkcja konwertuje i zwraca true gdy pesel poprawny
bool PeselValidator(const char* pesel_str, int *pesel_arr)
{
    if(strlen(pesel_str) != 11)
        return false;
    
    for(int i = 0; i < 11; i++)
        pesel_arr[i] = pesel_str[i] - 48;
    if(getCtrlNumber(pesel_arr) != pesel_arr[10]){
        return false;}
    for(int i = 0; i < 11; i++)
        if(pesel_arr[i]<0 || pesel_arr[i]>9) //gdy nie liczba
            return false;

    return true;
}

#endif