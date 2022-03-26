#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	vector<pair<double,double>> rates;
	vector<pair<double,double>>::reverse_iterator it;
	int N,M;
	cin >> N;
	for(int i=0;i<N;i++){
		double a,r;
		cin >> a >> r;
		rates.push_back(make_pair((a-1),r));
	}
	cin >> M;
	for(int i=0;i<M;i++){
		double tax=0;
		double income;
		cin >> income;
		for(it=rates.rbegin();it!=rates.rend();it++){
			int tmp;
			if(income>=(*it).first){
				tmp=income-(*it).first;
				tax+=tmp*((*it).second);
				income-=tmp;
			}
			if(income==0){
				break;
			}
		}
		cout << fixed << setprecision(7) << tax << '\n';
	}
}
