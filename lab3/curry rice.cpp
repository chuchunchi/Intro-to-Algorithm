#include <iostream>
#include <vector>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int k=0;k<T;k++){ //2
		int N;
		cin >> N;
		long long int Ctotal[8]={0};
		long long int should_return[N];
		for(int j=0;j<N;j++){ //4
			long long int C[8];
			for(int i=0;i<8;i++){
				cin >> C[i];
				if(i){
					if(C[i]){
						Ctotal[i]+=C[i];
					}
				}
			}
			should_return[j] = 1000*C[1]+500*C[2]+100*C[3]+50*C[4]+10*C[5]+5*C[6]+C[7]-C[0];
		}
		int no = 0;
		for(int j=0;j<N;j++){
			
			if(should_return[j]){
				
				Ctotal[1] -= (should_return[j]/1000);
				should_return[j] %= 1000;
				if(Ctotal[1]<0){
					should_return[j]+=(-Ctotal[1])*1000;
					Ctotal[1] = 0;
				}
				Ctotal[2] -= (should_return[j]/500);
				should_return[j] %= 500;
				if(Ctotal[2]<0){
					should_return[j]+=(-Ctotal[2])*500;
					Ctotal[2] = 0;
				}
				Ctotal[3] -= (should_return[j]/100);
				should_return[j] %= 100;
				if(Ctotal[3]<0){
					should_return[j]+=(-Ctotal[3])*100;
					Ctotal[3] = 0;
				}
				Ctotal[4] -= (should_return[j]/50);
				should_return[j] %= 50;
				if(Ctotal[4]<0){
					should_return[j]+=(-Ctotal[4])*50;
					Ctotal[4] = 0;
				}
				Ctotal[5] -= (should_return[j]/10);
				should_return[j] %= 10;
				if(Ctotal[5]<0){
					should_return[j]+=(-Ctotal[5])*10;
					Ctotal[5] = 0;
				}
				Ctotal[6] -= (should_return[j]/5);
				should_return[j] %= 5;
				if(Ctotal[6]<0){
					should_return[j]+=(-Ctotal[6])*5;
					Ctotal[6] = 0;
				}
				Ctotal[7] -= (should_return[j]/1);
				if(Ctotal[7]<0){
					no = 1;
					cout << "No" << '\n';
					break;
				}
			}
			
		}
		if(no==0){
			cout << "Yes" << '\n';
			continue;
		}
		
	}
} 
