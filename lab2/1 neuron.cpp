#include <iostream>
#include <map>
using namespace std;

class bintree{
	public:
		bintree* parent;
		bintree* lchild;
		bintree* rchild;
		long long int data;
		bintree():parent(0),lchild(0),rchild(0),data(0){};
		bintree(int x):parent(0),lchild(0),rchild(0),data(x){};
		
		int postorder(bintree* root){
			if(root->lchild!=0){
				long long int total = (root->data * (postorder(root->lchild)+postorder(root->rchild)))%1000000007;
				return total;
			}
			return root->data%1000000007;
		}
};
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	bintree root,nodes[N];
	for(int i=0;i<N;i++){
		int ci;
		cin >> ci;
		nodes[i].data = ci;
	}
	for(int i=1;i<N;i++){
		int oi;
		cin >> oi;
		nodes[i].parent = &nodes[oi-1];
		if(nodes[oi-1].lchild==0){
			nodes[oi-1].lchild = &nodes[i];
		}
		else{
			nodes[oi-1].rchild = &nodes[i];
		}
	}
	cout << root.postorder(&nodes[0])%1000000007;
	
	
}
