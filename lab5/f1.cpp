#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
long long int N;
vector<int> rootvec;
vector<vector<pair<int,int> > > neighbor;
vector<int> visit;
vector<long long int> oneside;
multimap<pair<long long int, long long int>, long long int> edgesinverse;
vector<long long int> upedgeW;
int traversal(int root) {
	int total = 0;
	if (neighbor[root].size() == 1 && visit[root]==1) {
		oneside[root] = 1;
		return 1;
	}
	visit[root] = 1;
	for (int i = 0; i < neighbor[root].size(); i++) {
		multimap<pair<long long int, long long int>, long long int>::iterator it;
		
		if (visit[neighbor[root][i].first] == 0) {
			upedgeW[neighbor[root][i].first] = neighbor[root][i].second;
			visit[neighbor[root][i].first] = 1;
			total += traversal(neighbor[root][i].first);

		}
	}
	total++;
	oneside[root] = total;
	return total;
}

int root(int i) {
	int root = i;
	while (rootvec[root] != root) {
		rootvec[root] = rootvec[rootvec[root]];
		root = rootvec[root];
	}
	return root;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long int M;
	cin >> N >> M;
	visit.resize(N, 0);
	oneside.resize(N, 0);
	multimap<long long int, pair<long long int, long long int>> edges;
	vector<int> sizevec;
	for (int i = 0; i < N; i++) {
		rootvec.push_back(i);
		sizevec.push_back(1);
	}
	long long int xi, yi;
	long long int ci;
	for (int i = 0; i < M; i++) {
		cin >> xi >> yi >> ci;
		edges.insert(make_pair(ci, make_pair(--xi, --yi)));
		
	}
	long long int cablelength = 0;
	//vector<vector<int> > neighbor;
	neighbor.resize(N);
	upedgeW.resize(N, 0);
	for (auto it = edges.begin(); it != edges.end(); it++) {
		xi = it->second.first;
		yi = it->second.second;
		ci = it->first;
		int xroot = root(xi);
		int yroot = root(yi);
		if (xroot != yroot) {
			if (sizevec[xroot] >= sizevec[yroot]) {
				rootvec[yroot] = xroot;
				sizevec[xroot] += sizevec[yroot];
			}
			else {
				rootvec[xroot] = yroot;
				sizevec[yroot] += sizevec[xroot];
			}
			(cablelength += ci) %= 1000000007;
			neighbor[xi].push_back(make_pair(yi, ci));
			neighbor[yi].push_back(make_pair(xi, ci));
			edgesinverse.insert(make_pair(make_pair(xi, yi), ci));
		}
	}
	int finalroot = root(1);
	//cout << finalroot << endl;
	for (int i = 0; i < N; i++) {
		if (root(i) != finalroot) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << (cablelength * 2) % 1000000007 << '\n';

	traversal(finalroot);


	long long int total = 0;
	for (int i = 0; i < N; i++) {
		//cout << upedgeW[i] << endl;
		long long int secondside = N - oneside[i];
		long long int traveltime = (2 * oneside[i] * secondside) % 1000000007;
		long long int sendcost = (upedgeW[i] * traveltime) % 1000000007;
		(total += sendcost) %= 1000000007;
	}
	cout << total % 1000000007 << '\n';
}


