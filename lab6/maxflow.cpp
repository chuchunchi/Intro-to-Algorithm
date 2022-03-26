#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<long long int> > R;
vector<int> parent;
int N;
bool bfs() {
	queue<int> q;
	vector<int> visit(N + 2, 0);
	q.push(0);
	visit[0] = 1;
	parent[0] = -1;
	
	while (!q.empty()) {
		
		int current = q.front();
		q.pop();
		for (int i = 0; i < N + 2; i++) {
			if (R[current][i] > 0 && visit[i] == 0) {
				if (i == N + 1) {
					parent[i] = current;
					return 1;
				}
				q.push(i);
				parent[i] = current;
				visit[i] = 1;
			}
		}
	}
	return 0;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> N;
	vector<vector<long long int> > G;
	G.resize(N + 2);
	R.resize(N + 2);
	parent.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			G[i].push_back(0);
			R[i].push_back(0);
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> G[0][i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> G[i][N+1];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		G[a][b] += w;
		G[b][a] += w;
	}
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			R[i][j] = G[i][j];
		}
	}
	long long int maxflow = 0;
	while (bfs()) {
		int v, pare;
		long long int minflow = 1e10;
		for (v = N + 1; v != 0;) {
			pare = parent[v];
			if (R[pare][v] < minflow) {
				minflow = R[pare][v];
			}
			v = pare;
		}

		for (v = N + 1; v != 0;) {
			pare = parent[v];
			R[pare][v] -= minflow;
			R[v][pare] += minflow;
			v = pare;
		}
		maxflow += minflow;
	}
	cout << maxflow;
}
