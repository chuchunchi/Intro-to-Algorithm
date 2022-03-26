#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>    
#include <list>      
using namespace std;

bool cmp(pair<string,list<long long int>> a, pair<string,list<long long int>> b){
	for(int i=0;i<4;i++){
		if(a.second.front()!=b.second.front()){
			return a.second.front()>b.second.front();
		}
		a.second.pop_front();
		b.second.pop_front();
	}
	return a.first < b.first;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	string Sg,Sh,Sr,Ss;
	cin >> Sg >> Sh >> Sr >> Ss;
	vector<pair<string/*name*/,list<long long int>>> G,H,R,S;
	vector<pair<string,list<long long int>>>::iterator it;
	for(int i=0;i<N;i++){
		string name;
		long long int gi, hi, ri, si;
		cin >> name >> gi >> hi >> ri >> si;
		list<long long int> m;
		vector<long long int> v ={gi,hi,ri,si};
		auto highest = max_element(v.begin(),v.end());
		if(*highest==gi){
			m.push_back(gi);
			switch (Sg[1]){
				case 'H':
					m.push_back(hi);
					break;
				case 'R':
					m.push_back(ri);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			switch (Sg[2]){
				case 'H':
					m.push_back(hi);
					break;
				case 'R':
					m.push_back(ri);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			switch (Sg[3]){
				case 'H':
					m.push_back(hi);
					break;
				case 'R':
					m.push_back(ri);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			G.push_back(make_pair(name,m));
		}
		else if(*highest==hi){
			m.push_back(hi);
			switch (Sh[1]){
				case 'G':
					m.push_back(gi);
					break;
				case 'R':
					m.push_back(ri);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			switch (Sh[2]){
				case 'G':
					m.push_back(gi);
					break;
				case 'R':
					m.push_back(ri);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			switch (Sh[3]){
				case 'G':
					m.push_back(gi);
					break;
				case 'R':
					m.push_back(ri);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			H.push_back(make_pair(name,m));
		}
		else if(*highest==ri){
			m.push_back(ri);
			switch (Sr[1]){
				case 'G':
					m.push_back(gi);
					break;
				case 'H':
					m.push_back(hi);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			switch (Sr[2]){
				case 'G':
					m.push_back(gi);
					break;
				case 'H':
					m.push_back(hi);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			switch (Sr[3]){
				case 'G':
					m.push_back(gi);
					break;
				case 'H':
					m.push_back(hi);
					break;
				case 'S':
					m.push_back(si);
					break;
			}
			R.push_back(make_pair(name,m));
		}
		else if(*highest==si){
			m.push_back(si);
			switch (Ss[1]){
				case 'G':
					m.push_back(gi);
					break;
				case 'H':
					m.push_back(hi);
					break;
				case 'R':
					m.push_back(ri);
					break;
			}
			switch (Ss[2]){
				case 'G':
					m.push_back(gi);
					break;
				case 'H':
					m.push_back(hi);
					break;
				case 'R':
					m.push_back(ri);
					break;
			}
			switch (Ss[3]){
				case 'G':
					m.push_back(gi);
					break;
				case 'H':
					m.push_back(hi);
					break;
				case 'R':
					m.push_back(ri);
					break;
			}
			S.push_back(make_pair(name,m));
		} 
	}
	
	if(G.empty()){
		cout << "GRYFFINDOR: NO NEW STUDENTS" << '\n';
	}
	else{
		sort(G.begin(),G.end(),cmp);
		cout << "GRYFFINDOR:" << '\n';
		for(it=G.begin();it!=G.end();it++){
			cout << it->first << '\n';
		}
	}
	
	if(H.empty()){
		cout << "HUFFLEPUFF: NO NEW STUDENTS" << '\n';
	}
	else{
		sort(H.begin(),H.end(),cmp);
		cout << "HUFFLEPUFF:" << '\n';
		for(it=H.begin();it!=H.end();it++){
			cout << it->first << '\n';
		}
	}
	
	if(R.empty()){
		cout << "RAVENCLAW: NO NEW STUDENTS" << '\n';
	}
	else{
		sort(R.begin(),R.end(),cmp);
		cout << "RAVENCLAW:" << '\n';
		for(it=R.begin();it!=R.end();it++){
			cout << it->first << '\n';
		}
	}
	
	if(S.empty()){
		cout << "SLYTHERIN: NO NEW STUDENTS" << '\n';
	}
	else{
		sort(S.begin(),S.end(),cmp);
		cout << "SLYTHERIN:" << '\n';
		for(it=S.begin();it!=S.end();it++){
			cout << it->first << '\n';
		}
	}
}
