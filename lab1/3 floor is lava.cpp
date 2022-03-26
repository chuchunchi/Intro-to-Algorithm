#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,k;
	cin >> N >> k;
	double lb=0;
	double hb=0;
	vector<int> c,p;
	for(int i=0;i<N;i++){
		int ci,pi;
		cin >> ci >> pi;
		c.push_back(ci);
		p.push_back(pi);
		if(ci/(pi+1)>hb){
			hb = ci/(pi+1);
		}
	}
	double avg;
	while((hb-lb)>(0.000001)){
		avg = (lb+hb)/2;
		int person=0;
		for(int i=0;i<N;i++){
			if((c[i]/avg)-p[i]>=0){
				person += ((c[i]/avg)-p[i]);
			}
		}
		if(person>=k){
			lb = avg;
		}
		else if(person < k){
			hb = avg;
		}
	}
	cout << fixed << setprecision(7) << avg;
}
