#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int N;

vector<vector<int> > neighbor;
vector<vector<int> > neighinv;
vector<int> visit;
vector<int> finish;
vector <int> scc_n;
set<int> scc_p;
vector<int> weight;
int pcount = 0;
void DFS1(int i) {
	if (visit[i]) {
		return;
	}
	visit[i] = 1;
	for (int j = 0; j < N; ++j) {
		if (neighbor[i][j]) {
			DFS1(j);
		}
	}

	finish.push_back(i);
}

void DFS2(int i, int parent) {
	if (visit[i]) {
		pcount--;
		return;
	}
	visit[i] = 1;
	for (int j = 0; j < N; ++j) {
		if (neighbor[j][i]) {
			DFS2(j, parent);
		}
	}
	scc_n[i] = parent;
	scc_p.insert(parent);
	weight[parent]++;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int  M;
	cin >> N >> M;

	neighbor.resize(N);
	neighinv.resize(N);
	visit.resize(N, 0);
	//finish.resize(N);
	scc_n.resize(N);
	weight.resize(N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			neighbor[i].push_back(0);
		}
	}
	for (int i = 0; i < M; i++) {
		int ai, bi;
		cin >> ai >> bi;
		neighbor[ai][bi] = 1;
	}

	//finish.clear();
	for (int i = 0; i < N; ++i) {
		DFS1(i);
	}

	visit.clear();
	visit.resize(N, 0);
	for (int i = N - 1; i >= 0; --i) {
		DFS2(finish[i], finish[i]);
		pcount++;
	}
	int check[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = 0;
		}
	}
	vector<int> in(N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			/*if(!new_[scc[neighbor[i]]][scc[neighbor[i][j]]]){
				new_[scc[neighbor[i]]].push_back(scc[neighbor[i][j]]);
				in[scc[neighbor[i][j]]]++;

			}*/
			if (neighbor[i][j]) {
				if (scc_n[i] != scc_n[j]) {
					if (check[scc_n[i]][scc_n[j]] == 0) {
						check[scc_n[i]][scc_n[j]] = 1;
						in[scc_n[j]]++;
						//cout << "ij " << scc_n[i] << " " << scc_n[j] << endl;
					}
				}
			}
		}
	}
	vector<int> ans;
	ans.resize(N, 0);
	visit.clear();
	visit.resize(N, 0);
	queue<int> q;
	for (auto it = scc_p.begin(); it != scc_p.end(); it++) {
		if (in[*it] == 0) {
			q.push(*it);
		}
	}
	while (!q.empty()) {

		int current = q.front();
		q.pop();
		visit[current] = 1;
		//cout << "C: " << current << endl;
		if (ans[current] < weight[current]) {
			ans[current] = weight[current];
		}
		for (int j = 0; j < N; j++) {
			if (check[current][j]) {
				check[current][j] = 0;
				int next = j;
				q.push(next);
				//if (!visit[next]) {
					//cout << "ans1: " << ans[next] << endl;
				if (ans[next] < ans[current] + weight[next]) {
					ans[next] = ans[current] + weight[next];
					//cout << "ans2: " << ans[next] << endl;
				}
			}



		}
	}
	cout << *max_element(ans.begin(), ans.end());
}
