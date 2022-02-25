#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

//problem-1
/*Given an array nums of distinct integers return all the possible permutations.
You can return the answer in any order.*/

//global vector which will store all possible permutations
vector<vector<int>> perArray,perArray2;

void per(vector<int> arr, int idx){
	if(idx == arr.size()){
		perArray.push_back(arr);
		return;
	}
	for(int i=idx; i<arr.size(); i++){
		swap(arr[i],arr[idx]);
		per(arr,idx+1);
	}
}

//problem-2
/*Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order*/
void per2(vector<int> arr, int idx){
	if(idx == arr.size()){
		perArray2.push_back(arr);
		return;
	}
	for(int i=idx; i<arr.size(); i++){
		if(i!=idx && arr[i] == arr[idx]) continue;
		swap(arr[i],arr[idx]);
		per(arr,idx+1);
	}
}


int main(){
	int n;
	cout<<"how many elements do you want to enter -> ";
	cin>>n;
	vector<int> nums(n);
	
	//getting inputs
	for(auto &val : nums){
		cin>>val;
	}
	
	//method-1
	per(nums, 0);
	cout<<"your permutations -> "<<endl;
	for(auto arr : perArray){
		for(auto val : arr)
			cout<<val<<" ";
		cout<<endl;
	}
	
	//method-2
	vector<vector<int>> perArray2;
	sort(nums.begin(), nums.end());
	do{
		perArray2.push_back(nums);
	}while(next_permutation(nums.begin(),nums.end()));
	
	cout<<"your permutations -> "<<endl;
	for(auto arr : perArray2){
		for(auto val : arr)
			cout<<val<<" ";
	cout<<endl;
	}
	
	//unique permutations
	per2(nums, 0);
	cout<<"your permutations -> "<<endl;
	for(auto arr : perArray2){
		for(auto val : arr)
			cout<<val<<" ";
		cout<<endl;
	}
	
	return 0;
}