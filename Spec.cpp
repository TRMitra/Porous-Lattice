#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<random>
#include<vector>
using namespace std;

double alpha (int m,double p,double q) {


		double x = m +  (m*(1+p)) * pow((2*m-(1+p)),-1) - 2;
		double y = m -  (m*(1+p)) * pow((2*m-(1+p)),-1);

		double a  = x - ((q*pow(y,2)) * pow(sqrt ((pow(y,2)*pow(q,2))+ pow((1+p),2)),-1));
		return a;


}

double f (int m,double p,double q) {

		double y = m - ((m*(1+p)) * pow((2*m-(1+p)),-1));

		double func = p - 1 + pow((1+p),2) / sqrt( pow(y,2)*pow(q,2) + pow((1+p),2) );
		return func;

}

ofstream fout ("WPSL1ml_spec0.75.dat");

int main() {

	for (double q = -1000; q <= 1000; q += 0.01){		

		fout << alpha(3,0.75,q) << '\t' << f(3,0.75,q) << '\t' << alpha(4,0.75,q) << '\t' << f(4,0.75,q) << '\t' << alpha(5,0.75,q) << '\t' << f(5,0.75,q) <<  endl;

	}


	return 0;
}