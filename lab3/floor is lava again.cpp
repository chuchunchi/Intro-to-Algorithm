#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,k;
	cin >> N >> k;
	vector <double> C,P;
	vector<int> been(N,0);
	for(int i=0;i<N;i++){
		double ci,pi,potheri;
		cin >> ci >> pi;
		C.push_back(ci);
		P.push_back(pi);
		
	}
	priority_queue<pair <double,int>> pq;
	for(int j=0;j<N;j++){
		double calc;
		if(P[j]==0&&been[j]==0){
			calc = C[j];	
		}
		else if(P[j]==0&&been[j]!=0){
			calc = 0;
		}
		else{
			calc = C[j]*P[j]/((P[j])*(P[j]+1));
		}
		pq.push(make_pair(calc,j));
	}
	
	double total=0;
	
	for(int i=2;i<=k+1;i++){
		pair<double,int> tmp = pq.top();
		pq.pop();
		total += tmp.first;
		int j = tmp.second;
		been[j] ++;
		double calc=0;
		if(P[j]==0&&been[j]==0){
			calc = C[j];	
		}
		else if(P[j]==0&&been[j]!=0){
			calc = 0;
		}
		else{
			calc = C[j]*P[j]/((P[j]+been[j])*(P[j]+been[j]+1));
		}
		pq.push(make_pair(calc,j));
	}
	cout << fixed << setprecision(7) << total;
	return 0; 
	
	
}
