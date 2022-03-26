#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	vector<int> Ns;
	for(int j=0;j<T;j++){
		int N;
		cin >> N;
		Ns.push_back(N);
	}	
	int Nmax = *max_element(Ns.begin(),Ns.end());
	long long int downL=1,upL=2;
	vector <long long int> sum(Nmax+1,0);
	long long int prevdownL;
	sum[1] = 2;
	for(int i=2;i<=Nmax;i++){
		prevdownL = downL;
		downL = (upL+1+sum[i-2])%1000000007;
		upL = (downL+1+prevdownL)%1000000007;
		sum[i] = upL;
		//cout << "i " << i << " prev " << prevdownL << " downL " << downL << " upL " << upL << endl;
	}
	for(int j=0;j<T;j++){
		if(Ns[j]==0){
			cout << 0 << '\n';
		}
		else{
			cout << (4*sum[Ns[j]-1]+1)%1000000007 << '\n';
		}
		
	}
	
}






