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
	
	long long int num;
	long long int xi,li;
	long long int k;
	long long int N,Q;
	cin >> N >> k;
	vector<long long int> s;
	for(int i=0;i<N;i++){
		long long int si;
		cin >> si;
		s.push_back(si);
	}
	
	sort(s.begin(),s.end());
	cin >> Q;
	for(int i=0;i<Q;i++){
		long long int count=0;
		cin >> xi >> li;
		vector<long long int>::iterator L,H;
		for(int j=1;j<k;j++){
			if(xi*j>=li){
				break;
			}
			
			L = lower_bound(s.begin(),s.end(),min(xi*j,li));
			H = lower_bound(s.begin(),s.end(),min(xi*(j+1),li));
			num = H-L;
			count += (num*j);
			
		}
		
		if(xi*k<=li){
			L = lower_bound(s.begin(),s.end(),xi*k);
			H = upper_bound(s.begin(),s.end(),xi*k);
			num = H-L;
			count += (num*k);
		}
		else{
			L = lower_bound(s.begin(),s.end(),li);
			H = upper_bound(s.begin(),s.end(),li);
			num = H-L;
			count += (num*(li/xi));
		}
		
		cout << count << '\n';
	}
}
