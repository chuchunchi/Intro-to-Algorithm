#include <iostream>
#include <set>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);     
	
	int L,N,p;
	int i,j;
	cin >> L >> N;
	set<int> jubutsu;
	set<int>::iterator it;
	jubutsu.insert(0);
	jubutsu.insert(L);
	
	set<int> shikigami;
	for(i=0;i<N;i++){
		cin >> p;
		jubutsu.insert(p);
		for(it=jubutsu.begin();it!=jubutsu.end();it++){
			pair<set<int>::const_iterator,set<int>::const_iterator> ret;
			ret = jubutsu.equal_range(*it);
			shikigami.insert(((*ret.first+*ret.second)/2)-*ret.first);
		}
		cout << *(--shikigami.end()) << '\n';
		shikigami.clear();
	}
}
