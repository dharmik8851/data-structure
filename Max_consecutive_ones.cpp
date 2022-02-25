#include<iostream>
#include<vector>
#include "bits/stdc++.h"
using namespace std;

/*
Given an array A of 0s and 1s, we may change
up to K values from 0 to 1.
Return the length of the longest(contiguos) 
subarray that contains only 1s.
*/

int main(){
	int n; 
	cout<<"Enter size of array->";
	cin>>n;
	int k; 
	cout<<"Enter value of k->";
	cin>>k;
	
	vector<int> arr(n);
	cout<<endl<<"Enter elements->";
	for(auto &i : arr)
		cin>>i;	
		
	int i=0,zerocount=0,ans=0;
	for(int j=0; j<n; j++){
		if(arr[j] == 0){
			zerocount++;
		}
		while(zerocount>k){
			if(arr[i] == 0){
				zerocount--;
			}
			i++;
		}
		ans = max(ans, j-i+1);
	}
	
	cout<<endl<<ans;
	return 0;
}