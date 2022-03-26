#include <iostream>
#include <map>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,T,total=0;
	cin >> N >> T;
	map<int,int> m;
	map<int,int>::iterator it,i,j;
	for(int i=0;i<N;i++){
		int w;
		cin >> w;
		it = m.find(w);
		if(it == m.end()){
			m.insert(make_pair(w,0));
		}
		else{
			it->second++;
		}
	}
	int count = 0,count3 = 0;
	for(i=m.begin();i!=m.end();i++){
		if(i->second==1){
			int want = T-(i->first)*2;
			it = m.find(want);
			if(it!=m.end()&&it!=i){
				count++;
			}
		}
		else if(i->second>1){
			if(i->first *3 == T){
				count++;
			}
		}
		if(i==prev(m.end())){
			break;
		}
		for(j=next(i);j!=m.end();j++){
			int want = T-(i->first+j->first);
			it = m.find(want);
		    if(it != m.end()&& it !=i && it !=j){
		        count3++;
		    }
		}
	}
	
	if(count+ count3/3){	
		cout << count+ count3/3;
	}
	else{
		cout << "FeiDooDoo_Zuo_Wei_Men";
	}
}
