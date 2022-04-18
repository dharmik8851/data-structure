#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int arr[], int n, int mid, int k){
	int pos=arr[0], elements=1;

	for(int i=1; i<n; i++){
		if(arr[i]-pos >= mid){
			pos=arr[i];
			elements++;
			if(elements==k) return true;
		}
	}

	return false;
}

int lasgestMinDis(int arr[], int n, int k){
	sort(arr, arr+n);

	int left=1, right=arr[n-1];
	int result = -1;

	while(left<right){
		int mid = (left+right)/2;

		if(isFeasible(arr,n,mid,k)){
			left = mid+1;
			result = max(result, mid);
		}else{
			right = mid;
		}
	}

	return result;
}

int main(){
	int arr[] = {5,4,3,2,1};
	cout<< lasgestMinDis(arr,5,3);
	return 0;
}