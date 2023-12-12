#include <iostream>
#include <fstream>
#include <cmath>

class Relaxation{
	private:
		constexpr static const double d=0.01;
		constexpr static const double rho=1.0;
		constexpr static const double mi=1.0;
		constexpr static const int nx=200;
		constexpr static const int ny=90;
		constexpr static const int i1=50;
		constexpr static const int j1=55;
		constexpr static const int j2=j1+2;
		constexpr static const int it_max=20000;
		double zeta[nx+1][ny+1];
		double psi[nx+1][ny+1];
		double u[nx+1][ny+1];
		double v[nx+1][ny+1];


	public:
		static double x(int i){
			return i*d;
		};
		static double y(int j){
			return j*d;
		};
		static double q_wy(double q_we){
			return q_we * (std::pow(y(ny), 3) - std::pow(y(j1), 3) - 3.*y(j1)*std::pow(y(ny), 2)+3.0*std::pow(y(j1), 2)*y(ny))/std::pow(y(ny),3);
		};
		static bool is_edge(int i, int j){
			// A 1
			if(i == 0 && j >= j1 && j <= ny)
				return true;
			// C 1
			if(i == nx && j >= 0 && j <= ny)
				return true;
			// D 1
			if(j == 0 && i >= i1 && i <= nx) 
				return true;
			// E 1
			if(i == i1 && j >= 0 && j <= j1)
				return true;
			// B
			if(i == 0 && j >= 0 && j <= i1)
			// if(j == ny && i >= 0 && i <= nx)
				return true;
			// F 1
			if(i >= 0 && i <= i1 && j == j1)
				return true;

			return false;
		}
   
		void wb_psi(int q){
			for(int j=j1; j<=ny; j++)
				psi[0][j] = q/(2.0*mi) * (std::pow(y(j), 3)/3. - std::pow(y(j), 2)*(y(j1) + y(ny))/2. + y(j)*y(j1)*y(ny));
			for(int j=0; j<=ny; j++)
				psi[nx][j] = q_wy(q)/(2.0*mi) * (std::pow(y(j), 3)/3. - std::pow(y(j), 2)*y(ny)/2.) + (q*std::pow(y(j1), 2)*(-y(j1) + 3.*y(ny))) / (12.*mi);
			for(int i=1; i<nx; i++)
				psi[i][ny] = psi[0][ny];
			for(int i=i1; i<nx; i++)
				psi[i][0] = psi[0][j1];
			for(int j=1; j<=j1; j++)
				psi[i1][j] = psi[0][j1];
			for(int i=1; i<=i1; i++)
				psi[i][j1] = psi[0][j1];

		};

		void wb_zeta(int q){
			for(int j=j1; j<=ny; j++)
				zeta[0][j] = q/(2.0*mi) * (2.0*y(j) - y(j1) - y(ny));
			for(int j=0; j<=ny; j++)
				zeta[nx][j] = q_wy(q)/(2.0*mi) * (2.0*y(j) - y(ny));
			for(int i=1; i<nx; i++)
				zeta[i][ny] = 2.0*(psi[i][ny-1] - psi[i][ny])/std::pow(d, 2);
			for(int i=i1+1; i<nx; i++)
				zeta[i][0] = 2.0*(psi[i][1] - psi[i][0])/std::pow(d, 2);
			for(int j=1; j<=j1; j++)
				zeta[i1][j] = 2.0*(psi[i1+1][j] - psi[i1][j])/std::pow(d, 2);
			for(int i=1; i<=i1; i++)
				zeta[i][j1] = 2.0*(psi[i][j1+1] - psi[i][j1])/std::pow(d, 2);
        	zeta[i1][j1] = (zeta[i1-1][j1] + zeta[i1][j1-1]) / 2.0;

		};

