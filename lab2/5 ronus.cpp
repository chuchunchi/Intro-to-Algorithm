#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a,b;
/*static int fmemo(int n) {
    // entry table to cache the computed values
    int[] fs = new int[n + 1];
    // initialize entry table with -1 to say value has to calculated
    Arrays.fill(fs, -1);

    return f(n, fs);
}*/
static int f(int n, vector<double>& fs) {
    
    if(n==1){
    	return 1;
	}
    if (fs[n] == -0.5) {
        fs[n] = (f(n-1,fs)*a+b)%1000000007;
    }

    return fs[n];
}
/*int f(int i,int a,int b){
	if(i==1){
		return 1;
	}
	else{
		return (f(i-1,a,b)*a+b)%1000000007;
	}
}*/

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> a >> b >> N;
	vector<int> vi;
	vector<int>::iterator it;
	for(int i=0;i<N;i++){
		int qi;
		cin >> qi;
		vi.push_back(qi);
	}
	vector<int>::iterator max = max_element(vi.begin(), vi.end());
	static vector<double> fs((*max)+1,-0.5);
	
	for(it=vi.begin();it!=vi.end();it++){
		cout << f(*it,fs) << '\n';
	}
} 
