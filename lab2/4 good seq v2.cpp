#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

long long int goodseq(long long int arr[], long long int l, long long int r){
	long long int m = (l+r)/2;
	long long int subv1[m-l+1],subv2[r-m];
	long long int csubv1[m-l+1],csubv2[r-m];
	copy(arr,arr+(m-l+1),subv1);
	copy(arr,arr+(m-l+1),csubv1);	
	copy(arr+(m-l+1),arr+(r-l+1),subv2);
	copy(arr+(m-l+1),arr+(r-l+1),csubv2);
	if(r-l+1<=2){
		return 0;
	}
	long long int op1=0,op2=0;
	
	nth_element(subv1,subv1+(m-l)/2,subv1+m-l+1);
	long long int median1 = subv1[+(m-l)/2];
	//cout << median1 << endl; 
	for(int i=0;i<m-l+1;i++){
		op1 += abs(subv1[i]-median1);
	}
	op1 += goodseq(csubv2,m+1,r);
	
	nth_element(subv2,subv2+(r-m-1)/2,subv2+r-m);
	long long int median2 = subv2[(r-m-1)/2];
	//cout << median2 << endl;
	for(int i=0;i<r-m;i++){
		op2 += abs(subv2[i]-median2);
	}
	op2 += goodseq(csubv1,l,m);
	return min(op1,op2);
	
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	long long int opers = 0; //output
	cin >> N;
	long long int a[N];
	for(int i=0;i<N;i++){
		long long int ai;
		cin >> ai;
		a[i] = ai;
	}
	long long int l=0, r=N-1;
	cout << goodseq(a,l,r);
	
	
	
}
