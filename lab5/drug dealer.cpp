#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int N;
vector<vector<int> > neighbor;
vector<int> police;
vector<int> bfssssp(int source) {
	queue<int> q;
 	vector<int> hops;
 	hops.resize(N+1, 0);
 	vector<int> visit;
 	visit.resize(N+1, 0);
 	q.push(source);
 	visit[source] = 1;
 	
 	while (!q.empty()) {
  		int qfront = q.front();
  		q.pop();
  		for (int i = 0; i < neighbor[qfront].size(); i++) {
   			if (visit[neighbor[qfront][i]] == 0) {
    			q.push(neighbor[qfront][i]);
    			hops[neighbor[qfront][i]] = hops[qfront] + 1;
    			visit[neighbor[qfront][i]] = 1;
   			}
  		}
 	}
 	return hops;
}


vector<int> bfssssp2() {
 	queue<int> q;
 	vector<int> hops;
 	hops.resize(N + 1, 0);
 	vector<int> visit;
 	visit.resize(N + 1, 0);
 	for(int i=0;i<police.size();i++){
  	q.push(police[i]);
  	visit[police[i]] = 1;
 	} 
 
 	while (!q.empty()) {
  		int qfront = q.front();
  		q.pop();
  		for (int i = 0; i < neighbor[qfront].size(); i++) {
   			if (visit[neighbor[qfront][i]] == 0) {
    			q.push(neighbor[qfront][i]);
    			hops[neighbor[qfront][i]] = hops[qfront] + 1;
    			visit[neighbor[qfront][i]] = 1;
   			}
  		}
 	}
 	return hops;
}

int main() {
 	cin.sync_with_stdio(0);
 	cin.tie(0);
 	int T;
 	cin >> T;
 	for (int t = 0; t < T; t++) {
 		
  		int M, S;
  		cin >> N >> M >> S;
  		//vector<vector<int> > neighbor;
  		neighbor.clear();
  		neighbor.resize(N+1);
	  	for (int m = 0; m < M; m++) {
	   		int ui, vi;
	   		cin >> ui >> vi;
	   		neighbor[ui].push_back(vi);
	   		neighbor[vi].push_back(ui);
	  	}
	
	  	vector<int> hops;
	  	hops = bfssssp(S);
	  	int X, Y;
	  	cin >> X;
	  
	  	police.clear();
	  	for (int x = 0; x < X; x++) {
	   		int ai;
	   		cin >> ai;
	   		police.push_back(ai); 
	  	}
	  
		vector<int> policehops;
		policehops = bfssssp2();
		  
		cin >> Y;
		int ans = 0;
		for (int y = 0; y < Y; y++) {
		 	int bi;
		   	cin >> bi;
		   	if (policehops[bi] > hops[bi] && ans==0) {
		    	cout << "Yes" << '\n';
		    	ans = 1;
		   	}
		}
		if (ans == 0) {
			cout << "No" << '\n';
		}
	
	}
	
}
