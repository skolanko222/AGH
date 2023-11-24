#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include "mgmres.h"

double rho1(int i, int j, double Delta, double xmax, double ymax, double sigma)
{
	return exp(-pow((Delta * i - 0.25 * xmax) / sigma, 2) - pow((Delta * j - 0.5 * ymax) / sigma, 2));
}

double rho2(int i, int j, double Delta, double xmax, double ymax, double sigma)
{
	return -exp(-pow((Delta * i - 0.75 * xmax) / sigma, 2) - pow((Delta * j - 0.5 * ymax) / sigma, 2));
}

double rho(int i, int j, double Delta, double xmax, double ymax, double sigma)
{
	return rho1(i, j, Delta, xmax, ymax, sigma) + rho2(i, j, Delta, xmax, ymax, sigma);
}

int j(int l, int nx)
{
	return l / (nx + 1);
}

int i(int l, int nx)
{
	return l - j(l, nx) * (nx + 1);
}

double epsilon(int l, int nx, double epsilon1, double epsilon2)
{
	if (i(l, nx) <= nx / 2)
		return epsilon1;
	else
		return epsilon2;
}

void poisson(int nx, int ny, double Delta, double epsilon1, double epsilon2,
			 double v1, double v2, double v3, double v4, bool useFunctionRho, bool printMatrix, char filename[])
{
	int N = (nx + 1) * (ny + 1);
	double xmax = Delta * nx;
	double ymax = Delta * ny;
	double sigma = xmax / 10;
	
	double *a = malloc(sizeof *a * 5 * N);
	double b[N], V[N];
	int ja[5 * N], ia[N + 1];
	for (int i = 0; i < 5 * N; i++)
	{
		a[i] = 0;
		ja[i] = 0;
		if (i < N + 1)
		{
			ia[i] = -1;
		}
		if (i < N)
		{
			b[i] = 0;
			V[i] = 0;
		}
	}
	
	int k = -1;
	int edge;
	double vb;
	for (int l = 0; l < N; l++)
	{
		edge = 0;
		vb = 0;
		
		if (i(l, nx) == 0)
		{
			edge = 1;
			vb = v1;
		}
		if (j(l, nx) == nx)
		{
			edge = 1;
			vb = v2;
		}
		if (i(l, nx) == 0)
		{
			edge = 1;
			vb = v3;
		}
		if (j(l, nx) == ny)
		{
			edge = 1;
			vb = v4;
		}
		
		if (edge == 1)
			b[l] = vb;
		else if (useFunctionRho)
			b[l] = -rho(i(l, nx), j(l, nx), Delta, xmax, ymax, sigma);
		else
			b[l] = 0;
		
		ia[l] = -1;
		
		if (l - nx - 1 >= 0 && edge == 0)
		{
			k++;
			if (ia[l] < 0)
				ia[l] = k;
			a[k] = epsilon(l, nx, epsilon1, epsilon2) / (Delta * Delta);
			ja[k] = l - nx - 1;
		}
		
		if (l - 1 >= 0 && edge == 0)
		{
			k++;
			if (ia[l] < 0)
				ia[l] = k;
			a[k] = epsilon(l, nx, epsilon1, epsilon2) / (Delta * Delta);
			ja[k] = l - 1;
		}
		
		k++;
		if (ia[l] < 0)
			ia[l] = k;
		if (edge == 0)
			a[k] = -(2 * epsilon(l, nx, epsilon1, epsilon2) + epsilon(l + 1, nx, epsilon1, epsilon2) +
					 epsilon(l + nx + 1, nx, epsilon1, epsilon2)) / (Delta * Delta);
		else
			a[k] = 1;
		ja[k] = l;
		
		if (l < N && edge == 0)
		{
			k++;
			a[k] = epsilon(l + 1, nx, epsilon1, epsilon2) / (Delta * Delta);
			ja[k] = l + 1;
		}
		
		if (l < N - nx - 1 && edge == 0)
		{
			k++;
			a[k] = epsilon(l + nx + 1, nx, epsilon1, epsilon2) / (Delta * Delta);
			ja[k] = l + nx + 1;
		}
	}
	int nz_num = k + 1;
	ia[N] = nz_num;
	
	pmgmres_ilu_cr(N, nz_num, ia, ja, a, V, b, 500, 500, 1e-8, 1e-8);
	
	if (printMatrix)
	{
		FILE *fA = fopen("matrix_A.txt", "w");
		for (int l = 0; l < 5 * N; l++)
		{
			fprintf(fA, "%d %f\n", l, a[l]);
		}
		fclose(fA);
		FILE *fb = fopen("vector_b.txt", "w");
		for (int l = 0; l < N; l++)
		{
			fprintf(fb, "%d %d %d %f\n", l, i(l, nx), j(l, nx), b[l]);
		}
		fclose(fb);
	}
	else
	{
		FILE *f = fopen(filename, "w");
		double limit = 0;
		for (int l = 0; l < N; l++)
		{
			if (Delta * j(l, nx) > limit)
				fprintf(f, "\n");
			fprintf(f, "%f %f %f\n", Delta * j(l, nx), Delta * i(l, nx), V[l]);
			limit = Delta * j(l, nx);
		}
		fclose(f);
	}
	
	free(a);
}

int main()
{
	poisson(4, 4, 0.1, 1, 1, 10, -10, 10, -10, false, true, "");
	// poisson(50, 50, 0.1, 1, 1, 10, -10, 10, -10, false, false, "5a.txt");
	// poisson(100, 100, 0.1, 1, 1, 10, -10, 10, -10, false, false, "5b.txt");
	// poisson(200, 200, 0.1, 1, 1, 10, -10, 10, -10, false, false, "5c.txt");
	// poisson(100, 100, 0.1, 1, 1, 0, 0, 0, 0, true, false, "6a.txt");
	// poisson(100, 100, 0.1, 1, 2, 0, 0, 0, 0, true, false, "6b.txt");
	// poisson(100, 100, 0.1, 1, 10, 0, 0, 0, 0, true, false, "6c.txt");
}