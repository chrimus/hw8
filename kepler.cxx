#include <cmath>
#include <iostream>

using namespace std;

void Hamiltonian( double &H, double q1, double q2, double p1, double p2){
	H = 0.5*(pow(p1,2.0)+pow(p2,2.0))-1.0/(sqrt(pow(q1,2.0)+pow(q2,2.0)));
}

int main(){
	
	//user inteface
	double tBeg = 0;
	double tEnd = 20*M_PI;
	double dt = 5e-4;
	double e  = 0.6;
	
	//Parameters
	int N = (tEnd-tBeg)/dt;
	double H = 0;
	
	//initial conditions
	double q1 = 1-e;	double p1 = 0;
	double q2 = 0;		double p2 = sqrt((1+e)/(1-e));
	Hamiltonian(H, q1, q2, p1, p2);
	
	for( int i=0; i<N+1; i++){
		
		cout << tBeg+i*dt << "\t" << q1 << "\t" << q2 << "\t" 
		<< p1 << "\t" << p2 << "\t" << H  << endl;
		
		double temp = pow( pow(q1,2)+pow(q2,2), 3.0/2);
		
		p1 -= q1/temp * dt;
		p2 -= q2/temp * dt;
		
		q1 += p1 * dt;
		q2 += p2 * dt;
		
		Hamiltonian(H, q1, q2, p1, p2);
	}
	
	return 1;
}

