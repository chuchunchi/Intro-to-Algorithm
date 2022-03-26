#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int N;
vector<int> L;
int ceil(int a,int l, int r) {
	
	while (r-l>1) {
		int m = (r + l) / 2;
		if (a == L[r]) {
			break;
		}
		if (a <= L[m]) {
			r = m;
		}
		else if (a > L[m]) {
			l = m;
		}
	}
	return r;
}

vector<int> LISL(vector<int> v) {
	L.clear();
	L.push_back(v[0]);
	vector<int> ans;
	ans.resize(N);
	ans[0] = 1;

	for (int i = 1; i < N; i++) {
		if (v[i] < L[0]) {
			L[0] = v[i];
			//cout << "1: " << i << endl;
		}
		else if (v[i] > L[L.size()-1]) {
			L.push_back(v[i]);
			//cout << "2: " << i << endl;
		}
		else {
			int r = ceil(v[i], 0, L.size()-1);
			L[r] = v[i];
			//cout << "3: " << i << endl;
		}
		ans[i] = L.size();
	}
	return ans;
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<int> v;
	vector<int> inv;
	inv.resize(N, 0);
	vector<int> increase1, increase2, decrease1, decrease2;
	for (int i = 0; i < N; i++) {
		int hi;
		cin >> hi;
		v.push_back(hi);
		inv[N - 1 - i] = hi;
	}
	increase1 = LISL(v);
	increase2 = LISL(inv);
	
	for (int i = 0; i < N; i++) {
		v[i] *= (-1);
		inv[i] *= (-1);
	}
	decrease1 = LISL(v);
	decrease2 = LISL(inv);
	for (int i = 0; i < N; i++) {
		cout << decrease1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << decrease2[i] << " ";
	}
	int maxi = 0;
	for (int i = 0; i < N; i++) {

		if (increase1[i] + increase2[N-1-i] - 1 > maxi) {
			maxi = increase1[i] + increase2[N-1-i] - 1;
		}
		if (decrease1[i] + decrease2[N-1-i] - 1 > maxi) {
			maxi = decrease1[i] + decrease2[N-1-i] - 1;
		}
	}
	cout << maxi;
}