		void relax(std::fstream &file_u, std::fstream &file_v, std::fstream &file_psi, std::fstream &file_zeta, int q){
			for(int j = 0; j <= ny; j++){
				for(int i = 0; i <= nx; i++){
						u[i][j] = 0.0;
						v[i][j] = 0.0;
						psi[i][j] = 0.0;
						zeta[i][j] = 0.0;
				}
			}
			wb_psi(q);  

			double omega, gamma;

			for(int it = 0; it <= it_max; it++){
				if(it < 2000)
					omega = 0.0;
				else
					omega = 1.0;
				for(int j = 1; j < ny; j++){
					for(int i = 1; i < nx; i++){
						if(!is_edge(i, j)){
                    		psi[i][j] = (psi[i+1][j] + psi[i-1][j] + psi[i][j+1] + psi[i][j-1] - pow(d,2) * zeta[i][j]) / 4.0;

							if(omega > 0.1)
								zeta[i][j] = (zeta[i+1][j] + zeta[i-1][j] + zeta[i][j+1] + zeta[i][j-1]) / 4.0 - omega * rho / (16.0 * mi) * ((psi[i][j+1] - psi[i][j-1]) * (zeta[i+1][j] - zeta[i-1][j]) - (psi[i+1][j] - psi[i-1][j]) * (zeta[i][j+1] - zeta[i][j-1]));
							else
								zeta[i][j] = (zeta[i+1][j] + zeta[i-1][j] + zeta[i][j+1] + zeta[i][j-1]) / 4.0;
							
							u[i][j] = (psi[i][j+1] - psi[i][j-1]) / (2.0 * d);

							v[i][j] = -(psi[i+1][j] - psi[i-1][j]) / (2.0 * d);
						}
					}
				}
				wb_zeta(q);

				gamma = 0.0;


				for(int i = 1; i < nx; i++){
					gamma += psi[i+1][j2] + psi[i-1][j2] + psi[i][j2+1] + psi[i][j2-1] - 4.0 * psi[i][j2] - pow(d,2) * zeta[i][j2];
				}
			}
			
			for(int i=0; i<i1; ++i){
				psi[i][0] =  std::nan("");
				zeta[i][0] =  std::nan("");
				u[i][0] =  std::nan("");
				v[i][0] =  std::nan("");
			}

			for(int j=0; j<j1; ++j){
				psi[0][j] =  std::nan("");
				zeta[0][j] =  std::nan("");
				u[0][j] =  std::nan("");
				v[0][j] =  std::nan("");
			}
			
			for(int i = 0; i <= ny; i++){
				for(int j = 0; j <= nx; j++){
					file_u << u[j][i] << " ";
					file_v << v[j][i] <<  " ";
					file_psi << psi[j][i] <<  " ";
					file_zeta << zeta[j][i] << " ";
				}
				file_u << std::endl;
				file_v << std::endl;
				file_psi << std::endl;
				file_zeta << std::endl;

			}
		}
	
};
int main(void){

	std::fstream file[12];

		file[0].open("plots/u_-4000.txt", std::ios::out);
		file[1].open("plots/v_-4000.txt", std::ios::out);
		file[2].open("plots/psi_-4000.txt", std::ios::out);
		file[3].open("plots/zeta_-4000.txt", std::ios::out);

		file[4].open("plots/u_-1000.txt", std::ios::out);
		file[5].open("plots/v_-1000.txt", std::ios::out);
		file[6].open("plots/psi_-1000.txt", std::ios::out);
		file[7].open("plots/zeta_-1000.txt", std::ios::out);
		
		file[8].open("plots/u_4000.txt", std::ios::out);
		file[9].open("plots/v_4000.txt", std::ios::out);
		file[10].open("plots/psi_4000.txt", std::ios::out);
		file[11].open("plots/zeta_4000.txt", std::ios::out);

		Relaxation zad1;
		zad1.relax(file[0], file[1], file[2], file[3], -4000);
		zad1.relax(file[4], file[5], file[6], file[7], -1000);
		zad1.relax(file[8], file[9], file[10], file[11], 4000);

	return 0;
}
