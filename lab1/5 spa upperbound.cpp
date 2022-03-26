#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <list>
#include <functional> 
#include <numeric>
using namespace std;


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	long long int xi,li;
	int k;
	int N,Q;
	cin >> N >> k;
	list<long long int> s;
	for(int i=0;i<N;i++){
		long long int si;
		cin >> si;
		s.push_back(si);
	}
	cout << "?????????";
	s.sort();
	cin >> Q;
	for(int i=0;i<Q;i++){
		int count=0;
		cin >> xi >> li;
		list<long long int>::iterator L,H;
		for(int j=1;j<k;j++){
			L = lower_bound(s.begin(),s.end(),xi*j);
			H = lower_bound(s.begin(),s.end(),min(xi*(j+1),li));
			int num = distance(L,H);
			count += (num*j);
		}
		
		cout << count << '\n';
	}
}
