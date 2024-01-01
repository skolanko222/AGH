#include <iostream>
#include <fstream>
#include <cmath>
#include <array>
#include <iomanip>
#include <sstream>

const int nx = 400;
const int ny = 90;
const int i_one = 200;
const int i_two = 210;
const int j_one = 50;
const double d = 0.01;
const double sigma = 10.0 * d;
const double xa = 0.45;
const double ya = 0.45;
const int it_max = 10000;

class Grid {
public:
    Grid() {
        create_grids();
    }

    void create_grids() {
        f_grid_x << std::fixed;
        f_grid_y << std::fixed;

        for (int i = 0; i <= nx; i++) {
            f_grid_x << x(i) << std::endl;
        }

        for (int j = 0; j <= ny; j++) {
            f_grid_y << y(j) <<  std::endl;
        }

    }

    double x(int i) {
        return d * i;
    }

    double y(int j) {
        return d * j;
    }

private:
    std::fstream f_grid_x = std::fstream("data/grid_x.dat", std::ios::out);
    std::fstream f_grid_y = std::fstream("data/grid_y.dat", std::ios::out);
};

class Solver {
public:
    Solver() {
        std::ifstream file("data/psi.dat");
        std::string line;
        double psi[nx + 1][ny + 1];

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            size_t i, j;
            double temp_psi;
            if (iss >> i >> j >> temp_psi) {
                psi[i][j] = temp_psi;
            }
        }
        file.close();

        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                vx[i][j] = 0.0;
                vy[i][j] = 0.0;
            }
        }

        for (int i = 1; i < nx; i++) {
            for (int j = 1; j < ny; j++) {
                vx[i][j] = (psi[i][j + 1] - psi[i][j - 1]) / (2.0 * d);
                vy[i][j] = -(psi[i + 1][j] - psi[i - 1][j]) / (2.0 * d);
            }
        }

        for (int i = i_one; i <= i_two; i++) {
            for (int j = 0; j <= j_one; j++) {
                vx[i][j] = 0.0;
                vy[i][j] = 0.0;
            }
        }

        for (int i = 1; i < nx; i++) {
            vx[i][0] = 0.0;
            vy[i][ny] = 0.0;
        }

        for (int j = 0; j <= ny; j++
        ) {
            vx[0][j] = vx[1][j];
            vx[nx][j] = vx[nx - 1][j];
        }

		// save v_x and v_y
		f_v_x << std::fixed;
		f_v_y << std::fixed;
		for(int j=0; j<=ny; j++
        ){
			for(int i=0; i<=nx; i++){
				f_v_x << vx[i][j] << " ";
				f_v_y << vy[i][j] << " ";
			}
			f_v_x << std::endl;
			f_v_y << std::endl;
		}

		double v_max = 0.0;
		double v_magnitude;
        
		for (int i=0; i<=nx; i++) {
			for (int j=0; j<=ny; j++
            ) {
				v_magnitude = std::sqrt(pow(vx[i][j],2) + pow(vy[i][j],2));
				if (v_magnitude > v_max) {
					v_max = v_magnitude;
				}
			}
		}

		dt = d / (4.0 * v_max);
		for (int it=1; it<it_max; it++) {
			f_grid_t << t(it, dt) << std::endl;
		}
    }

    void solve(double dd , bool flag) {
        for (int j = 0; j <= ny; j++
        ) {
            for (int i = 0; i <= nx; i++) {
                u0[i][j] = 0.0;
                u1[i][j] = 0.0;
            }
        }

        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++
            ) {
                u0[i][j] = u(x(i), y(j));
            }
        }

        for (int it = 1; it < it_max; it++) {
			if(it%100 == 0)
				std::cout << "ITER: " << it << " " << "d: " << dd <<std::endl; 

            for (int i = 0; i <= nx; i++) {
                for (int j = 0; j <= ny; j++
                ) {
                    u1[i][j] = u0[i][j];
                }
            }

            for (int kit = 1; kit <= 20; ++kit) {
                for (int i = 0; i <= nx; i++) {
                    for (int j = 1; j < ny; j++
                    ) {
                        if (i >= i_one && i <= i_two && j >= 0 && j <= j_one) {
                            continue;
                        } else if (i == 0) {
                            u1[i][j] = (u0[i][j] - dt * vx[i][j] / 2.0 * (((u0[i + 1][j] - u0[nx][j]) / (2.0 * d)) +
                                                                         ((u1[i + 1][j] - u1[nx][j]) / (2.0 * d))) -
                                        dt * vy[i][j] / 2.0 * (((u0[i][j + 1] - u0[i][j - 1]) / (2.0 * d)) +
                                                                ((u1[i][j + 1] - u1[i][j - 1]) / (2.0 * d))) +
                                        dt * dd / 2.0
                                        * ((u0[i + 1][j] + u0[nx][j] + u0[i][j + 1] + u0[i][j - 1] - 4.0 * u0[i][j]) /
                                           (pow(d, 2)) +
                                           ((u1[i + 1][j] + u1[nx][j] + u1[i][j + 1] + u1[i][j - 1]) / (pow(d, 2))))) /
                                       (1.0 + (2.0 * dd * dt) / (pow(d, 2)));
                        } else if (i == nx) {
                            u1[i][j] = (u0[i][j] - dt * vx[i][j] / 2.0 * (((u0[0][j] - u0[i - 1][j]) / (2.0 * d)) +
                                                                         ((u1[0][j] - u1[i - 1][j]) / (2.0 * d))) -
                                        dt * vy[i][j] / 2.0 * (((u0[i][j + 1] - u0[i][j - 1]) / (2.0 * d)) +
                                                                ((u1[i][j + 1] - u1[i][j - 1]) / (2.0 * d))) +
                                        dt * dd / 2.0
                                        * ((u0[0][j] + u0[i - 1][j] + u0[i][j + 1] + u0[i][j - 1] - 4.0 * u0[i][j]) /
                                           (pow(d, 2)) +
                                           ((u1[0][j] + u1[i - 1][j] + u1[i][j + 1] + u1[i][j - 1]) / (pow(d, 2))))) /
                                       (1.0 + (2.0 * dd * dt) / (pow(d, 2)));
                        } else {
                            u1[i][j] = (u0[i][j] - dt * vx[i][j] / 2.0 * (((u0[i + 1][j] - u0[i - 1][j]) / (2.0 * d)) +
                                                                         ((u1[i + 1][j] - u1[i - 1][j]) / (2.0 * d))) -
                                        dt * vy[i][j] / 2.0 * (((u0[i][j + 1] - u0[i][j - 1]) / (2.0 * d)) +
                                                                ((u1[i][j + 1] - u1[i][j - 1]) / (2.0 * d))) +
                                        dt * dd / 2.0
                                        * ((u0[i + 1][j] + u0[i - 1][j] + u0[i][j + 1] + u0[i][j - 1] - 4.0 * u0[i][j]) /
                                           (pow(d, 2)) +
                                           ((u1[i + 1][j] + u1[i - 1][j] + u1[i][j + 1] + u1[i][j - 1]) / (pow(d, 2))))) /
                                       (1.0 + (2.0 * dd * dt) / (pow(d, 2)));
                        }
                    }
                }
            }

            for (int i = 0; i <= nx; i++) {
                for (int j = 0; j <= ny; j++
                ) {
                    u0[i][j] = u1[i][j];
                }
            }

            double c_tmp = 0.0;
            for (int i = 0; i <= nx; i++) {
                for (int j = 0; j <= ny; j++
                ) {
                    c_tmp += u0[i][j] * pow(d, 2);
                }
            }
			if(flag)
           	 f_c1 << c_tmp << std::endl;
			else
			 f_c2 << c_tmp << std::endl;

            double xsr_tmp = 0.0;
            for (int i = 0; i <= nx; i++) {
                for (int j = 0; j <= ny; j++
                ) {
                    xsr_tmp += u0[i][j] * x(i) * pow(d, 2);
                }
            }
			if(flag)
				f_xsr1 << xsr_tmp << std::endl;
			else
            	f_xsr2 << xsr_tmp << std::endl;
            std::fstream *f1 ;
            std::fstream *f2 ;
            std::fstream *f3;
            std::fstream *f4 ;
            std::fstream *f5 ;

            if(flag){
                f1 = &f_u_1;
                f2 = &f_u_2;
                f3 = &f_u_3;
                f4 = &f_u_4;
                f5 = &f_u_5;
            }
            else{
                f1 = &f_u_6;
                f2 = &f_u_7;
                f3 = &f_u_8;
                f4 = &f_u_9;
                f5 = &f_u_10;
            }
            if (it == it_max / 5.0) {
                for (int j = 0; j <= ny; j++
                ) {
                    for (int i = 0; i <= nx; i++) {
                       *f1 << u0[i][j] << " ";
                    }
                    *f1 << std::endl;
                }
            }
            if (it == 2.0 * it_max / 5.0) {
                for (int j = 0; j <= ny; j++
                ) {
                    for (int i = 0; i <= nx; i++) {
                       *f2 << u0[i][j] << " ";
                    }
                    *f2 << std::endl;
                }
            }
            if (it == 3.0 * it_max / 5.0) {
                for (int j = 0; j <= ny; j++
                ) {
                    for (int i = 0; i <= nx; i++) {
                        *f3 << u0[i][j] << " ";
                    }
                    *f3 << std::endl;
                }
            }
            if (it == 4.0 * it_max / 5.0) {
                for (int j = 0; j <= ny; j++
                ) {
                    for (int i = 0; i <= nx; i++) {
                        *f4 << u0[i][j] << " ";
                    }
                    *f4 << std::endl;
                }
            }
            if (it == it_max - 1) {
                for (int j = 0; j <= ny; j++
                ) {
                    for (int i = 0; i <= nx; i++) {
                        *f5 << u0[i][j] << " ";
                    }
                    *f5 << std::endl;
                }
            }
        }
    }
	~Solver(){
		f_c1.close();
		f_xsr1.close();
		f_c2.close();
		f_xsr2.close();
		f_u_1.close();
		f_u_2.close();
		f_u_3.close();
		f_u_4.close();
		f_u_5.close();
		f_u_6.close();
		f_u_7.close();
		f_u_8.close();
		f_u_9.close();
		f_u_10.close();
		f_grid_t.close();
		f_v_x.close();
		f_v_y.close();

	}
