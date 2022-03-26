#include <iostream>
#include <queue>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	queue<pair<int,int>> q,q2;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		pair<int,int> p;
		cin >> p.first >> p.second;
		q.push(p);
	}
	
    do{
		int size = q.size();
	    for (int i = 0; i < size; i++) {
	    	
	        cout << q.front().first << "\n";
	        q.front().second--;
	        if(q.front().second>0){
	        	q2.push(q.front());	
			}
	        
	        q.pop();
	    }
	    swap(q,q2);
    	
	}while(!q.empty());
}
