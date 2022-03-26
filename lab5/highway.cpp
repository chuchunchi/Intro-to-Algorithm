#include <iostream>
#include <vector>
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
vector<int> frootvec;
int froot(int i) {
	int root = i;
	while (frootvec[root] != root) {
		frootvec[root] = frootvec[frootvec[root]];
		root = frootvec[root];
	}
	return root;
}

vector<int> srootvec;
int sroot(int i) {
	int root = i;
	while (srootvec[root] != root) {
		srootvec[root] = srootvec[srootvec[root]];
		root = srootvec[root];
	}
	return root;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		long double N, M, K, F, S;
		cin >> N >> M >> K >> F >> S;
		int fcount = 0, scount = 0;
		rootvec.clear();
		frootvec.clear();
		srootvec.clear();
		vector<pair<int, int> > fvec, svec;
		vector<int> sizevec, fsizevec, ssizevec;
		for (int i = 0; i < N; i++) {
			rootvec.push_back(i);
			sizevec.push_back(1);
			frootvec.push_back(i);
			fsizevec.push_back(1);
			srootvec.push_back(i);
			ssizevec.push_back(1);
		}
		for (int i = 0; i < M; i++) {
			int v1, v2;
			char c;
			cin >> v1 >> v2 >> c;
			if (c == 'F') {
				fcount++;
				fvec.push_back(make_pair(v1, v2));
			}
			if (c == 'S') {
				scount++;
				svec.push_back(make_pair(v1, v2));
			}
			int xroot = root(v1);
			int yroot = root(v2);
			if (xroot != yroot) {
				if (sizevec[xroot] >= sizevec[yroot]) {
					rootvec[yroot] = xroot;
					sizevec[xroot] += sizevec[yroot];
				}
				else {
					rootvec[xroot] = yroot;
					sizevec[yroot] += sizevec[xroot];
				}
			}
		}
		int rootzero = root(0);
		int ansshow = 0;
		for (int i = 1; i < N; i++) {
			if (root(i) != rootzero) {
				cout << "No" << '\n';
				ansshow = 1;
				break;
			}
		}
		if(ansshow==1){
			continue;
		}
		int fmax=0, smax=0, fmin, smin;
		for (int fi = 0; fi < fcount; fi++) {
			int v1, v2;
			v1 = fvec[fi].first;
			v2 = fvec[fi].second;
			int xroot = froot(v1);
			int yroot = froot(v2);

			if (xroot != yroot) {
				if (fsizevec[xroot] >= fsizevec[yroot]) {
					frootvec[yroot] = xroot;
					fsizevec[xroot] += fsizevec[yroot];
				}
				else {
					frootvec[xroot] = yroot;
					fsizevec[yroot] += fsizevec[xroot];
				}
				fmax++;
			}
		}
		if (fmax > N - 1) {
			fmax = N - 1;
		}
		for (int si = 0; si < scount; si++) {
			int v1, v2;
			v1 = svec[si].first;
			v2 = svec[si].second;
			int xroot = sroot(v1);
			int yroot = sroot(v2);
			if (xroot != yroot) {
				if (ssizevec[xroot] >= ssizevec[yroot]) {
					srootvec[yroot] = xroot;
					ssizevec[xroot] += ssizevec[yroot];
				}
				else {
					srootvec[xroot] = yroot;
					ssizevec[yroot] += ssizevec[xroot];
				}
				smax++;
			}
		}
		if (smax > N - 1) {
			smax = N - 1;
		}
		fmin = N - 1 - smax;
		smin = N - 1 - fmax;
		if(F!=S){
			long double fans = (K - (N - 1) * S) / (F - S);
		}
		else{
			if(F*(N-1)==K){
				cout << "Yes" << '\n';
				continue;
			}	
			else{
				cout << "No" << '\n';
				continue;
			}
		}
		double fans = (K - (N - 1) * S) / (F - S);
		if (fans == int(fans) && fmin <= fans && fans <= fmax && ansshow == 0) {
			cout << "Yes" << '\n';
			ansshow = 1;
		}
		if (ansshow == 0) {
			cout << "No" << '\n';
		}
	}
}