private:
    std::fstream f_c1 = std::fstream("data/c0.dat", std::ios::out);
    std::fstream f_xsr1 = std::fstream("data/xsr0.dat", std::ios::out);
	std::fstream f_c2 = std::fstream("data/c1.dat", std::ios::out);
    std::fstream f_xsr2 = std::fstream("data/xsr1.dat", std::ios::out);
    std::fstream f_u_1 = std::fstream("data/u_1_d=0.dat", std::ios::out);
    std::fstream f_u_2 = std::fstream("data/u_2_d=0.dat", std::ios::out);
    std::fstream f_u_3 = std::fstream("data/u_3_d=0.dat", std::ios::out);
    std::fstream f_u_4 = std::fstream("data/u_4_d=0.dat", std::ios::out);
    std::fstream f_u_5 = std::fstream("data/u_5_d=0.dat", std::ios::out);
	std::fstream f_u_6 = std::fstream("data/u_1_d=0.1.dat", std::ios::out);
	std::fstream f_u_7 = std::fstream("data/u_2_d=0.1.dat", std::ios::out);
	std::fstream f_u_8 = std::fstream("data/u_3_d=0.1.dat", std::ios::out);
	std::fstream f_u_9 = std::fstream("data/u_4_d=0.1.dat", std::ios::out);
	std::fstream f_u_10 = std::fstream("data/u_5_d=0.1.dat", std::ios::out);
	std::fstream f_grid_t = std::fstream("data/grid_t.dat", std::ios::out);
	std::fstream f_v_x = std::fstream("data/v_x.dat", std::ios::out);
	std::fstream f_v_y = std::fstream("data/v_y.dat", std::ios::out);



    double vx[nx + 1][ny + 1];
    double vy[nx + 1][ny + 1];
	double u0[nx + 1][ny + 1];
	double u1[nx + 1][ny + 1];

	double dt;

    double x(int i) {
        return d * i;
    }

    double y(int j) {
        return d * j;
    }

    double u(double x, double y) {
        return std::exp(-(pow((x - xa), 2) + pow((y - ya), 2)) / (2.0 * pow(sigma, 2))) / (2.0 * M_PI * pow(sigma, 2));
    }

	double t(int k, double dt){
    	return dt*k;	
	}
};

int main() {
    Grid grid;
	grid.create_grids();
    Solver solver1;
    solver1.solve(0.,true);
    solver1.solve(0.1,false);
    return 0;
}