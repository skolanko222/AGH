#include <iostream>
using namespace std;

//! Function for converting temperature values
void temperature(const float T, const int Skala = 0);

int main(int argc, char *argv[])
{
	float a = 20.0;
	temperature(a);
	temperature(a, 1);
	temperature(a, -2);
} 

void temperature(const float T, const int Skala)
{
	switch(Skala)
	{
	case 0:
		cout << "Temperatura = " << T << " oC" << endl;
		break;
	case 1:
		cout << "Temperatura = " << T+273.13 << " K" << endl;
		break;
	default:
		cout << "Nieznana skala!!!" << endl;
		break;
	}
}
