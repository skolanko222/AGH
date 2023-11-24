#include <math.h>
#include <stdio.h>
#include "mgmres.h"

double rho(int i, int j, double delta, double xmax, double ymax, double sigma)
{
	double rho1 = exp(-pow((delta * i - 0.25 * xmax) / sigma, 2) - pow((delta * j - 0.5 * ymax) / sigma, 2));
	double rho2 = -exp(-pow((delta * i - 0.75 * xmax) / sigma, 2) - pow((delta * j - 0.5 * ymax) / sigma, 2));
	return rho1 + rho2;
}
int j(int l, int nx){return l / (nx + 1);}
int i(int l, int nx){return l - j(l, nx) * (nx + 1);}


void metodaPoissona(double delta, double nx, double ny, double ep1, double ep2, double V1, double V2, double V3,double V4, char useRho, FILE *fp, char writeMatrix){
	int N =(nx + 1) * (ny + 1);
	double xmax = delta * nx;
	double ymax = delta * ny;
	double a[5 * N], b[N], V[N];
	int ja[5 * N], ia[N + 1];

	for(int i = 0; i < 5 * N; i++){
		a[i] = 0;
		ja[i] = 0;
		if(i < N + 1)
			ia[i] = -1;
		if(i < N){
			b[i] = 0;
			V[i] = 0;
		}
	}
	int k = -1;

	for(int l = 0; l < N; l++)
	{
		int brzeg = 0;
		double vb = 0;

		if(i(l, nx) == 0){
			brzeg = 1;
			vb = V1;
		}
		if(j(l, nx) == ny){
			brzeg = 1;
			vb = V2;
		}
		if(i(l, nx) == nx){
			brzeg = 1;
			vb = V3;
		}
		if(j(l, nx) == 0){
			brzeg = 1;
			vb = V4;
		}

		if(brzeg == 1){
			b[l] = vb;
		}
		else{
			if(useRho == 'y')
				b[l] = -rho(i(l, nx), j(l, nx), delta, xmax, ymax, xmax / 10);
			else
				b[l] = 0;
		}

		ia[l] = -1;
		//lewa skrajna przekatna
		if(l - nx - 1 >= 0 && brzeg == 0){
			k++;
			if(ia[l] < 0)
				ia[l] = k;
			double epsilon = i(l, nx) <= nx / 2 ? ep1 : ep2;
			a[k] = epsilon / pow(delta, 2);
			ja[k] = l - nx - 1;
		}
		//poddiagonala
		if(l - 1 >= 0 && brzeg == 0){
			k++;
			if(ia[l] < 0)
				ia[l] = k;
			double epsilon = i(l, nx) <= nx / 2 ? ep1 : ep2;
			a[k] = epsilon / pow(delta, 2);
			ja[k] = l - 1;
		}
		//diagonala
		k++;
		if(ia[l] < 0)
			ia[l] = k;
		if(brzeg == 0){
			double epsilon0 = i(l, nx) <= nx / 2 ? ep1 : ep2;
			double epsilon1 = i(l + 1, nx) <= nx / 2 ? ep1 : ep2;
			double epsilon2 = i(l + nx + 1, nx) <= ny / 2 ? ep1 : ep2;
			a[k] = -(2 * epsilon0 + epsilon1 + epsilon2) / pow(delta, 2);

		}
		else
			a[k] = 1;
		ja[k] = l;

		//nad diagonala
		if(l < N && brzeg == 0){
			k++;
			double epsilon = i(l + 1, nx) <= nx / 2 ? ep1 : ep2;
			a[k] = epsilon / pow(delta, 2);
			ja[k] = l + 1;
		}
		//prawa skrajna przekatna
		if(l < N - nx - 1 && brzeg == 0){
			k++;
			double epsilon = i(l + nx + 1, nx) <= nx / 2 ? ep1 : ep2;
			a[k] = epsilon / pow(delta, 2);
			ja[k] = l + nx + 1;
		}
	}
	int nz_num = k + 1;
	ia[N] = nz_num;

	pmgmres_ilu_cr(N, nz_num, ia, ja, a, V, b, 500, 500, 1e-8, 1e-8);
	if(writeMatrix == 'y'){
		fprintf(fp, "# l \t i_l \t j_l \t b[l]\n");
		for(int l = 0; l < N; l++){
			fprintf(fp, "%d \t\t%d \t\t%d \t\t%lf\n", l, i(l, nx), j(l, nx),b[l]);
		}
		fprintf(fp, "# k \t a[l]\n");
		for(int l = 0; l < 5*N; l++){
			fprintf(fp, "%d \t %lf\n", l,a[l]);
		}
		
	}

}

int main()
{
	FILE *fp;
	fp = fopen("matrixA_vectorB.dat", "w");
	metodaPoissona(0.1, 4, 4, 1, 1, 10, -10, 10, -10, 'n', fp, 'y');
	fclose(fp);

	return 0;
}