#include <iostream>
#include <algorithm>
#include <map>
#include <stack> 
#include <vector>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin,s);
	
	for(int i=0;i<s.length();i++){
		if('A'<=s[i]&&s[i]<='Z'){
			if('A'<=s[i+1]&&s[i+1]<='Z'||s[i+1]=='('||s[i+1]==')'){
				s.insert(i+1,"1");
			}
			else if('a'<=s[i+1]&&s[i+1]<='z'||s[i+1]=='('||s[i+1]==')'){
				if('A'<=s[i+2]&&s[i+2]<='Z'||s[i+2]=='('||s[i+2]==')'){
					s.insert(i+2,"1");
				}	
			}
		}
	}
	stack<int> brackets;
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			brackets.push(i);
			continue;
		}
		else if(s[i]==')'){
			int firstbracket = brackets.top();
			int secondbracket = i;
			brackets.pop();
			string multi = "";
			for(int j=i+1;j<s.length();j++){//the number after the bracket;
				if('0'<=s[j]&&s[j]<='9'){
					multi+=s[j];
				}
				else break;
			}
			if(multi==""){
				multi += "1";
			}
			int m = stoi(multi);
			string number = "";
			int pos = s.length();
			for(int j=firstbracket+1;j<secondbracket+1;j++){//numbers between the bracket
				if('0'<=s[j]&&s[j]<='9'){
					number+=s[j];
					if(j<pos){
						pos = j;//the first position of the number
					}
				}
				else{
					if(number!=""){
						int num = stoi(number);
						int aftermulti = num * m;
						string after_m_str = to_string(aftermulti);
						s.erase(pos,number.length());
						s.insert(pos,after_m_str);
						j = pos + after_m_str.length()-1;
						secondbracket += (after_m_str.length()-number.length());
						pos = s.length();
						number = "";
					}
				}
				i = secondbracket;
			}
		}
	}
	
	map<char,int> singular;
	map<char,int>::iterator sit;
	map<string,int> dou;
	map<string,int>::iterator dit;
	int i,j;
	for(i=0;i<s.length();i++){
		if('A'<=s[i]&&s[i]<='Z'){
			if('a'<=s[i+1]&&s[i+1]<='z'){
				string doubles = "";
				doubles+=s[i];
				doubles+=s[i+1];
				string number = "";
				for(j=i+2;j<s.length();){
					if('0'<=s[j]&&s[j]<='9'){
						number+=s[j];
						j++;
					}
					else break;
				}
				if(number==""){//a.k.a if j=i+2=s.length (otherwise we will run the for-loop above at least once.
					number += '1';
				}
				int num = stoi(number);
				if(dou.find(doubles)!=dou.end()){
					dou[doubles]+=num;
				}
				else{
					dou.insert(pair<string,int>(doubles,num));
				}
				i = j-2; //jump to the next element
				
			}
			else{
				string number = "";
				for(j=i+1;j<s.length();){
					if('0'<=s[j]&&s[j]<='9'){
						number+=s[j];
						j++;
					}
					else break;
				}
				if(number==""){
					number += '1';
				}
				int num = stoi(number);
				if(singular.find(s[i])!=singular.end()){
					singular[s[i]]+=num;
				}
				else{
					singular.insert(pair<char,int                         >(s[i],num));
				}
				i = j-1; //jump to the next element	
				
			}
		}
	}
	
	cout << singular.size() << '\n';
	for(sit=singular.begin();sit!=singular.end();sit++){
		cout << sit->first << ":" << sit->second << '\n';
	}
	cout << dou.size() << '\n';
	for(dit=dou.begin();dit!=dou.end();dit++){
		cout << dit->first << ":" << dit->second << '\n';
	}
}
