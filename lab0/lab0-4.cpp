#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);     
	
	stack<unsigned long long int> s;
	unsigned long long int x, y, z;
	
	string a;
	while(cin >> a){
		if(a=="+"){
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();
			z = (x+y)%1000000007;
			s.push(z);
		}
		else if(a=="*"){
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();
			z = (x*y)%1000000007;
			s.push(z);
		}
		else{
			s.push(stoi(a)%1000000007);
		}
	}
	//cout << s.top();
	cout << s.top()%1000000007;
	
	/*do{
		int x = s.top()-'0';
		//cout << x << '\n';
		s.pop();
		int y = s.top()-'0';
		//cout << y << '\n';
		s.pop();
		char oper = s.top();
		if(oper=='+'){
			s.push((x+y)%1000000007);
		}
		else if(oper=='*'){
			s.push((x*y)%1000000007);
		}
	}while(s.size()!=1);
	
	cout << s.top(); */
	
}
