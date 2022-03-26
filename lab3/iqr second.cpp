#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int num;
	multiset<double> ms;
	multiset<double>::iterator q1first,q1last,q3first,q3last;
	int state=0,n=0;
	while(cin>>num){
		cout<< "cdfvgfd" << endl;
		(state>=3)?state=0,n++:state=state+1;
		if(num==0){
			break;
		}
		ms.insert(num);
		if(ms.size()==1){//reset
			q1first = next(ms.begin(),n-1);
			q1last = next(q1first);
			q3first = next(ms.begin(),n*3-1);
			q3last = next(q3first);
			cout << 0 << "\n";
			continue;
		}
		switch(state){
			case 0:
				q1last++;
				q3last++;
				break;
			case 1:
				q3first++;
				q3last++;
				break;
			case 2:
				q1first++;
				q3first++;
				break;
			case 3:
				q3first++;
				q3last++;
				break;
		}
		double q1 = (*q1first + *q1last)/2;
		double q3 = (*q3first + *q3last)/2;
		cout << q3-q1 << "\n";
	}
	cout << "3?";
}
