#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<random>
#include<vector>
using namespace std;
int main() {
ofstream fout1 ("WPSL1p_dc0.25.dat");
ofstream fout2 ("WPSL1p_area0.25.dat");
int e; //ensemble value
e=100;
int t=9999; //number of times of division

vector <int> K;
vector <double> Av;

for (int i=0; i<10000; i++) {

	Av.push_back (0);
}

for (int i=0;i<e;i++) {
	vector <double> AAv;

random_device rd;
mt19937 engine (rd());
 uniform_int_distribution <int> _dist(0,1000000000);
 						int xx= _dist (engine);
 						double cc=xx*0.000000001;

 						int x= _dist (engine);
 						double c=x*0.000000001;
 						double c1;
 						double c2;

 						if (c<=0.5){
 	 						c2=cc;
 	 						c1=0;
 	 					}
 	 					else {
 	 						c2=0;
 	 						c1=cc;
 	 					}
 	 											
vector<double> A;
vector <double> Ar;
A.push_back(0);
if (c<=0.5) {
	A.push_back((1-c2)*1);
A.push_back(c2*1);
}
else {
A.push_back(c1*1);
A.push_back((1-c1)*1);
}
vector<double> xl;
vector<double> xh;
vector<double> yl;
vector<double> yh;
if (c<=0.5) {
xl.push_back(0);
xl.push_back(0);
xl.push_back(0);

xh.push_back(0);
xh.push_back(1);
xh.push_back(1);

yl.push_back(0);
yl.push_back(c2);
yl.push_back(0);

yh.push_back(0);
yh.push_back(1);
yh.push_back(c2);
		}

	else {
xl.push_back(0);
xl.push_back(0);
xl.push_back(c1);

xh.push_back(0);
xh.push_back(c1);
xh.push_back(1);

yl.push_back(0);
yl.push_back(0);
yl.push_back(0);

yh.push_back(0);
yh.push_back(1);
yh.push_back(1);
		}

 						int xp= _dist (engine);
						double cp=xp*0.000000001;
						int cco=0;

	if (cp>0.25) {
		cco = cco+1;
		Ar.push_back (A[2]);
		A.erase(A.begin()+2);
		//A.insert(A.begin()+2,0);
		xl.erase(xl.begin()+2);
		//xl.insert(xl.begin()+2,0);
		xh.erase(xh.begin()+2);
		//xh.insert(xh.begin()+2,0);
		yl.erase(yl.begin()+2);
		//yl.insert(yl.begin()+2,0);
		yh.erase(yh.begin()+2);
		//yh.insert(yh.begin()+2,0);
	}

//	cout << cco << endl;

vector <double> AC; //AC= cumulative areas of the boxes	
int n; // cell number to be divided
int m; // number of remaining cells
int l;
for (int i = 2; i <=t ; i++){

double p=0;
double q=0;
double r=0;
double s=0; // four coordinates of the cell to be divided
l = i-cco;
for(int k=0;k<=(l-1)+1;k++){
AC.insert (AC.begin()+k,0);
		}
for(int k=0;k<=(l-1)+1;k++){
	for (int j=0;j<=k;j++){
		AC[k]+=A[j];
					}
					//cout<<"Area:"<<AC[k]<<endl;

				}
// c3 will determine the random number which will choose the area range to choose the box to be divided
uniform_int_distribution <int> _dist(0,1000000000);
 						int x3= _dist (engine);
						double c3=x3*0.000000001;
						
for (int j = 0; j <=(l-1); ++j){

	if (c3>AC[j] && c3<=AC[j+1]){
		p=xl[j+1];
		q=yl[j+1];
		r=xh[j+1];
		s=yh[j+1];
		n=j+1;
		//break;
				  }

			}
//cout<<n<<endl;
if (p==0 && q==0 && r==0 && s==0) {
 cco = cco+1;
	goto below;
}


else {

double d1;
double d2;
int xcc= _dist (engine);
double ccc=xcc*0.000000001;

int x4= _dist (engine);
double c4=x4*0.000000001;

int x5= _dist (engine);
double c5=x5*0.000000001;


if (ccc<=0.5) {			
 						d2=(c4*(s-q))+q; //produce a random number between s & q
 						d1=0;
 					}

 			else {	

 						d1=(c5*(r-p))+p; //produces a random number between r & p
 						d2=0;
									}

/*for (double b=0;b<=1;b+=1) {

fout3 << b << '\t' << c2 << '\t' << c1 << '\t' << ((r-p)*b)+p << '\t' << d2 << '\t' << ((s-q)*b)+q << '\t' << d1 << endl;

}*/

if (ccc<0.5) {
A.erase (A.begin ()+n);
A.insert (A.begin ()+n,(s-d2)*(r-p));
A.push_back ((d2-q)*(r-p));

//xl.erase (xl.begin ()+n);
//xl.insert (xl.begin ()+n,p);
xl.push_back (p);

//xh.erase (xh.begin ()+n);
//xh.insert (xh.begin ()+n,r);
xh.push_back (r);

yl.erase (yl.begin ()+n);
yl.insert (yl.begin ()+n,d2);
yl.push_back (q);

yh.erase (yh.begin ()+n);
yh.insert (yh.begin ()+n,s);
yh.push_back (d2);

		}

	else {


A.erase (A.begin ()+n);
A.insert (A.begin ()+n,(s-q)*(d1-p));
A.push_back ((s-q)*(r-d1));

xl.erase (xl.begin ()+n);
xl.insert (xl.begin ()+n,p);
xl.push_back (d1);

xh.erase (xh.begin ()+n);
xh.insert (xh.begin ()+n,d1);
xh.push_back (r);

//yl.erase (yl.begin ()+n);
//yl.insert (yl.begin ()+n,q);
yl.push_back (q);

//yh.erase (yh.begin ()+n);
//yh.insert (yh.begin ()+n,s);
yh.push_back (s);

AC.erase (AC.begin(),AC.end ());

	}
	int xpp= _dist (engine);
double cpp=xpp*0.000000001;

int w = i+1-cco;

if (cpp>0.25) {

	Ar.push_back (A[w]);

A.erase (A.begin ()+w);
//A.insert (A.begin ()+n+1,0);
xl.erase (xl.begin ()+w);
//xl.insert (xl.begin ()+n+1,0);
xh.erase (xh.begin ()+w);
//xh.insert (xh.begin ()+n+1,0);
yl.erase (yl.begin ()+w);
//yl.insert (yl.begin ()+n+1,0);
yh.erase (yh.begin ()+w);
//yh.insert (yh.begin ()+n+1,0);
cco = cco+1;

}


}
	below:
	;

}

int  count;

for (int i = 1; i < A.size(); ++i){

	fout2 << i << '\t' << A[i] <<endl;
}

for (double j = 0; j < 0.01; j+=0.00001){

		count = 0;


	for (int i = 1; i < A.size(); i++){
		
			if (A[i] > j && A[i] <= j+0.00001) {
			//cout << "True" << " " << j << '\t' << i <<endl;
			count = count + 1;

			}
		}

		AAv.push_back (count);
	}

for (int i = 0; i <10000 ; i++){

	Av[i] = Av[i] + AAv[i];
}

K.clear ();
A.clear ();
Ar.clear ();
xl.clear ();
xh.clear ();
yl.clear ();
yh.clear ();
AC.clear ();

}

for (double i=0; i<0.01; i+=0.00001) {

if (Av[i*100000]!=0) {

fout1 << i << '\t' << Av[i*100000]*pow(e,-1)*100000 <<  '\t' << log(Av[i*100000]*pow(e,-1)*100000) << endl;

}

}
return 0;
}