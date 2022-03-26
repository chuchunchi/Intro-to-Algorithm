#include <iostream>
#include <queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long int N;
	cin >> N;
	priority_queue <long long int, vector<long long int>, greater<long long int>> pq;
	for(int i=0;i<N;i++){
		long long int c;
		cin >> c;
		if(c>N){
			c = N;
		}
		pq.push(c);
	}
	long long int multi=1, minus = 0; 
	while(!pq.empty()){
		multi *= (pq.top()-minus)%1000000007;
		multi%=1000000007;
		minus++;
		pq.pop();
	}
	cout << multi%1000000007 << '\n';
	
	return 0;
} 
