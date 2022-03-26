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
	while(cin>>num){
		if(num==0){
			break;
		}
		ms.insert(num);
		int mssize = ms.size();
		if(mssize==1){
			cout << 0 << "\n";
			continue;
		}
		int state = mssize%4;
		int n = mssize/4;
		switch(state){
			case 0:
				q1first = next(ms.begin(),n-1);
				q1last = next(q1first);
				q3first = next(ms.begin(),n*3-1);
				q3last = next(q3first);
				break;
			case 1:
				q1first = next(ms.begin(),n-1);
				q1last = next(q1first);
				q3first = next(ms.begin(),n*3);
				q3last = next(q3first);
				break;
			case 2:
				q1first = next(ms.begin(),n);
				q1last = q1first;
				q3first = next(ms.begin(),n*3+1);
				q3last = q3first;
				break;
			case 3:
				q1first = next(ms.begin(),n);
				q1last = q1first;
				q3first = next(ms.begin(),n*3+2);
				q3last = q3first;
				break;
		}
		double q1 = (*q1first + *q1last)/2;
		double q3 = (*q3first + *q3last)/2;
		cout << q3-q1 << "\n";
	}
}
