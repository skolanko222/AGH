#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
class Dane{
	public:
		constexpr static const double d = 0.2;
		static const int nx = 128;
		static const int ny = 128;
		constexpr static const double x_max = d*nx;
		constexpr static const double y_max = d*ny;
		constexpr static const double TOL = 1e-8;

		static double vb1(int j){
    		return std::sin(M_PI * d * j / y_max);
		}

		static double vb2(int i){
			return -std::sin(2.0 * M_PI * d * i / x_max);
		}

		static double vb3(int j){
			return std::sin(M_PI * d * j / y_max);
		}

		static double vb4(int i){
			return std::sin(2.0 * M_PI * d * i / x_max);
		}
	 
	
};
class Relaxation{
	public:
		double V[Dane::nx + 1][Dane::ny + 1];
		int k;
		std::vector<double> sArr;
		Relaxation(int n) : k(n){
			for(int j = 0; j <= Dane::ny; ++j){
				for(int i = 0; i <= Dane::nx; ++i)
					V[i][j] = 0.0;
			}
			border();
		}
		void relax(){
			std::cout << "k = " << k << std::endl;
			int it = 0;
			double sPrev = Dane::TOL;
        	double sNew;
			while(true){
				for(int j = k; j < Dane::ny; j += k){ //dodac -k
					for(int i = k; i < Dane::nx; i += k) {
						V[i][j] = 0.25*(V[i+k][j] + V[i-k][j] + V[i][j+k] + V[i][j-k]);
					}
				}
				sNew = funS(k);
				if(std::abs((sNew - sPrev) / sPrev) < Dane::TOL){
					break;
				}
				sArr.push_back(sNew);
				sPrev = sNew;
				it++;
			}
			std::cout << "it = " << it << std::endl;
			
		}
		void saveMatrixToFile(std::fstream &file){
			for(int j = 0; j < Dane::ny; j += k){ //dodac -k
					for(int i = 0; i < Dane::nx; i += k) {
						file << V[i][j] << " ";
				}
				file << std::endl;
			}
		}
		void dense(){
			if(k!=1){
            for(int j = 0; j < Dane::ny; j += k) {
                for(int i = 0; i < Dane::nx; i += k){
                    V[i+k/2][j+k/2] = 0.25 * (V[i][j] + V[i+k][j] + V[i][j+k] + V[i+k][j+k]);
                    V[i+k][j+k/2] = 0.5 * (V[i+k][j] + V[i+k][j+k]);
                    V[i+k/2][j+k] = 0.5 * (V[i][j+k] + V[i+k][j+k]);
                    V[i+k/2][j] = 0.5 * (V[i][j] + V[i+k][j]);
                    V[i][j+k/2] = 0.5 * (V[i][j] + V[i][j+k]);
                }
           	 }
        	}
			border();
		}
		void saveSarrToFile(std::fstream &file){
			for(int i = 0; i < sArr.size(); ++i){
				file << sArr[i] << ' ';
			}
			file << std::endl;
			sArr.clear();
		}
		
	protected:
		double funS(int k){
			double S = 0.;
			double d = Dane::d;
			for(int j = 0; j < Dane::ny-2; j+=k){
				for(int i=0; i < Dane::nx-2; i+=k){
					S += 0.5*k*k*d*d*( pow(((V[i+k][j] - V[i][j] + V[i+k][j+k] - V[i][j+k]) / (2.0 * k * d)),2) +
                               pow(((V[i][j+k] - V[i][j] + V[i+k][j+k] - V[i+k][j]) / (2.0 * k * d)),2) );
				}
			}
			return S;
		}
		void border(){
			for (int i=0; i<=Dane::nx; ++i) {
				V[i][Dane::ny] = Dane::vb2(i);
				V[i][0] = Dane::vb4(i);
			}

			for (int j = 0; j <= Dane::ny; ++j) {
				V[0][j] = Dane::vb1(j);
				V[Dane::nx][j] = Dane::vb3(j);
			}
		}
};

int main(){

	int kArr[] = {16, 8, 4, 2, 1};
	std::fstream file;
	std::fstream file2;
	file2.open("plot/dataS.txt", std::ios::out);
	Relaxation relax(1);
	for(int k : kArr){
		file.open("plot/data" + std::to_string(k) + ".txt", std::ios::out);
		relax.k = k;
		relax.relax();
		relax.saveMatrixToFile(file);
		relax.saveSarrToFile(file2);
		relax.dense();
		file.close();
	}

	return 0;
}