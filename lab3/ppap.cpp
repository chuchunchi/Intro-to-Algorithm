#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
using namespace std;

int c=0;
map<string,int> mp;
class Node{
	public:
		string word;
		int freq;
		int count;
		Node* parent;
		Node* lchild;
		Node* rchild;
		Node():parent(0),lchild(0),rchild(0),word(""),freq(0),count(1){};
		Node(string s,int x):parent(0),lchild(0),rchild(0),word(s),freq(x),count(1){};
		
		
};
void travel(Node* root){
	if(root->lchild==0 && root->rchild==0){
		mp[root->word] = c;
		//cout << c << " ";
		return;
	}
	else{
		c++;
		//cout << root->word << " " << c << endl;
		travel(root->lchild);
		travel(root->rchild);
		c--;
	}
	//travel(root.lchild).count+=root.count;
	//travel(root.rchild).count+=root.count;
}
struct cmp{
	bool operator()(Node* n1,Node* n2){
		if(n1->freq!=n2->freq){
			return (n1->freq > n2->freq); 
		}
		else{
			return (n1->word > n2->word);
		}
	}
};


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	string s = " \n";
	getline(cin,s);
	string str[N];
	
	map<string,int>::iterator mpit;
	double totalwordcount=0;
	for(int i=0;i<N;i++){
		getline(cin,str[i]);
		for(int j=0;j<str[i].size();j++){
			string word = "";
			while(str[i][j]!=' '&&j<str[i].size()){
				word += str[i][j];
				j++;
			}
			mpit = mp.find(word);
			if(mpit!=mp.end()){
				mpit->second++;
			}
			else{
				mp.insert(make_pair(word,1));
				totalwordcount++;
			}
		}
	}
	priority_queue< Node*,vector<Node*>,cmp > nodes;
	for(mpit=mp.begin();mpit!=mp.end();mpit++){
		//cout << mpit->first << " " << mpit->second << endl;
		Node* N = new Node(mpit->first,mpit->second);
		nodes.push(N);
	}
	while(nodes.size()!=1){
		Node* L = new Node;
		L = nodes.top();
		nodes.pop();
		Node* R = new Node;
		R = nodes.top();
		nodes.pop();
		Node* Root = new Node((L->word>R->word)?R->word:L->word,L->freq+R->freq);
		nodes.push(Root);
		Root->lchild = L;
		Root->rchild = R;
		//L.count++;
		//R.count++;
	}
	Node* finalroot = nodes.top();
	//cout << finalroot.lchild->word << endl;
	travel(finalroot);
	for(int i=0;i<N;i++){
		double bits=0, wordcount=0;
		for(int j=0;j<str[i].size();j++){
			string word = "";
			while(str[i][j]!=' '&&j<str[i].size()){
				word += str[i][j];
				j++;
			}
			wordcount++;
			mpit = mp.find(word);
			if(mpit!=mp.end()){
				cout << "word " << word << endl;
				cout << "count " << mpit->second << endl;
				bits += mpit->second;
			}
		}
		//cout << bits << "   " << log2(totalwordcount) << "   " << wordcount << endl;
		cout << fixed << setprecision(7) << bits/(ceil(log2(totalwordcount))*wordcount) << '\n';
		//cout << endl;
	}
	/*for(mpit=mp.begin();mpit!=mp.end();mpit++){
		cout << mpit->first << " " << mpit->second << endl;
	}*/
}
