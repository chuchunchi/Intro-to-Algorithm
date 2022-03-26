#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,T;
	cin >> N >> T;
	long long int cij[T][N];
	for(int i=0;i<T;i++){
		for(int j=0;j<N;j++){
			long long int c;
			cin >> c;
			cij[i][j] = c;
		}
	}
	for(int i=T-2;i>=0;i--){
		for(int j=0;j<N;j++){
			if(j>=1&&j<=N-2){
				cij[i][j]+=*max_element(cij[i+1]+j-1,cij[i+1]+j+2);
				//cout << "one " << *max_element(cij[i+1]+j-1,cij[i+1]+j+2) << endl;
			}
			else if(j==0&&j==N-1){
				cij[i][j]+=cij[i+1][j];
			}
			else if(j==0){
				cij[i][j]+=*max_element(cij[i+1],cij[i+1]+2);
				//cout << "two " << *max_element(cij[i+1],cij[i+1]+2) << endl;
			}
			else if(j==N-1){
				cij[i][j]+=*max_element(cij[i+1]+j-1,cij[i+1]+j+1);
			}
		}
	}
	for(int j=0;j<N;j++){
		cout << cij[0][j] << " ";
	}
}
