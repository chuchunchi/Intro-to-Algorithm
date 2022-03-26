#include <iostream>
#include <vector>
using namespace std;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<long long int> > weight;
	weight.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			weight[i].push_back(0);
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		long long int w;
		cin >> a >> b >> w;
		if (a != b) {
			if ((weight[a][b] != 0 && weight[a][b] > w) || weight[a][b] == 0) {
				weight[a][b] = w;
			}
		}
		
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (weight[i][k] != 0 && weight[k][j] != 0) {
					if (weight[i][j] > weight[i][k] + weight[k][j]|| weight[i][j] == 0) {
						weight[i][j] = weight[i][k] + weight[k][j];
						//cout << "w: " << i << " " << j << " " << weight[i][j] << endl;
					}
				}
				
			}
		}
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int F, T;
		cin >> F >> T;
		if (weight[F][T] == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << weight[F][T] << '\n';
		}
	}
}