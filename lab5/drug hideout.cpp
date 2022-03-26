#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int N, S;
vector<vector<int> > neighbor;
vector<int> ispolice;

bool bfssssp(int source) {
	queue<int> q;
	//vector<int> hops;
	//hops.resize(N + 1, 0);
	vector<int> visit;
	visit.resize(N + 1, 0);
	q.push(source);
	visit[source] = 1;
	while (!q.empty()) {
		int qfront = q.front();
		q.pop();
		for (int i = 0; i < neighbor[qfront].size(); i++) {
			if (visit[neighbor[qfront][i]] == 0) {
				q.push(neighbor[qfront][i]);
				//hops[neighbor[qfront][i]] = hops[qfront] + 1;
				visit[neighbor[qfront][i]] = 1;
				if (neighbor[qfront][i] == S && ispolice[neighbor[qfront][i]] == 0) {
					cout << "Yes" << '\n';
					return 1;
				}
				else if (ispolice[neighbor[qfront][i]] == 1) {
					return 0;
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int M;
		cin >> N >> M >> S;
		//vector<vector<int> > neighbor;
		neighbor.clear();
		neighbor.resize(N + 1);
		for (int m = 0; m < M; m++) {
			int ui, vi;
			cin >> ui >> vi;
			neighbor[ui].push_back(vi);
			neighbor[vi].push_back(ui);
		}

		int X, Y;
		cin >> X;
		ispolice.clear();
		ispolice.resize(N + 1, 0);
		for (int x = 0; x < X; x++) {
			int ai;
			cin >> ai;
			ispolice[ai] = 1;
		}
		cin >> Y;
		int y;
		vector<int> B;
		for (y = 0; y < Y; y++) {
			int bi;
			cin >> bi;
			B.push_back(bi);
			
		}
		for (y = 0; y < Y; y++) {
			int bi = B[y];
			if (bfssssp(bi)) {
				break;
			}
		}
		if (y == Y) {
			cout << "No" << '\n';
		}
	}
}
