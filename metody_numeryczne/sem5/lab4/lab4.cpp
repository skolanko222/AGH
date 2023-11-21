#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
class Dane{
	public:
		constexpr static double epsilon = 1;
		constexpr static double TOL = 10e-8;
		constexpr static const double dt = 0.1;
		static const int nx = 150;
		static const int ny = 100;
		constexpr static const double V1 = 10;
		constexpr static const double V2 = 0;
		constexpr static const double xmax = dt*nx;
		constexpr static const double ymax = dt*ny;

	static double rho(double x, double y){
		double sigma_x = 0.1*xmax;
    	double sigma_y = 0.1*ymax;
		double rho1 = exp(-1 * pow(((x - 0.35*xmax) / sigma_x),2) - pow(((y - 0.5*ymax) / sigma_y),2));
		double rho2 = -1*exp(-1 * pow(((x - 0.65*xmax) / sigma_x),2) - pow(((y - 0.5*ymax) / sigma_y),2));
		return rho1 + rho2;
	} 
	
};
class Relaxation{
	public:
		double V1[Dane::nx+10][Dane::ny+1];
		double V2[Dane::nx+10][Dane::ny+1];

		double rho[Dane::nx+10][Dane::ny+10];

		double sMatrix[Dane::nx+1][Dane::ny+1];

		std::vector<int> iterVec;
		std::vector<double> sVec;

		Relaxation(){
			for(int j=0; j<Dane::ny+1; j++){
				for(int i=0; i<Dane::nx+1; i++){
				V2[i][j] = 0.0;
			}
			}
			double V_old[150+1][100+1];
			for(int j=0; j<Dane::ny+1; j++){
				for(int i=0; i<Dane::nx+1; i++){
					V1[i][j] = 0.0;
				}
			}
			for(int i=0; i<=Dane::nx; i++){
				V2[i][0] = 10.0;
				V1[i][0] = 10.0;
			}
		}
		void writeSMatrix(std::fstream &file){
			for(int j = 0; j < Dane::ny; j++){
				for(int i = 0; i < Dane::nx; i++){
					sMatrix[i][j] = (V2[i + 1][j] - 2.0 * V2[i][j] + V2[i - 1][j]) / (Dane::dt * Dane::dt)
                    + (V2[i][j + 1] - 2.0 * V2[i][j] + V2[i][j - 1]) / (Dane::dt * Dane::dt)
                    + rho[i][j] / Dane::epsilon;
					file << sMatrix[i][j] << " ";
				}
				file << "\n";
			}
		}
		void writeS(std::fstream &file){
			for(int i = 0; i < iterVec.size(); i++){
				file << iterVec[i] << " ";
			}
			file << '\n';
			for(int i = 0; i < iterVec.size(); i++){
				file << sVec[i] << " ";
			}
			file << '\n';
		}
		void writeV2(std::fstream &file){
			for(int j = 0; j < Dane::ny; j++){
				for(int i = 0; i < Dane::nx; i++){
					file << V2[i][j] << " ";
				}
				file << "\n";
			}
		}
	protected:
		double funS(){
			double S = 0.;
			double d = Dane::dt;
			for(int j = 0; j < Dane::ny-2; j++){
				for(int i=0; i < Dane::nx-2; i++){
					S += d*d*(std::pow((V1[i+1][j] - V1[i][j])/d, 2)/2. + std::pow((V1[i][j+1] - V1[i][j])/d, 2)/2. - rho[i][j]*V1[i][j]);
				}
			}
			return S;
		}
};
class GlobalRelaxation : public Relaxation{
	public:
		void relax(double omega){
			double sOld = 0.0;
			double sNew = 0.0;
			int i = 0;
			std::cout << "Global, omega: " << omega << std::endl;
			while(true){
				for(int i = 1; i < Dane::nx ; i++){
					for(int j = 1; j < Dane::ny; j++){
						V2[i][j] = 0.25*(V1[i+1][j] + V1[i-1][j] + V1[i][j+1] + V1[i][j-1] + pow(Dane::dt,2)/Dane::epsilon*rho[i][j]);
					}
				}
				for(int j = 1; j < Dane::ny; j++){
					V2[0][j] = V2[1][j];
					V2[Dane::nx][j] = V2[Dane::nx - 1][j];
				}
				for(int i = 0; i <= Dane::nx ; i++){
					for(int j = 1; j < Dane::ny; j++){
						V1[i][j] = (1.0-omega)*V1[i][j] + omega*V2[i][j];
					}
				}
				sOld = sNew;
				sNew = 0.0;
				sNew = funS();
				iterVec.push_back(i);
				sVec.push_back(sNew);
				if(std::abs((sNew - sOld)/sOld) < Dane::TOL) break;
				i++;
			

			}

		}
};
class LocalRelaxation : public Relaxation{
	public:
		void relax(double omega){
			double sOld;
			double sNew;
			int i = 0;
			std::cout << "Local, omega: " << omega << std::endl;
			while(true){
				for(int j = 1; j < Dane::ny-1 ; j++){
					for(int i = 1; i < Dane::nx -1; i++){
						V1[i][j] = (1-omega)*V1[i][j] + omega*0.25*(V1[i+1][j] + V1[i-1][j] + V1[i][j+1] + V1[i][j-1] + rho[i][j]*Dane::dt*Dane::dt/Dane::epsilon);
					}
				}
				for(int j = 1; j < Dane::ny - 1; j++){
					V1[0][j] = V1[1][j];
					V1[Dane::nx - 1][j] = V1[Dane::nx - 2][j];
				}
				sOld = sNew;
				sNew = funS();
				iterVec.push_back(i);
				sVec.push_back(sNew);
				if(i!=0 && std::abs(sNew - sOld)/sOld < Dane::TOL) break;
				i++;
			}
		}
};

int main(){

	std::fstream fglobal = std::fstream("plots/globalErrorPlot.txt", std::ios::out);
	std::fstream flocal = std::fstream("plots/localErrorPlot.txt", std::ios::out);

	std::fstream fmatrix1 = std::fstream("plots/globalErrorMatrix1.txt", std::ios::out);
	std::fstream fmatrix2 = std::fstream("plots/globalErrorMatrix6.txt", std::ios::out);

	std::fstream fglobalV1 = std::fstream("plots/globalV1.txt", std::ios::out);
	std::fstream fglobalV6 = std::fstream("plots/globalV6.txt", std::ios::out);

	GlobalRelaxation globalRelaxation1;
	globalRelaxation1.relax(1);
	globalRelaxation1.writeS(fglobal);
	globalRelaxation1.writeSMatrix(fmatrix1);
	globalRelaxation1.writeV2(fglobalV1);

	GlobalRelaxation globalRelaxation2;
	globalRelaxation2.relax(0.6);
	globalRelaxation2.writeS(fglobal);
	globalRelaxation1.writeSMatrix(fmatrix2);
	globalRelaxation1.writeV2(fglobalV6);

	LocalRelaxation localRelaxation1;
	localRelaxation1.relax(1);
	localRelaxation1.writeS(flocal);

	LocalRelaxation localRelaxation2;
	localRelaxation2.relax(1.4);
	localRelaxation2.writeS(flocal);

	LocalRelaxation localRelaxation3;
	localRelaxation3.relax(1.8);
	localRelaxation3.writeS(flocal);

	LocalRelaxation localRelaxation4;	
	localRelaxation4.relax(1.9);
	localRelaxation4.writeS(flocal);
	
	fglobal.close();
	flocal.close();
	fmatrix1.close();
	fmatrix2.close();

	return 0;
}