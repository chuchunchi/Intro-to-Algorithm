#include <iostream>
#include <algorithm>
#include <list>
#include <functional> 
#include <math.h>
using namespace std;

vector<int> rar(int n){
	if(n==1){
		vector<int> seq = {1};
		return seq;
	}
	else{
		vector<int> seq = rar(n-1);
		reverse(seq.begin(),seq.end());
		
		//cout<<"n:" << n << endl;
		vector<int> seq2 (pow(2,n-2),pow(2,n-2));
		
		int k = pow(2,n-2);
		vector<int> seq3(k,0);
		
		transform (seq.begin(), seq.end(), seq2.begin(), seq3.begin(), plus<int>());
		
		reverse(seq3.begin(),seq3.end());
		
		seq.insert(seq.begin(),seq3.begin(),seq3.end());
		return seq;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	
	vector<int> seq = rar(N+1);
	for (vector<int>::iterator it = seq.begin(); it != seq.end(); it++) {
    	cout << *it << " ";
	}
}
