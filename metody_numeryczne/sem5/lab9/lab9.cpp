#include <gsl/gsl_math.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_blas.h>
#include <iostream>
#include <fstream>
#include <string>

class Solver{
	private:
		const int nx = 40;
		const int ny = 40;
		const int N = (nx+1)*(ny+1);
		const double d = 1.;
		const double dt = 1.;
		const double T_a = 40;
		const double T_b = 0;
		const double T_c = 30;
		const double T_d = 0;
		const double k_b = 0.1;
		const double k_d = 0.6;
		const int ITER_MAX = 2000; 
		int signum = 1;

		gsl_matrix *A;
		gsl_matrix *B;
		gsl_vector *c;
		gsl_vector *t;
		gsl_permutation *perm;

		int l_fun(int i, int j){
			return i + j*(nx+1);
		}

		void save_vector(gsl_vector *v, std::string filename){
			std::fstream file;
			file.open(filename, std::ios::out);
			for(int i = 1; i < N; i++){
				file << gsl_vector_get(v, i) << " ";
				if(i % (nx+1) == 0 && i != 0){
					file << std::endl;
				}
			}
		}
	public:

		Solver(){
			A = gsl_matrix_calloc(N,N);
			B = gsl_matrix_calloc(N,N);
			c = gsl_vector_calloc(N);
			t = gsl_vector_calloc(N);
			perm = gsl_permutation_calloc(N);

			for (int i = 0; i <= nx; ++i) {
				for (int j = 0; j <= ny; ++j) {
					int l = l_fun(i, j);
					double val;

					if ((i == 0 || i == nx) && (j >= 0 && j <= ny)) { //21
						gsl_matrix_set(A, l, l, 1.0);
						gsl_matrix_set(B, l, l, 1.0);
						gsl_vector_set(c, l, 0.0);
					} else if ((i >= 1 && i <= nx) && j == ny) {//30
						gsl_matrix_set(A, l, l - nx - 1, -1.0 / (k_b * d));
						gsl_matrix_set(A, l, l, 1.0 + 1.0 / (k_b * d));
						gsl_vector_set(c, l, T_b);
						for (int k = 0; k < N; ++k) {
							gsl_matrix_set(B, l, k, 0.0);
						}
					} else if ((i >= 1 && i <= nx) && j == 0) { //40
						gsl_matrix_set(A, l, l, 1.0 + 1.0 / (k_d * d));
						gsl_matrix_set(A, l, l + nx + 1, -1.0 / (k_d * d));
						gsl_vector_set(c, l, T_d);
						for (int lj = 0; lj < N; ++lj) {
							gsl_matrix_set(B, l, lj, 0.0);
						}
					} else { // 15
						val = dt / (2.0 * d * d);
						gsl_matrix_set(A, l, l, -2.0 * dt / (d * d) - 1.0);
						gsl_matrix_set(B, l, l, 2.0 * dt / (d * d) - 1.0);
						gsl_matrix_set(A, l, l - nx - 1, val);
						gsl_matrix_set(A, l, l + nx + 1, val);
						gsl_matrix_set(A, l, l - 1, val);
						gsl_matrix_set(A, l, l + 1, val);
						gsl_matrix_set(B, l, l - nx - 1, -val);
						gsl_matrix_set(B, l, l + nx + 1, -val);
						gsl_matrix_set(B, l, l - 1, -val);
						gsl_matrix_set(B, l, l + 1, -val);
					}
				}
			}
			for(int i = 0; i <= nx; i++){
				for(int j = 0; j <= ny; j++){
					int l = l_fun(i,j);
					if(i == 0 && (j > 0 && j <= ny)){
						gsl_vector_set(t, l, T_a);
					}
					else if(i == nx && (j > 0 && j <= ny)){
						gsl_vector_set(t, l, T_c);
					}
					else{
						gsl_vector_set(t, l, 0.0);
					}
				}
			}
		}					
		void solve(){
			//CN algorithm
			gsl_linalg_LU_decomp(A, perm, (&signum));
			gsl_vector *d = gsl_vector_calloc(N);
			gsl_vector *t_old = gsl_vector_calloc(N);
			gsl_vector *temp = gsl_vector_calloc(N);

			//d = B*t + c
			for(int it = 0; it <= ITER_MAX; it++){
				gsl_vector_memcpy(t_old, t);
				gsl_blas_dgemv(CblasNoTrans, 1.0, B, t, 0.0, d); //d = B*t
				gsl_vector_add(d, c);
				gsl_linalg_LU_solve(A, perm, d, t);
				if(it == 100 || it == 200 || it == 500 || it == 1000 || it == 2000){
					std::string filename = "data/data_" + std::to_string(it) + ".dat";
					save_vector(t, filename);
					std::string filename2 = "data/data_lap_" + std::to_string(it) + ".dat";
					
					//(t - t_old)/dt
					gsl_vector_memcpy(temp, t);
					gsl_vector_sub(temp, t_old);
					gsl_vector_scale(temp, 1.0/dt);
					save_vector(temp, filename2);
				}
			}
			gsl_vector_free(d);
			gsl_vector_free(t_old);
			gsl_vector_free(temp);
		}
		~Solver(){
			gsl_matrix_free(A);
			gsl_matrix_free(B);
			gsl_vector_free(c);
			gsl_vector_free(t);
			gsl_permutation_free(perm);
		}
};

int main(){
	Solver s;
	s.solve();

	return 0;
}