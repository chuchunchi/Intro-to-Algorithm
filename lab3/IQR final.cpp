#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
#include <iomanip>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int num;
	multiset<double> ms;
	multiset<double>::iterator q1first,q1last,q3first,q3last;
	int state=0,n=0;
	while(cin>>num){
		(state>=3)?state=0,n++:state=state+1;
		if(num==0){
			break;
		}
		ms.insert(num);
		if(ms.size()==1){
			cout << 0 << '\n';
			continue;
		}
		else if(ms.size()==2){
			q1first = ms.begin();
			q1last = q1first;
			q3first = --ms.end();
			q3last = q3first;
			//cout << state << " " << n << endl;
			//cout << distance(ms.begin(),q1first) << " " << distance(ms.begin(),q1last) << " " << distance(ms.begin(),q3first) << " " << distance(ms.begin(),q3last) << endl;
		}
		else{
			switch(state){
				case 0:
					if(num<*q1first){
						q1first--;
						q3first--;
					}
					else if(*q1first<=num&&num<*q3first){
						q1last++;
						q3first--;
					}
					else if(*q3last<=num){
						q1last++;
						q3last++;
					}
					//cout << state << " " << n << endl;
					//cout << distance(ms.begin(),q1first) << " " << distance(ms.begin(),q1last) << " " << distance(ms.begin(),q3first) << " " << distance(ms.begin(),q3last) << endl;
					break;
				case 1:
					if(num<*q1first){
						q1first--;
						q1last--;
					}
					else if(*q1first<=num&&num<*q1last){
						q1last--;
					}
					else if(*q3first<=num&&num<*q3last){
						q3first++;
					}
					else if(*q3last<=num){
						q3first++;
						q3last++;
					}
					//cout << state << " " << n << endl;
					//cout << distance(ms.begin(),q1first) << " " << distance(ms.begin(),q1last) << " " << distance(ms.begin(),q3first) << " " << distance(ms.begin(),q3last) << endl;
					break;
				case 2:
					if(num<*q1first){
						q1last--;
						q3last--;
					}
					else if(*q1first<=num&&num<*q1last){
						q1first++;
						q1last--;
						q3last--;
					}
					else if(*q1last<=num && num <*q3first){
						q1first++;
						q3last--;
					}
					else if(*q3first<=num&&num<*q3last){
						q1first++;
						q3first++;
						q3last--;
					}
					else if(*q3last<=num){
						q1first++;
						q3first++;
					}
					//cout << state << " " << n << endl;
					//cout << distance(ms.begin(),q1first) << " " << distance(ms.begin(),q1last) << " " << distance(ms.begin(),q3first) << " " << distance(ms.begin(),q3last) << endl;
					break;
				case 3:
					if(num<*q1first){
						q1first--;
						q1last--;
					}
					else if(*q3last<=num){
						q3first++;
						q3last++;
					}
					//cout << state << " " << n << endl;
					//cout << distance(ms.begin(),q1first) << " " << distance(ms.begin(),q1last) << " " << distance(ms.begin(),q3first) << " " << distance(ms.begin(),q3last) << endl;
					break;
			}
		}
		double q1 = (*q1first + *q1last)/2;
		double q3 = (*q3first + *q3last)/2;
		if(int(q3-q1)==q3-q1){
			cout << int(q3-q1) << '\n';
		}
		else{
			cout << fixed << setprecision(1) << q3-q1 << '\n';
		}
	}
}
