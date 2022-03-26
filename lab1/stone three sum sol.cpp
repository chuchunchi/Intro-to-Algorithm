#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	cin >> n >> t;
	multiset<int> ms;
	multiset<int>::iterator iti,itj,itk;
	for(int i=0;i<n;i++){
		int wi;
		cin >> wi;
		ms.insert(wi);
	}
	int count=0;
	for(iti=ms.begin();iti!=prev(ms.end(),2);iti++){
		itj = next(iti);
		itk = prev(ms.end(),1);
		if(*iti==*prev(iti)){
			continue;
		}
		while(itj!=itk){
			if(*itj+*itk+*iti==t){
				if(*prev(itj)!=*itj||*next(itk)!=*itk){
					count++;
				}
				itj++;
				if(itj!=itk){
					itk--;
				}
				else{
					break;
				}
			}
			else if(*itj+*itk<t-*iti){
				itj++;
			}
			else if(*itj+*itk>t-*iti){
				itk--;
			}
		}
	}
	if(count==0){
		cout << "FeiDooDoo_Zuo_Wei_Men";
	}
	else{
		cout << count;
	}
	
} 
