#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
	    int name;
	    
	    Node* next;
	    vector<int> date;
};

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);     
	
	//Q indicates the number of instructions.
	int q;
	int instruc; //either 1 or 2
	cin >> q;
	vector<Node> merch;
	vector<Node>::iterator it;
	
	for(int i=0;i<q;i++){
		cin >> instruc;
		//cout<<">>>>>>>>>"<< endl;
		if(instruc==1){
			int a,x;
			cin >> a >> x;
			
			
			for(it=merch.begin();it!=merch.end();it++){
				if(it->name==a){
					it->date.push_back(x);
					//cout << "find name in step one" << '\n';
					//cout << it->date.front() << '\n';
					break;
				}
			}
			if(it==merch.end()){
				//cout << "cant find name in step one" << '\n';
				Node* new_node = new Node();
				new_node->name = a;
				new_node->date.push_back(x);
				merch.push_back(*new_node);
			}
			//cout<< "<<<<<<<" << endl;
			//continue;
		}
		else if(instruc==2){
			int b;
			cin >> b;
			//cout << "====================";
			for(it=merch.begin();it!=merch.end();it++){
				if(it->name==b){
					if(it->date.empty()){
						cout << -1 << '\n';
						break;
					}
					vector<int>::iterator min = min_element(it->date.begin(), it->date.end());
					cout << *min << '\n';
    				it->date.erase(min);
					//cout << "find name in step two" << '\n';
					//sort(it->date.begin(), it->date.end(), greater<int>());
					//cout << "it's first" << it->date.front() << endl;
					//cout << it->date.back() << '\n';
					//it->date.pop_back();
					//cout << "sort n pop success" << '\n';
					break;
				}
			}
			if(it==merch.end()){
				//cout << "cant find name in step two" << '\n';
				cout << -1 << '\n';	
			}
		
		}
	}
}
