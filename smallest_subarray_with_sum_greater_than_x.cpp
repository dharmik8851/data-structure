#include<iostream>
#include<climits>
using namespace std;

// void smallestSubarray(int arr[], int n, int x){
// 	int sum=0, ans=INT_MAX,s=0;

// 	for(int i=0; i<n; i++){
// 		sum += arr[i];
// 		if(sum>x){
			
// 			while(sum>x){
// 				sum = sum - arr[s];
// 				s++;	
// 			}
// 			ans = min(ans, i-s+2);
// 		}
// 	}

// 	cout<<ans << " is smallestSubarray greater than x";
// }

void smallestSubarray(int arr[], int n, int x){
	int start=0,end=0,sum=0,minLength=n+1;

	while(end < n){
		while(sum <= x && end < n){
			sum+=arr[end++];
		}

		while(sum>x && start<n){
			if(end - start < minLength){
				minLength = end - start;
			}
			sum -= arr[start++];
		}
	}

	cout<<minLength << " is smallestSubarray greater than x";
}

int main(){
	int arr[] = {1,4,45,6,10,19};
	int n=6;
	int x=51;
	smallestSubarray(arr,n,x);
	return 0;
}