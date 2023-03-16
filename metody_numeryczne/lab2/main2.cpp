#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#define N 5

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out

void gaus(gsl_matrix *A, gsl_vector *B);
void vector_save(std::fstream &file, gsl_vector *B, double q);
void wypisz(gsl_matrix *A, gsl_vector *B);
void odch(std::fstream &file, gsl_matrix *A_org, gsl_matrix *B, gsl_vector *B_org, double q);
void save_matrix(std::fstream &file, gsl_matrix *A, const char * str)
{
    file << str << std::endl;
    for(int i = 0; i < A->size1; i++)
    {
        for(int j = 0; j < A->size2; j++)
        {
            file.width(10);
            file << gsl_matrix_get(A, i, j) << "\t";
        }
        file << "\n";
    }
    file << "\n";
}
int main()
{
    double q=0.0;
    
    //wczytanie macierzy A z pliku a.txt
    FILE *t = fopen("a.txt", "r");
	gsl_matrix *A_org = gsl_matrix_calloc(N, N);
	gsl_matrix_fscanf(t, A_org);
	fclose(t);

    //wczytanie wektora B z pliku b.txt
	t = fopen("b.txt", "r");
	gsl_vector *B_org = gsl_vector_calloc(N);
	gsl_vector_fscanf(t, B_org);
	fclose(t);

    gsl_matrix *A = gsl_matrix_calloc(N, N);
    gsl_vector *B = gsl_vector_calloc(N);

    std::fstream plik;
	plik.open("out2.txt");

    while(q<3.0)
    {
        //gaus bedzie nadpisywal wyslana macierz wiec dzialamy na kopiach, ustawienie odpowiedniej wartosci q
        gsl_matrix_set(A_org,0,0,2*q);
        gsl_matrix_memcpy(A, A_org);
        gsl_vector_memcpy(B, B_org);

        gaus(A, B);
        //vector_save(plik, B, q);

        //zrobienie z wektora wynikow macierzy aby dziala metoda mnozaca macierze
        gsl_matrix *B_r = gsl_matrix_calloc(N, 1);
	    for(size_t i = 0; i < N; i++)
	 	    gsl_matrix_set(B_r,i,0,gsl_vector_get(B,i));

        odch(plik, A_org, B_r, B_org, q);


        gsl_matrix_free(B_r);
        q+=0.01;
    }

    gsl_vector_free(B_org);
    gsl_vector_free(B);
    gsl_matrix_free(A_org);
    gsl_matrix_free(A);
    plik.close();

    return 0;
}

void gaus(gsl_matrix *A, gsl_vector *B)
{
    for(int i=0; i<N; i++)
    {
        double div=gsl_matrix_get(A,i,i);
        gsl_vector_set(B,i, (gsl_vector_get(B,i)/div) );
        for(int j=i; j<N; j++)
        {
            gsl_matrix_set(A,i,j, gsl_matrix_get(A,i,j)/div);
        }
        
        //wypisz(A, B);
        
        for(int j=i+1; j<N; j++)
        {
            double div2 = gsl_matrix_get(A,j,i) / gsl_matrix_get(A,i,i);
            double temp =gsl_vector_get(B,j) - (div2 * gsl_vector_get(B,i));
            gsl_vector_set(B, j, temp);
            for(int k=i; k<N; k++)
            {
                gsl_matrix_set(A, j ,k, gsl_matrix_get(A,j,k) - (gsl_matrix_get(A,i,k) * div2));
                
                //wypisz(A, B);
            }
        }
    }

    for(int i = N-1; i>=0 ; i--)
	{
		for(int j = i-1;j >=0; j--)
		{
			double div = gsl_matrix_get(A,j,i) / gsl_matrix_get(A,i,i);
			gsl_vector_set(B,j,gsl_vector_get(B,j) - (gsl_vector_get(B,i) * div));
			gsl_matrix_set(A,j,i,gsl_matrix_get(A,j,i) - (gsl_matrix_get(A,i,i) * div));

            //wypisz(A, B);
		}

	}
}

void vector_save(std::fstream &file, gsl_vector *B, double q)
{
    file << "***********************************DLA Q = "<< q <<"***********************************" <<"\n";
    for(int i = 0; i < N; i++)
    {
            file.width(15);
            file << gsl_vector_get(B, i);
    }
    file << "\n";
}

void wypisz(gsl_matrix *A, gsl_vector *B)
{
    for(int i = 0; i < N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cout.width(15);
            std::cout << gsl_matrix_get(A, i, j);
        }
        std::cout << "\t\t";
        std::cout << gsl_vector_get(B, i);
        std::cout << "\n";
    }
    std::cout << "\n\n\n";
}

void odch(std::fstream &file, gsl_matrix *A_org, gsl_matrix *B, gsl_vector *B_org, double q)
{
    //mnozenie macierzy
    gsl_matrix *C = gsl_matrix_calloc(N, N);
	for (int i = 0; i < A_org->size1; i++)
    {
        for (int j = 0; j < B->size2; j++)
        {
            double temp = gsl_matrix_get(C,i,j);
            for (int k=0; k < A_org->size2; k++)
            {
                temp += gsl_matrix_get(A_org,i,k) * gsl_matrix_get(B,k,j);
            }
            gsl_matrix_set(C,i,j, temp);
        }
    }
    
    //wyliczenie i wypisanie odchylenia
    double odchylenie = 0.0;
    double temp;
	for(int i = 0; i < N; i++)
	{
		temp = gsl_matrix_get(C,i,0) - gsl_vector_get(B_org,i);
		odchylenie += temp*temp;
	}
	odchylenie = sqrt(odchylenie)/5.0;
	save_matrix(file, A_org, "A");
    save_matrix(file, C, "C");
    vector_save(file, B_org, q);
    file << "odchylenie: " << odchylenie <<"\n\n\n";
    gsl_matrix_free(C);
}