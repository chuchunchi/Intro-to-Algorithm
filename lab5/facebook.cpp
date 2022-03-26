#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

vector<int> rootvec;

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
	int N, M, Q;
	cin >> N >> M >> Q;

	vector<int> sizevec;
	for (int i = 0; i < N; i++) {
		rootvec.push_back(i);
		sizevec.push_back(1);
	}
	set<pair<int, int> > edges;
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges.insert(make_pair(v1, v2));
	}
	stack<pair<char, pair<int, int> > > memos;
	for (int i = 0; i < Q; i++) {
		char c;
		int v1, v2;
		cin >> c >> v1 >> v2;
		memos.push(make_pair(c, make_pair(v1, v2)));
		if (c == 'U') {
			auto it = edges.find(make_pair(v1, v2));
			if (it != edges.end()) {
				edges.erase(it);
			}
			else {
				it = edges.find(make_pair(v2, v1));
				edges.erase(it);
			}
		}
		
	}
	for (auto it = edges.begin(); it != edges.end(); it++) {
		int v1 = it->first;
		int v2 = it->second;
		int v1root = root(v1);
		int v2root = root(v2);
		if (sizevec[v1root] >= sizevec[v2root]) {
			rootvec[v2root] = v1root;
			sizevec[v1root] += sizevec[v2root];
		}
		else {
			rootvec[v1root] = v2root;
			sizevec[v2root] += sizevec[v1root];
		}
	}
	stack<int> ans;
	while (!memos.empty()) {
		char c = memos.top().first;
		int v1 = memos.top().second.first;
		int v2 = memos.top().second.second;
		memos.pop();
		if (c == 'A') {//find
			if (root(v1) == root(v2)) {
				ans.push(1);
			}
			else {
				ans.push(0);
			}
		}
		else if (c == 'U') {//union
			int v1root = root(v1);
			int v2root = root(v2);
			if (sizevec[v1root] >= sizevec[v2root]) {
				rootvec[v2root] = v1root;
				sizevec[v1root] += sizevec[v2root];
			}
			else {
				rootvec[v1root] = v2root;
				sizevec[v2root] += sizevec[v1root];
			}
		}
	}
	while (!ans.empty()) {
		if (ans.top() == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		ans.pop();
	}
}
