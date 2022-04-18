#include<iostream>
using namespace std;

void maxSubarraySum(int arr[], int n, int x, int k){	
	int sum=0,ans=0;

	for(int i=0; i<k; i++){
		sum+=arr[i];
	}

	if(sum<x) ans=sum;

	for(int i=k; i<n; i++){
		sum = sum - arr[i-k];
		sum = sum + arr[i];

		if(sum<x){
			ans = max(ans, sum);
		}
	}

	cout<< ans << " is max subarray which is less than x";
}

int main(){

	int arr[] = {7,5,4,6,8,9};
	int n=6;
	int x=20;
	int k=3;

	maxSubarraySum(arr,n,x,k);
	return 0;
}