#include <iostream>
#include <vector>
using namespace std;

vector<int> treeize(vector<int> & inorder, vector<int> & postorder,int startind, int n){
	vector<int> tree;
	tree.push_back(postorder[n]);
	for(int i=0;i<n;i++){
		if(inorder[i]==tree[1]){
			if(i==1||i==n-2){
				if(i==1){
					tree.push_back(inorder[0]);
				}
				if(i==n-2){
					tree.push_back(inorder[n-1]);
				}
				return tree;
			}
			if(i==0){
				inorder.insert(inorder.begin(),INT_MAX);
				postorder.insert(postorder.begin(),INT_MAX);
				i++;
			}
			if(i==n-1){
				inorder.insert(inorder.end()-1,INT_MAX);
				postorder.insert(postorder.end()-2,INT_MAX);
				i++;
			}
			vector<int> inord1;
			inord1.assign(inorder.begin(),inorder.begin()+i);
			vector<int> postord1;
			postord1.assign(postorder.begin(),postorder.begin()+i);
			vector<int> tree1 = treeize(inord1, postord1,i);
			
			vector<int> inord2;
			inord2.assign(inorder.begin()+i+1,inorder.end());
			vector<int> postord2;
			postord2.assign(postorder.begin()+i,postorder.end()-1);
			vector<int> tree2 = treeize(inord1, postord1,n-1-i);
			for(int j=0;j<max(tree1.size(),tree2.size());j++){
				if(j<tree1.size()){
					tree.push_back(tree1[j]);
				}
				if(j<tree2.size()){
					tree.push_back(tree2[j]);
				}
			}
			return tree;
		}
		break;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> seniority;
	vector<int> inorder;
	vector<int> postorder;
	for(int i=1;i<=N;i++){
		int si;
		cin >> si;
		seniority.push_back(si);
	}
	for(int i=1;i<=N;i++){
		int io;
		cin >> io;
		inorder.push_back(io);
	}
	for(int i=1;i<=N;i++){
		int po;
		cin >> po;
		postorder.push_back(po);
	}
	vector<int> tree = treeize(inorder, postorder, N);
	cout << tree.size() << endl;
	for(int i=0;i<tree.size();i++){
		cout << tree[i] << " ";
	}
}
