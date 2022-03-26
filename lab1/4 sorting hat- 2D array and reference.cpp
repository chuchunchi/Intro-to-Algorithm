#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>          
using namespace std;

bool cmp(pair<string,vector<int>> &a, pair<string,vector<int>> &b){
	if(a.second[0]!=b.second[0]){
		return a.second[0]>b.second[0];
	}
	else if(a.second[1]!=b.second[1]){
		return a.second[1]>b.second[1];
	}
	else if(a.second[2]!=b.second[2]){
		return a.second[2]>b.second[2];
	}
	else if(a.second[3]!=b.second[3]){
		return a.second[3]>b.second[3];
	}
	else{
		return a.first < b.first;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	int arr[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			char ch;
			cin >> ch;
			if(ch=='G') arr[i][0] = j;
			else if(ch=='H') arr[i][1] = j;
			else if(ch=='R') arr[i][2] = j;
			else if(ch=='S') arr[i][3] = j;
		}
	}
	vector<pair<string/*name*/,vector<int>>> G,H,R,S;
	vector<pair<string,vector<int>>>::iterator it;
	for(int i=0;i<N;i++){
		string name;
		int gi, hi, ri, si;
		cin >> name >> gi >> hi >> ri >> si;
		vector<int> m(4,0);
		vector<int> v ={gi,hi,ri,si};
		auto highest = max_element(v.begin(),v.end());
		if(*highest==gi){
			m[arr[0][0]] = gi;
			m[arr[0][1]] = hi;
			m[arr[0][2]] = ri;
			m[arr[0][3]] = si;
			
			G.push_back(make_pair(name,m));
		}
		else if(*highest==hi){
			m[arr[1][0]] = gi;
			m[arr[1][1]] = hi;
			m[arr[1][2]] = ri;
			m[arr[1][3]] = si;
			
			H.push_back(make_pair(name,m));
		}
		else if(*highest==ri){
			m[arr[2][0]] = gi;
			m[arr[2][1]] = hi;
			m[arr[2][2]] = ri;
			m[arr[2][3]] = si;
			R.push_back(make_pair(name,m));
		}
		else if(*highest==si){
			m[arr[3][0]] = gi;
			m[arr[3][1]] = hi;
			m[arr[3][2]] = ri;
			m[arr[3][3]] = si;
			S.push_back(make_pair(name,m));
		}
		
	}
	
	if(G.empty()){
		cout << "GRYFFINDOR: NO NEW STUDENTS" << '\n';
	}
	else if(G.size()==1){
		cout << "GRYFFINDOR: " << '\n';
		cout << G[0].first << '\n';
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
	else if(H.size()==1){
		cout << "HUFFLEPUFF: " << '\n';
		cout << H[0].first << '\n';
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
	else if(R.size()==1){
		cout << "RAVENCLAW: " << '\n';
		cout << R[0].first << '\n';
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
	else if(S.size()==1){
		cout << "SLYTHERIN: " << '\n';
		cout << S[0].first << '\n';
	}
	else{
		sort(S.begin(),S.end(),cmp);
		cout << "SLYTHERIN:" << '\n';
		for(it=S.begin();it!=S.end();it++){
			cout << it->first << '\n';
		}
	}
}
