#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
vector<int> seniority;
vector<int> inorder; 
vector<int> postorder;
int N;
vector<int> inorderaddress;
int  treeize(int INstart, int INlast, int POSTstart, int POSTlast, int prevroot){
	int awkward = 0;
	int root = seniority[postorder[POSTlast]-1];
	
	//cout << "rootind:" << postorder[POSTlast] << endl;
	
	if(root>prevroot){
		awkward ++;
		//cout << "root in post: " <<  root << endl;
		//cout << "prevroot in post: " <<  prevroot << endl;
	}
	
	if(INlast<=INstart||POSTlast<=POSTstart){
		return awkward;
	}
	
	//vector<int>::iterator it = find(inorder.begin(), inorder.end(), postorder[POSTlast]);
	//int rootind = distance(inorder.begin(), it);
	int rootind = inorderaddress[postorder[POSTlast]]-1;
	int leftsize = rootind-INstart;
	int rightsize = INlast-rootind;
	if(leftsize){
		awkward += treeize(INstart, INstart+leftsize-1, POSTstart, POSTstart+leftsize-1, root);
	}
	if(rightsize){
		awkward += treeize(rootind+1, INlast, POSTstart+leftsize, POSTstart+leftsize+rightsize-1, root);
	}
	return awkward;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	seniority.resize(N);
	inorder.resize(N);
	postorder.resize(N);
	for(int i=0;i<N;i++){
		int si;
		cin >> si;
		seniority[i] = si; 
	}
	for(int i=0;i<N;i++){
		int io;
		cin >> io;
		inorder[i] = io;
	}
	for(int i=0;i<N;i++){
		int po;
		cin >> po;
		postorder[i] = po;
	}
	
	inorderaddress.resize(N+1);
	inorderaddress[0] = 0;
	for(int i=0;i<N;i++){
		inorderaddress[inorder[i]] = i+1;
	}
	cout << treeize(0, N-1,0, N-1, INT_MAX);
	
}
