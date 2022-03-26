#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int,long long int> intpair;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	long long int p,Lt,Rt;
	cin >> N >> p;
	cin >> Lt >> Rt;
	//vector<intpair> v;
	//vector<intpair>::iterator it;
	map<long long int,long long int> mp;
	map<long long int,long long int>::iterator it,left;
	for(int i=0;i<N;i++){
		long long int Li,Ri;
		cin >> Li >> Ri;
		//v.push_back(make_pair(Ri,Li));
		mp[Li] = Ri;
	}
	long long int count=0;
	//priority_queue<intpair> choice;
	long long int max = Lt;
	left = mp.begin();
	while(Lt<Rt){
		int iscontinue=0;
		
		for(it=left;it!=mp.end();it++){
			if(it->second<=Lt){
				//mp.erase(it);
				continue;
			}
			else if(it->first<=Lt&&it->second>max){
				max = it->second;
				//choice.push(make_pair(it->second,it->first));
				iscontinue = 1;
				
				continue;
			}
			else if(it->first>Lt){
				left = prev(it);
				//cout << "too over!" << it->first << endl;
				break;
			}
		}
		/*for(it=mp.begin();it!=mp.end();it++){
			cout << "1: " << it->first << "    2: " << it->second << endl;
		}*/
		if(iscontinue==0){
			cout << 0;
			return 0; 
		}
		Lt = max;
		//Lt = choice.top().first;
		//choice.pop();
		count ++;
	}
	cout << count*p;
	return 0; 
	
	
}
