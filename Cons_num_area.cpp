#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<random>
#include<vector>
using namespace std;
int main() {
ofstream fout1 ("WPSL1p_cons0.5s.dat");
ofstream fout2 ("WPSL1_c.dat");
ofstream fout3 ("WPSL1n.dat");
ofstream fout4 ("A_rmt.dat");
ofstream fout5 ("AA1_0.5st.dat");
ofstream fout6 ("N1_0.5st.dat");
int e; //ensemble value
e=1;
int t=19999; //number of times of division
vector <int> K;
vector <double> area1_v;
vector <double> m_area1_v;
double m_area1;
double area1;
vector <double> area2_v;
vector <double> m_area2_v;
double m_area2;
double area2;
vector <double> area3_v;
vector <double> m_area3_v;
double m_area3;
double area3;
int ccount=0;
vector <double> AAe;
vector <double> Nve;

for (int i=0; i<20000; i++) {

	AAe.push_back (0);
}

for (int i=0; i<20000; i++) {

	Nve.push_back (0);
}

for (int i=0;i<e;i++) {
	m_area1 = 0;
	m_area2 = 0;
	m_area3 = 0;
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

	if (cp>0.5) {
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
		fout2 << 2 << endl;
	}

//	cout << cco << endl;

vector <double> AC; //AC= cumulative areas of the boxes	
int n; // cell number to be divided
int m; // number of remaining cells
int l;
vector <double> AAv;
vector <double> Nv;
for (int i = 2; i <=t ; i++){
	double AA= 0;
	double N =0;
	area1 = 0;
	area2 = 0;
	area3 = 0;

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
//cout << "a" << endl;
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

if (cpp>0.5) {

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
fout2 << i+1 << endl;
}
	fout3<<endl;


}
	below:
	;
for (int z = 1; z < xh.size () ; z++) {

	double l = xh[z] - xl [z] ;
	double b = yh[z] - yl [z] ;

	area1 = area1 + pow(l,2);
	area2 = area2 + pow(l,1)*pow(b,0.2);
	area3 = area3 + pow(l,3)*pow(b,-0.07692307692) ;
}

area1_v.push_back (area1);
area2_v.push_back (area2);
area3_v.push_back (area3);

for (int i=0; i<A.size(); i++) {

		AA = AA + A[i];
	}

	AAv.push_back (AA);

N = N + xl.size()-1;
Nv.push_back (N);


}




//cout << cco << endl;

/*for (int i=0; i<xl.size();i++)
fout1 << xl[i] << '\t' << xh[i] << '\t' << yl[i] << '\t' << yh[i] << endl;
*/ 	

//cout << xl.size()-1 <<endl;
ccount = ccount + xl.size()-1;

for (int y = 0; y < area1_v.size() ; y++){
m_area1_v.push_back (0);
m_area2_v.push_back (0);
m_area3_v.push_back (0);
 }

for (int y = 0; y < area1_v.size() ; y++){

m_area1_v[y] = m_area1_v[y] + area1_v[y] ;
m_area2_v[y] = m_area2_v[y] + area2_v[y] ;
m_area3_v[y] = m_area3_v[y] + area3_v[y] ;
}
double aarea1 = 0;
for (int i=0; i<A.size(); i++) {

aarea1 = aarea1 + A[i];

}

double aarea2 = 0;
for (int i=0; i<Ar.size(); i++) {

	aarea2 = aarea2 + Ar[i];
}

//cout << "Total area =" << " " << aarea1+aarea2 << endl;

for (int i=0; i<AAv.size(); i++) {

	AAe[i] = AAe[i] + AAv[i];
}

for (int i=0; i<Nv.size(); i++) {

	Nve[i] = Nve[i] + Nv[i];
}

K.clear ();
A.clear ();
Ar.clear ();
xl.clear ();
xh.clear ();
yl.clear ();
yh.clear ();
AC.clear ();
area1_v.clear();
area2_v.clear();
area3_v.clear();



}

for (int y = 97; y <= t+1 ; y+=100){


fout1 << y+3 << '\t' << log(y+3) << '\t' << m_area1_v[y] * pow (e,-1) << '\t' << log(m_area1_v[y] * pow (e,-1)) << '\t' << m_area2_v[y] * pow (e,-1) << '\t' << log(m_area2_v[y] * pow (e,-1)) << '\t' << m_area3_v[y] * pow (e,-1) << '\t' << log(m_area3_v[y] * pow (e,-1)) << endl;
						
}

for (int i=0; i<=19997; i++) {

	fout5 << i+2 << '\t' << AAe[i]*pow(e,-1) << '\t' << log(i+2) << '\t' << log(AAe[i]*pow(e,-1)) << endl;

}

for (int i=0; i<=19997; i++) {

	fout6 << i+2 << '\t' << Nve[i]*pow(e,-1) << '\t' << log(i+2) << '\t' << log(Nve[i]*pow(e,-1)) << endl;

}

cout << ccount * pow(e,-1) << endl;
return 0;
}