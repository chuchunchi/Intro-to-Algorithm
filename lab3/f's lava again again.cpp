//save
#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,k;
	cin >> N >> k;
	vector <int> C,P;
	vector<double> POther,PSelf;
	for(int i=0;i<N;i++){
		double ci,pi,potheri;
		cin >> ci >> pi;
		//C.push_back(ci);
		//P.push_back(pi);
		if(pi==0){
			potheri = 0.0;
		}
		else{
			potheri = ci*pi/(pi+2);
		}
		POther.push_back(potheri);
		PSelf.push_back(ci-potheri); //x>=1
	}
	
	for(int i=0;i<N;i++){
		cout << fixed << setprecision(7) << PSelf[i] << " ";
	}
	return 0; 
	
	
}
