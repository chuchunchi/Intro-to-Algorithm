#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M,scientist;
	cin >> N >> M >> scientist;
	vector<int> schedule;
	schedule.resize(N);
	for(int i=0;i<N;i++){
		int yi;
		cin >> yi;
		schedule[i] = yi;
	}
	sort(schedule.begin(),schedule.end());
	
	vector<int> games,costs;
	int yearinpan=0;
	for(int i=0;i<M;i++){
		int beginy,endy,virus;
		cin >> beginy >> endy >> virus;
		auto beginit = lower_bound(schedule.begin(),schedule.end(),beginy);
		auto endit = upper_bound(schedule.begin(),schedule.end(),endy);
		
		int game = endit-beginit;
		yearinpan+=game;
		games.push_back(game);
		costs.push_back(virus);
	}
	vector<int> memos(scientist+1,0);
	//cout << numofgame(scientist,0,memos);
	for(int i=0;i<M;i++){
		for(int j=scientist;j-costs[i]>=0;j--){
			memos[j] = max(memos[j],memos[j-costs[i]]+games[i]);
			
		}
	}
	
	cout << N-yearinpan+memos[scientist]; 
}
