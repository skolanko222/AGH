#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <string>
class WaveSimulator {
private:
    constexpr static const int nx = 150;
	const int nt = 1000;
	const double delta = 0.1;
	const double delta_t = 0.05;
	const double xA = 7.5;
	const double sigma = 0.5;
	const double tMax = nt * delta_t;
	double b = 0.0; 
	double alpha = 0.0; 

	double u[nx];
	double v[nx];
	double a[nx];
	double u0[nx];
	double vp[nx];

public:
    WaveSimulator() = default;

    double aF(double x, double t) {
        return cos(50 * t / tMax) * (x==alpha ? 1 : 0);
    }

    void initialize() {
        for(int i = 0; i < nx; i++) {
            double x = i * delta;
			double temp = alpha == 1.0 ? 0.0 : exp(-(x - xA)*(x - xA) / (2 * sigma * sigma));
            u[i] = temp;
			u0[i] = temp;
            v[i] = 0.0;
        }
        for(int i = 1; i < nx - 1; i++) {
            a[i] = (u[i+1] - 2*u[i] + u[i-1]) / 
					(delta * delta) - b * (u[i] - u0[i]) / delta_t + alpha*aF(i*delta, 0);
        }
    }

    double calcEnergy() {
        double E = 0.0;
        double e1 = pow((u[1] - u[0]) / delta, 2);
        double e2 = pow((u[nx] - u[nx-1]) / delta, 2);
        E += delta / 4 * (e1 + e2);
        for(int i = 0; i < nx - 1; i++) {
            e1 = v[i] * v[i];
            e2 = pow((u[i+1] - u[i-1]) / (2*delta), 2);
            E += (delta / 2)*(e1 + e2);
        }
        return E;
    }

    void run(int size, double betaArr[], double alphaArr[]) {
        for (int i = 0; i < size; i++) {
            std::ostringstream stream;
			b = betaArr[i];
            alpha = alphaArr[i];
            stream << std::fixed << std::setprecision(1) << b;
            std::string b_str = stream.str();
            stream.str("");
            stream << std::fixed << std::setprecision(1) << alpha;
            std::string a_str = stream.str();
            stream.str("");
            printf("b = %f, alpha = %f\n", b, alpha);
            std::ofstream file1("data/E(t)_alpha_" + a_str + "_beta_" + b_str + ".txt");
            std::ofstream file2("data/map_alpha_" + a_str + "_beta_" + b_str + ".txt");
            initialize();
			if(!file1.is_open() || !file2.is_open()) {
				std::cout << "Error opening file" << std::endl;
				return;
			}
            for(double t = 0; t < tMax; t += delta_t) {
                 for(int i = 0; i < nx; i++) {
					vp[i] = v[i] + delta_t * a[i] / 2;
					}
					for(int i = 1; i < nx - 1; i++) {
						u0[i] = u[i];
					}
					for(int i = 0; i < nx ; i++) {
						u[i] = u[i] + delta_t * vp[i];
					}
					for(int i = 0; i < nx -1; i++) {
						a[i] = (u[i+1] - 2*u[i] + u[i-1]) / (delta * delta) 
								- b * (u[i] - u0[i]) / delta_t + alpha*aF(i*delta, t);
						v[i] = vp[i] + delta_t * a[i] / 2;
					}
					u[0] = 0;
					u[nx-1] = 0;
					v[0] = 0;
					v[nx-1] = 0;
					double E = calcEnergy();
					file2 << E << " ";
					for(int i = nx; i > 0; i--) {
						file1 << u[i] << " ";
					}
                file1 << "\n";
            }
            file1.close();
            file2.close();
        }
    }
};

int main() {
    WaveSimulator simulator;
    double betaArr[] = {0.0, 0.1, 1.0}; 
    double alphaArr[] = {0.0, 0.0, 0.0};
    simulator.run(3, betaArr, alphaArr);
    return 0;
}