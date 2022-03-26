#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;
long long int N;
vector<long long int> dijkstra(vector<vector < pair<int, long long int> > > weight, int flag) {
	vector<long long int> s2d;
	s2d.resize(N + 1);
	priority_queue< pair<long long, long long>, vector< pair<long long, long long> >, greater< pair<long long, long long> > > q;
	if (flag == 0) {
		q.push(make_pair(0, 1));
		s2d[1] = 0;
		for (long long int i = 2; i <= N; i++) {
			s2d[i] = 1e15;
		}
	}
	if (flag == 1) {
		q.push(make_pair(0, N));
		s2d[N] = 0;
		for (long long int i = 1; i < N; i++) {
			s2d[i] = 1e15;
		}
	}
	
	vector<int> visit;
	visit.resize(N + 1, 0);
	while (!q.empty()) {
		long long int current = q.top().second;
		q.pop();
		visit[current] = 1;
		for (long long int i = 0; i < weight[current].size(); i++) {
			long long int neighbor = weight[current][i].first;
			long long int edge = weight[current][i].second;
			if (visit[neighbor] == 0) {
				if (s2d[current] + edge < s2d[neighbor]) {
					s2d[neighbor] = s2d[current] + edge;
					//cout <<  "eee: " << neighbor  << " " << s2d[neighbor] << '\n';
					q.push(make_pair(s2d[neighbor], neighbor));
				}
			}
		}
	}
	return s2d;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long int M;
	cin >> N >> M;
	vector<long long int> s2d;
	vector<long long int> d2s;
	vector<vector< pair<int, long long int> > > weight;
	vector<vector< pair<int, long long int> > > weightinv;
	weight.resize(N + 1);
	weightinv.resize(N + 1);

	//map< pair<int, int> , int> edges;
	//map< pair<int, int> , int>::iterator it;
	vector<pair<pair<long long int, long long int>, long long int> > edges;
	vector<pair<pair<long long int, long long int>, long long int> >::iterator it;
	for (long long int i = 0; i < M; i++) {
		long long int a, b;
		long long int w;
		cin >> a >> b >> w;
		weight[a].push_back(make_pair(b, w));
		weightinv[b].push_back(make_pair(a, w));
		edges.push_back(make_pair(make_pair(a, b),w));
	}
	s2d = dijkstra(weight,0);
	d2s = dijkstra(weightinv,1);
	long long int sp = s2d[N];
	for (it = edges.begin(); it != edges.end(); it++) {
		long long int a = it->first.first;
		long long int b = it->first.second;
		long long int w = it->second;
		//cout << "a: " << s2d[a] << " b: " << d2s[b] << " w: " << w << " sp: " << sp << endl;
		long long int ans = s2d[a] + d2s[b] + w - sp;
		if (s2d[a] == 1e15|| d2s[b] == 1e15|| ans>w) {
			cout << -1 << '\n';
			continue;
		}
		else {
			cout << ans << '\n';
		}
	}
}
