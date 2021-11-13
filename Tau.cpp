#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<random>
#include<vector>
using namespace std;

double tau (int m,double p,double q) {


		double x = m +  (m*(1+p)) * pow((2*m-(1+p)),-1) - 2;
		double y = m -  (m*(1+p)) * pow((2*m-(1+p)),-1);

		double a  = -((x*q)+2-(1+p)) + sqrt ((pow(q,2)*pow(y,2)) + pow((1+p),2));
		return a;


}

ofstream fout ("WPSL1ml_tau0.75nn.dat");

int main() {

	for (double q = -1; q <= 4; q += 0.01){		

		fout << q << '\t' << tau (3,0.75,q) << '\t' << tau (4,0.75,q) << '\t' << tau (5,0.75,q) <<  endl;

	}


	return 0;
}