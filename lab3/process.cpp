#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,c,q;
	cin >> N >> c >> q;
	vector< vector<int> >  v2d;
	vector<int> t;
	v2d.resize(N+1);
	for(int i=0;i<q;i++){
		int ki;
		cin >> ki;
		t.push_back(ki);
		v2d[ki].push_back(i);
	}
	
	int count=0;
	vector<int> exist(N+1,0);
	vector<int> index(N+1,0);
	priority_queue<pair<int,int> > pq;
	
	for(int i=0;i<q;i++){
		if(count<c&&exist[t[i]]==0){
			exist[t[i]]=1;
			
			if(index[t[i]]<v2d[t[i]].size()-1){
				index[t[i]]++;
				int ind = v2d[t[i]][index[t[i]]];
				pq.push(make_pair(ind,t[i]));
			}
			else{
				index[t[i]]++;
				pq.push(make_pair(q,t[i]));
			}
			count++;
			
			continue;
		}
		else if(count<c&&exist[t[i]]==1){
			
			if(index[t[i]]<v2d[t[i]].size()-1){
				index[t[i]]++;
				int ind = v2d[t[i]][index[t[i]]];
				pq.push(make_pair(ind,t[i]));
			}
			else{
				index[t[i]]++;
				pq.push(make_pair(q,t[i]));
			}
		}
		else if(count>=c){
			if(exist[t[i]]==0){
				exist[pq.top().second]=0;
				pq.pop();
				exist[t[i]]=1;
				if(index[t[i]]<v2d[t[i]].size()-1){
					index[t[i]]++;
					int ind = v2d[t[i]][index[t[i]]];
					pq.push(make_pair(ind,t[i]));
				}
				else{
					index[t[i]]++;
					pq.push(make_pair(q,t[i]));
				}
				count++;
			}
			else{
				
				if(index[t[i]]<v2d[t[i]].size()-1){
					index[t[i]]++;
					int ind = v2d[t[i]][index[t[i]]];
					pq.push(make_pair(ind,t[i]));
				}
				else{
					index[t[i]]++;
					pq.push(make_pair(q,t[i]));
				}
			}
		}
	}
	cout << count << '\n';
}
