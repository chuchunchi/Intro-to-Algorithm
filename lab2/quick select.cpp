// CPP program for implementation of QuickSelect
#include <bits/stdc++.h>
using namespace std;

// Standard partition process of QuickSort().
// It considers the last element as pivot
// and moves all smaller element to left of
// it and greater elements to right
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

// This function returns k'th smallest
// element in arr[l..r] using QuickSort
// based method. ASSUMPTION: ALL ELEMENTS
// IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of
	// elements in array
	if (k > 0 && k <= r - l + 1) {

		// Partition the array around last
		// element and get position of pivot
		// element in sorted array
		int index = partition(arr, l, r);

		// If position is same as k
		if (index - l == k - 1)
			return arr[index];

		// If position is more, recur
		// for left subarray
		if (index - l > k - 1)
			return kthSmallest(arr, l, index - 1, k);

		// Else recur for right subarray
		return kthSmallest(arr, index + 1, r,
							k - index + l - 1);
	}

	// If k is more than number of
	// elements in array
	return INT_MAX;
}

// Driver program to test above methods
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	/*int n = sizeof(arr) / sizeof(arr[0]);
	cout << n << endl;
	int k = 3;*/
	int l=0,r=8,m=(l+r)/2;
	int subv1[m-l+1],subv2[r-m];
	int csubv1[m-l+1],csubv2[r-m];
	copy(arr,arr+(m-l+1),subv1);
	copy(arr,arr+(m-l+1),csubv1);	
	copy(arr+(m-l+1),arr+(r-l+1),subv2);
	copy(arr+(m-l+1),arr+(r-l+1),csubv2);
	if(r-l+1<=2){
		return 0;
	}
	int op1=0,op2=0;
	
	nth_element(subv1,subv1+(m-l)/2,subv1+m-l+1);
	cout << "PPPP" << *subv1+(m-l)/2 << endl;
	int median1 = subv1[(m-l)/2];
	cout << median1 << endl; 
	for(int i=0;i<m-l+1;i++){
		cout << subv1[i] << " " ;
		op1 += abs(subv1[i]-median1);
	}
	cout << endl ;
	
	nth_element(subv2,subv2+(r-m-1)/2,subv2+r-m);
	int median2 = subv2[(r-m-1)/2];
	cout << median2 << endl;
	for(int i=0;i<r-m;i++){
		cout << subv2[i] << " ";
		op2 += abs(subv2[i]-median2);
	}
	cout << endl;
	return 0;
}

