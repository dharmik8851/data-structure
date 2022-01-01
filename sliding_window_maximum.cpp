#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(){
	int n,k;
	deque<int> dq;
	cout<<"Enter the size of your array -> "; cin>>n;
	cout<<"Enter the window size -> "; cin>>k;
	vector<int> ans;
	vector<int> arr(n);
	
	cout<<"Enter elements -> "; 
	for(auto &i : arr){
		cin>>i;
	}
	
	//here first we will find max from first window
	for(int i=0; i<k; i++){
		while(!dq.empty() && arr[dq.back()] < arr[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	//max element will be push into the ans array
	ans.push_back(arr[dq.front()]);
	
	//now we are finding max for remaining windows
	for(int i=k; i<n; i++){
		//this condition will check if the index of max element
		//from previous window is equal to the 
		//index of first element from previous window
		//if true than delete that index from deque
		if(i-k == dq.front()) dq.pop_front();
		
		while(!dq.empty() && arr[dq.back()] < arr[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		ans.push_back(arr[dq.front()]);
	}
	
	for(auto i : ans){
		cout<<i<<" ";
	}
	
	return 0;
}