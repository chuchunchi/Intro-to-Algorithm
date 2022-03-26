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
	set<int>::iterator it,lower,upper;
	jubutsu.insert(0);
	jubutsu.insert(L);
	
	set<int> distance;
	distance.insert(L-0);
	for(i=0;i<N;i++){
		cin >> p;
		cout << "do anything!!!!!!!" << '\n';
		jubutsu.insert(p);
		it = jubutsu.find(p);
		lower = prev(it);
		upper = next(it);
		cout << "do something!!!!!!!" << '\n';
		cout << "it: " << *it << '\n';
		cout << "upper: " << *upper << " lower: " << *lower << '\n';
		distance.erase(*upper-*lower);
		distance.insert(*upper-*it);
		distance.insert(*it-*lower);		
		cout << (*distance.begin())/2 << '\n';
	}
}
