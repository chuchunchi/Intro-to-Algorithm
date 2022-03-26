#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int M;
vector<int> games,costs;
int numofgame(int scientist,int start, vector<int> &memos){
	int maxgame = 0;
	if(memos[scientist-1]>=0){
		return memos[scientist-1];
	}
	for(int i=start;i<M;i++){
		if(scientist-costs[i]>0){
			if(games[i]+numofgame(scientist-costs[i],i+1,memos)>=maxgame){
				maxgame = games[i]+numofgame(scientist-costs[i],i+1,memos);
			}
			
		}
		
		else if(scientist-costs[i]==0){
			memos[scientist-1] = games[i];
			//return memos[scientist-1];
			////////////////////////////
			//跑完一次之後就不跑了直接return？
			//不一定全部花完？如果是大於零哩？ 
		}
	}
	memos[scientist-1] = maxgame;
	return memos[scientist-1];

}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,scientist;
	cin >> N >> M >> scientist;
	vector<int> schedule;
	schedule.resize(N);
	for(int i=0;i<N;i++){
		int yi;
		cin >> yi;
		schedule[i] = yi;
	}
	sort(schedule.begin(),schedule.end());
	
	
	for(int i=0;i<M;i++){
		int beginy,endy,virus;
		cin >> beginy >> endy >> virus;
		auto beginit = lower_bound(schedule.begin(),schedule.end(),beginy);
		auto endit = upper_bound(schedule.begin(),schedule.end(),endy);
		int game = endit-beginit;
		games.push_back(game);
		cout << "g" << game << endl;
		costs.push_back(virus);
	}
	vector<int> memos(scientist,-1);
	cout << numofgame(scientist,0,memos);
}
