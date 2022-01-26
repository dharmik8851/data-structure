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
