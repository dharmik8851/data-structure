#include <vector>
#include <iostream>
#include "bits/stdc++.h"
using namespace std;

/*
Given an array and a value, find if there exists 
three numbers whose sum is equal to the given value.
*/

int main(){
	int n; 
	cout<<"Enter size of array->";
	cin>>n;
	int target; 
	cout<<"Enter three sum which you want to find->";
	cin>>target;
	
	vector<int> arr(n);
	cout<<endl<<"Enter elements->";
	for(auto &i : arr)
		cin>>i;	
		
	sort(arr.begin(),arr.end());
		
	bool found=false;
	for(int i=0; i<n; i++){
		int low=i+1, high=n-1; 
		while(low<high){
			int current = arr[i] + arr[low] + arr[high];
			if(current == target){
				found=true; break;
			}
			else if(current>target){
				high--;
			}
			else {
				low++;
			}
		}
	}
	
	if(found){
		cout<<endl<<"true";
	}
	else 
	cout<<endl<<"false";
		
	return 0;
}