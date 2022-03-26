#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int a_power_kminus1(long long int a, long long int k){
	long long int result=1;
	long long int asquare = a*a%1000000007;
	if(k%2){
		for(int i=0;i<(k-1)/2;i++){
			(result *= asquare)%1000000007;
		}
	}
	if(k%2==0){
		for(int i=0;i<(k-1)/2;i++){
			(result *= asquare)%1000000007;
		}
		(result *= a)%1000000007;
	}
	return result;
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	long long int a,b;
	cin >> a >> b >> N;
	for(int i=0;i<N;i++){
		long long int qi;
		cin >> qi;
		long long int a_kminus1 = a_power_kminus1(a,qi);
		long long int fk = a_kminus1 + b*(1-a_kminus1)/(1-a);
		cout << fk << '\n'; 
	}
	
} 
