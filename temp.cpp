#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin>>n;
	vector<int> arr(n);
	
	for(auto &ele : arr) cin>>ele;
	
	int ans;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			ans = max(ans,min(arr[i],arr[j])*(j-i));
		}
	}
	
	cout<<ans;
	
    return 0;
}


void permutation(vector<int> arr, vector<int> ans,bool *chk){
	if(arr.size()==0){
		
		int a=abs(ans[0]-ans[1]);
		for(int i=1; i<ans.size()-1; i++){
			int op = abs(ans[i]-ans[i+1]);
			a = a^op;
		}

		if(a==0){
			cout<<endl;
			for(auto ele : ans) cout<<ele<<" ";
			cout<<a;
			*chk = true;
		}
		return;
	}

	for(int i=0; i<arr.size(); i++){
		vector<int> roa;
		for(int j=0; j<i; j++) roa.push_back(arr[j]);
		for(int j=i+1; j<arr.size(); j++) roa.push_back(arr[j]);
		ans.push_back(arr[i]);
		permutation(roa,ans,chk);
		ans.pop_back();
		if(*chk) return;
	}
}