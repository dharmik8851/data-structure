//get area of largest rectangle in histogram
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int get_max_rectangle(vector<int> arr){
	int n=arr.size(), i=0, ans=0;
	arr.push_back(0);
	stack<int> st;
	
	while(i<n){
		
		while(!st.empty() and arr[st.top()] > arr[i]){
			int h = arr[st.top()];
			st.pop();
			if(st.empty()){
				ans = max(ans, h*i);
			}
			else{
				int w = i-st.top()-1;
				ans = max(ans, h*w);
			}
		}
	
		st.push(i);
		i++;
	}
	
	return ans;
}

int main(){
	vector<int> arr= {1,2,3,2,1};
	cout<<get_max_rectangle(arr);
	return 0;
}