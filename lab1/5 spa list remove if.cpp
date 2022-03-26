#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <list>
#include <functional> 
#include <numeric>
using namespace std;

long long int xi,li;
int k;
bool LowerThanxi(const int& value){
	return value<xi;
}
bool HigherThanli(const int& value){
	return value>li;
}
bool HigherThank(const int& value){
	return value>=k;
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,Q;
	cin >> N >> k;
	list<long long int> s;
	for(int i=0;i<N;i++){
		long long int si;
		cin >> si;
		s.push_back(si);
	}
	cin >> Q;
	for(int i=0;i<Q;i++){
		long long int count=0;
		cin >> xi >> li;
		list <long long int> scopy;
		scopy.assign(s.begin(),s.end());
		scopy.remove_if(LowerThanxi);
		scopy.remove_if(HigherThanli);
		list<long long int>::iterator it;
		
    	/*for(it=scopy.begin(); it!=scopy.end(); ++it){
    		long long int num = (*it)/xi;
    		if(num<k){
    			count+=num;
			}
		}
		cout << count << '\n';*/
		list <long long int> new_s;
		long long int scaler = xi;
		//transform(scopy.begin(), scopy.end(), scopy.begin(), [scaler](long long int &c){return c/scaler; });
		for_each(scopy.begin(), scopy.end(), [scaler](long long int &c){ c /= scaler; });
		scopy.remove_if(HigherThank);
		/*for(it=scopy.begin(); it!=scopy.end(); ++it){
			cout << *it << ' ';
		}
		cout << endl;*/
		cout << accumulate(scopy.begin(),scopy.end(),0) << '\n';
	}
}
