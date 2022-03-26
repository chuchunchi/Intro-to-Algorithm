#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	map <int,int> us;
	int N , M;
	
	cin >> N >> M;
	for(int i=0;i<N;i++){
		int ai;
		cin >> ai;
		us.insert(make_pair(ai,i));
	}
	for(int i=0;i<M;i++){
		int qi;
		cin >> qi;
		map <int,int>::iterator f = us.find(qi);
		if(f==us.end()){
			cout << -1 << '\n';
		}
		else{
			cout << f->second << '\n';
		}
	}
}
