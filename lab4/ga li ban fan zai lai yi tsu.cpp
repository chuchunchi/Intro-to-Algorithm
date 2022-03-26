#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector <int> currency;
int N;


int numofcoin(int change, vector<int> &memos){
	int mincoins = change; //max:all one dollars
	if(memos[change-1]>=0){
		return memos[change-1];
	}
	for(int i=N-1;i>=0;i--){
		if(change-currency[i]>0){
			if(1+numofcoin(change-currency[i],memos)<=mincoins){
				mincoins = 1+numofcoin(change-currency[i],memos);
				//cout << mincoins << endl;
			}
		}
		else if(change-currency[i]==0){
			memos[change-1] = 1;
			return 1;
		}
	}
	memos[change-1] = mincoins;
	return memos[change-1];
}


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int Q;
	cin >> N;
	
	for(int i=0;i<N;i++){
		int ci;
		cin >> ci;
		currency.push_back(ci);
	}
	cin >> Q;
	vector <long long int> change;
	change.resize(Q);
	for(int j=0;j<Q;j++){
		long long int B;
		cin >> B;
		vector <long long int> paid;
		change[j]=B;
		for(int i=0;i<N;i++){
			long long int pi;
			cin >> pi;
			paid.push_back(pi);
			change[j] -= (paid[i]*currency[i]);
		}
		change[j]*=(-1);
	}
	sort(currency.begin(),currency.end(),greater<int>());
	vector<int> memos(*max_element(change.begin(),change.end()),-1);
	
	for(int j=0;j<Q;j++){
		//cout << "change " << change[j] << endl;
		if(change[j]==0){
			cout << 0 << '\n';
			continue;
		}
		cout << numofcoin(change[j],memos) << '\n';
	}
	/*for(int i=0;i<memos.size();i++){
		cout << memos[i] << " ";
	}*/
} 
/*5
100 50 10 5 1
1
63 1 0 0 0 0*/
