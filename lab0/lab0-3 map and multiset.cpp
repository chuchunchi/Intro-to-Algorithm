#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);     
	
	//Q indicates the number of instructions.
	int q;
	int instruc; //either 1 or 2
	cin >> q;
	map<int, multiset<int>> merch;
	map<int, multiset<int>>::iterator it;
	
	for(int i=0;i<q;i++){
		cin >> instruc;
		//cout<<">>>>>>>>>"<< endl;
		if(instruc==1){
			int a,x;
			cin >> a >> x;
			
			it = merch.find(a);
			
			/*for(it=merch.begin();it!=merch.end();it++){
				if(it->first==a){
					it->second.push(x);
					//cout << "find name in step one" << '\n';
					break;
				}
			}*/
			if(it==merch.end()){
				//cout << "cant find name in step one" << '\n';
				multiset<int>  date;
				date.insert(x);
				merch[a] = date;
				date.clear();
			}
			else{
				it->second.insert(x);
			}
			//cout<< "<<<<<<<" << endl;
			//continue;
		}
		else if(instruc==2){
			int b;
			cin >> b;
			it = merch.find(b);
			//cout << "====================";
			/*for(it=merch.begin();it!=merch.end();it++){
				if(it->first==b){
					if(it->second.empty()){
						cout << -1 << '\n';
						break;
					}
					cout << it->second.top() << '\n';
					it->second.pop();
					break;
				}
			}*/
			if(it==merch.end()){
				//cout << "cant find name in step two" << '\n';
				cout << -1 << '\n';	
			}
			else{
				if(it->second.empty()){
					cout << -1 << '\n';
					continue;
				}
				cout << *it->second.begin() << '\n';
				it->second.erase(it->second.begin());
			}
		
		}
	}
} 
