#include <math.h>
#include <iostream>
#include <vector>

// Obliczanie gęstości powietrza na danej wysokości
double ro(double h, double T, double P0) {
    return 0.0289644 / (8.31446 * (T - 0.0065 * h)) * P0* pow((1 - 0.0065 * h / T), 5.255);
}

// Obliczanie oporu areodynamicznego
double F_drag(double v, double Cx, double Sm, double h, double T, double P0) {
    return Cx * ro(h, T, P0) * Sm * pow(v, 2) / 2;
}

double wziuuum(double alfa, int a = 0) {
    // Zmienne
    double x, y, v, Time;
    double pi, g, Cx, diam, Sm, M, T, P0;
    double dt, v_tmp;
    
    // Stałe
    pi = 3.14159265358979;  // Pi, tak +-
    g = 9.807;        // Przyśpieszenie ziemskie[m / s2]

    // Parametry pocisku 155mm ERFB-BB i Armatochaubicy Krab
    //  T. Kuśnierz, METODA WYZNACZENIA WARTOŚCI WSPÓŁCZYNNIKA AERODYNAMICZNEGO
    //  POCISKÓW STABILIZOWANYCH OBROTOWO, WITU
    Cx = 0.187; // Współczynnik tarcia pocisku  

    diam = 155; // Kaliber pocisku [mm]
    Sm = pi * pow((diam / 2 / 1000), 2); // Powierzchnia przekroju[m2]

    M = 48;     // Masa pocisku [kg]
    v = 958.0;  // Początkowa prędkość pocisku [m/s] 334-968

    // Parametry środowiskowe
    T = 273;     //  Temperatura [K]
    P0 = 101300;  //  Ciśnienie znormalizowane [Pa]

    // Przeliczanie kątu wystrzału [deg --> rad]
    alfa = alfa / 180 * pi; //  [deg --> rad]

    // Parametry obliczeniowe
    dt = 0.01;  /*  krok czasowy [s] (Jeżeli program będzie wykonywał się zbyt długo,
                zrezygnuj z dynamicznego obliczania kroku czasowago na początku pętli */

    //  Inicjalizacja wartościami początkowymi
    x = 0.0;     // współrzędna pozioma
    y = 1.0E-5;  //  wsp pionowa
    Time = 0.0;   // Czas lotu pocisku
    std::fstream plik;
    std::vector<double> xv;
    std::vector<double> yv;
    plik.open("trajektoria.txt");
    if(a > 0)
        plik << "trajektoria "<<a<< "\n";
    // Obliczanie trajektorii pocisku w czasie
    while (y > 0.0) {
        //dt=1.0/v;    // Dynamiczny krok czasowy, dla zwiększenia precyzji
                      //  Wykorzystujemy metodę Eulera do obliczenia zmiany położenia,
                      //  szybkości i kąta nachylenia stycznej do toru ruchu pocisku
        x += v * cos(alfa) * dt;    // Wsp. pozioma
        y += v * sin(alfa) * dt;    // Wsp. pionowa (wysokość npm.)
        if(a > 0){
            xv.push_back(x);
            yv.push_back(y);
        }
        // Prędkość tymczasowa
        v_tmp = v + (-F_drag( v,  Cx, Sm,  y,  T,  P0) / M - g * sin(alfa)) * dt;
        alfa -= g * cos(alfa) / v * dt; // Teraz alfa jest nachyleniem toru lotu pocisku
        v = v_tmp;
        Time += dt;
    }    
    // Funkcja zwraca dystans na jaki doleciał pocisk [m]
    for(const auto & i : xv)
        plik << i << ", ";
    plik << std::endl;
    for(const auto & i : yv)
        plik << i << ", ";
    plik << std::endl;
    plik.close();
    return x;
}

double wziuuum_range(double alfa, int a, double heigth, double range) {
    // Zmienne
    double x, y, v, Time;
    double pi, g, Cx, diam, Sm, M, T, P0;
    double dt, v_tmp;
    
    // Stałe
    pi = 3.14159265358979;  // Pi, tak +-
    g = 9.807;        // Przyśpieszenie ziemskie[m / s2]

    // Parametry pocisku 155mm ERFB-BB i Armatochaubicy Krab
    //  T. Kuśnierz, METODA WYZNACZENIA WARTOŚCI WSPÓŁCZYNNIKA AERODYNAMICZNEGO
    //  POCISKÓW STABILIZOWANYCH OBROTOWO, WITU
    Cx = 0.187; // Współczynnik tarcia pocisku  

    diam = 155; // Kaliber pocisku [mm]
    Sm = pi * pow((diam / 2 / 1000), 2); // Powierzchnia przekroju[m2]

    M = 48;     // Masa pocisku [kg]
    v = 958.0;  // Początkowa prędkość pocisku [m/s] 334-968

    // Parametry środowiskowe
    T = 273;     //  Temperatura [K]
    P0 = 101300;  //  Ciśnienie znormalizowane [Pa]

    // Przeliczanie kątu wystrzału [deg --> rad]
    alfa = alfa / 180 * pi; //  [deg --> rad]

    // Parametry obliczeniowe
    dt = 0.01;  /*  krok czasowy [s] (Jeżeli program będzie wykonywał się zbyt długo,
                zrezygnuj z dynamicznego obliczania kroku czasowago na początku pętli */

    //  Inicjalizacja wartościami początkowymi
    x = 0.0;     // współrzędna pozioma
    y = 1.0E-5;  //  wsp pionowa
    Time = 0.0;   // Czas lotu pocisku
    std::fstream plik;
    std::vector<double> xv;
    std::vector<double> yv;
    plik.open("trajektoria.txt");
    bool wzrost = true;
    if(a > 0)
        plik << "trajektoria " << a << "\n";
    // Obliczanie trajektorii pocisku w czasie
    while (y > heigth || wzrost) {
        //dt=1.0/v;    // Dynamiczny krok czasowy, dla zwiększenia precyzji
                      //  Wykorzystujemy metodę Eulera do obliczenia zmiany położenia,
                      //  szybkości i kąta nachylenia stycznej do toru ruchu pocisku
        if (alfa < 0) wzrost = 0;
        x += v * cos(alfa) * dt;    // Wsp. pozioma
        y += v * sin(alfa) * dt;    // Wsp. pionowa (wysokość npm.)
        if(a > 0){
            xv.push_back(x);
            yv.push_back(y);
        }
        // Prędkość tymczasowa
        v_tmp = v + (-F_drag( v,  Cx, Sm,  y,  T,  P0) / M - g * sin(alfa)) * dt;
        alfa -= g * cos(alfa) / v * dt; // Teraz alfa jest nachyleniem toru lotu pocisku
        v = v_tmp;
        Time += dt;
        
    }    
    // Funkcja zwraca dystans na jaki doleciał pocisk [m]
    for(const auto & i : xv)
        plik << i << ", ";
    plik << std::endl;
    for(const auto & i : yv)
        plik << i << ", ";
    plik << std::endl;
    plik.close();
    std::cout << std::abs(range - x) << std::endl;
    return std::abs(range - x);
}