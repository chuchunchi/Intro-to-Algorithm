#include <iostream>
#include <vector>

using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	//N indicates how many types of merchandise there are and QQ indicates the number of instructions.
	int n,q;
	int instruc;
	cin >> n >> q;
	vector<int> merch[n];
	
	for(int i=0;i<q;i++){
		cin >> instruc;
		if(instruc==1){
			int a,x;
			cin >> a >> x;
			merch[a].push_back(x);
		}
		else if(instruc==2){
			int b,y;
			cin >> b >> y;
			if(y>=merch[b].size()){
				cout << -1 << '\n';
			}
			else{
				cout << merch[b][y] << '\n';
			}
		
		}
	}
}
