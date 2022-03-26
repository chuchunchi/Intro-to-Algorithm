#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <limits>
using namespace std;
int CeilIndexinc(std::vector<int>& v, int l, int r, int key)
{
    while(r-l>1){
        int m = (l+r) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}

int CeilIndexdec(std::vector<int>& v, int l, int r, int key)
{
    while(r-l> 1){
        int m = (l+r) / 2;
        if (v[m] <= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
vector<int> LISLength(vector<int>& v)
{
 
    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    vector<int> increase;
    increase.push_back(1);
    for (int i = 1; i < v.size(); i++) {
        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];
 
        // v[i] extends largest subsequence
        else if(v[i] > tail[length - 1]){
        	tail[length++] = v[i];
		}
        else{
        	tail[CeilIndexinc(tail, -1, length - 1, v[i])] = v[i];
		}
            
        increase.push_back(length);
    }
    return increase;
}

vector<int> LDSLength(vector<int>& v)
{
    
    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    vector<int> decrease;
    decrease.push_back(1);
    for (int i = 1; i < v.size(); i++) {
        // new smallest value
        if (v[i] > tail[0]){
        	tail[0] = v[i];
		}
        // v[i] extends largest subsequence
        else if(v[i] < tail[length - 1]){
        	tail[length++] = v[i];
		}
        else{
        	tail[CeilIndexdec(tail, -1, length - 1, v[i])] = v[i];
		}
        decrease.push_back(length);
    }
    return decrease;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v;
	vector<int> increase1,increase2,decrease1,decrease2;
	for(int i=0;i<N;i++){
		int hi;
		cin >> hi;
		v.push_back(hi);
	}
	increase1 = LISLength(v);
	decrease1 = LDSLength(v);
	reverse(v.begin(),v.end());
	increase2 = LISLength(v);
	decrease2 = LDSLength(v);
	int maxi = 0;
	for(int i=0;i<N;i++){
		if(increase1[i]+increase2[N-i-1]>maxi){
			maxi = increase1[i]+increase2[N-i-1];
		}
		if(decrease1[i]+decrease2[N-i-1]>maxi){
			maxi = decrease1[i]+decrease2[N-i-1];
		}
	}
	
	cout << maxi-1;
}
