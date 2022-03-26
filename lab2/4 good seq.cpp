#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	int opers = 0; //output
	cin >> N;
	vector<int> a;
	for(int i=0;i<N;i++){
		int ai;
		cin >> ai;
		a.push_back(ai);
	}
	while(1){
		vector<int> subv1(a.begin(), a.begin()+(N-1)/2+1);
		vector<int> subv2(a.begin()+((N-1)/2+1), a.end());
		
		int x1 = (N-1)/2+1;
		int x2 = N/2;
		int total1= 0, total2=0;
		//cout << "1:::: ";
		for(int i=0;i<x1;i++){
			//cout << subv1[i] << " " ;
			total1+= subv1[i];
		}
		//cout << endl;
		//cout << "2:::: ";
		int avg1 = round(total1/x1);
		for(int i=0;i<x2;i++){
			//cout << subv2[i] << " ";
			total2+= subv2[i];
		}
		//cout << endl;
		int avg2 = round(total2/x2);
		
		int sum1= 0, sum2=0;
		for(int i=0;i<x1;i++){
			sum1 += abs(subv1[i]-avg1);
		}
		for(int i=0;i<x2;i++){
			sum2 += abs(subv2[i]-avg2);
		}
		if(sum1>=sum2){
			a = subv1;
			N = subv1.size();
			opers += sum2;
		}
		else if(sum1<sum2){
			a = subv2;
			N = subv2.size();
			opers += sum1;
		}
		
		if(subv1.size()<=2){
			break;
		}
	}
	cout << opers ; 
	
	
	
}
