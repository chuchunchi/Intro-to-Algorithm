#include <iostream>
#include <bits/stdc++.h>
#include <limits>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<long long int> A,reward,Aplus;
	Aplus.resize(N+1);
	Aplus[0] = 0;
	A.push_back(0);
	for(int i=1;i<=N;i++){
		long long int ai;
		cin >> ai;
		A.push_back(ai);
		if(i>0){
			Aplus[i] = Aplus[i-1]+A[i]; 
		}
	}
	
	long long int f[N+1][N+1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			f[i][j] = 0;
		}
		
	}
	for(int len=3;len<=N;len+=2){
		for(int l=1;l+len-1<=N;l++){
			int r = l+len-1;
			//else{
				f[l][r] = -INT_MAX;
				for(int k=l+1;k<r;k+=2){
					f[l][r] = max(f[l][r],f[l][k-1]+f[k+1][r]+((Aplus[k-1]-Aplus[l-1])*(Aplus[r]-Aplus[k])-(Aplus[k]-Aplus[k-1])));
					//cout << "bbbbbb " << ((Aplus[k-1]-Aplus[l-1])*(Aplus[r]-Aplus[k])-(Aplus[k]-Aplus[k-1])) << endl;
					//cout << "l " << l << " r " << r << " flr " << f[l][r] << endl;
				}
				f[l][r] = max(f[l][r],f[l+1][r-1]+((Aplus[l]-Aplus[l-1])*(Aplus[r]-Aplus[r-1])-(Aplus[r-1]-Aplus[l+1-1])));
			//}
		}
	}
	cout << f[1][N] << endl; 
}






