#include <iostream>
#include <set>
using namespace std;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	
	
	long long int N,k;
	long long int L;
	int count = 0;
	cin >> N >> L >> k;
	multiset<long long int> ms;
	multiset<long long int>::iterator big,small;
	
	for(int i=0;i<N;i++){
		long long int w;
		cin >> w;
		ms.insert(w);
	}
	
	while(!ms.empty()){
		
		big = --ms.end();
		small = ms.begin();
		
		if(big==small){
			ms.erase(big);
			count++;
			break;
		}
		
		if(*big+*small<=L){
			ms.erase(big);
			ms.erase(small);
		}
		else{
			ms.erase(big);
		}
		count++;

	}
	cout << count*2*k;
	return 0;
} 
