#include<iostream>
#include "bits/stdc++.h"
#include<stack>
using namespace std;

/*
problem : Trapping rainwater harvesting : 
Given non-negative integers representing an elevation map where the 
width of each bar is 1, compare how much water it can trap after raining
*/

int trapping_rain(vector<int> arr){
	stack<int> st;
	int ans=0;
	
	for(int i=0; i<arr.size(); i++){
		while(!st.empty() and arr[st.top()]<arr[i]){
			int curr = st.top();
			st.pop();
			
			if(st.empty()) break;
			
			int diff = i-st.top()-1;
			ans += (min(arr[st.top()],arr[i])-arr[curr]) * diff;
		}
		st.push(i);
	}
	
	return ans;
}

int main(){
	vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1,0};	
	cout<<trapping_rain(arr);
	return 0;
}