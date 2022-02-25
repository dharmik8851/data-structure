#include<iostream>
using namespace std;

int main(){
	
	int n,mx=-199999999;
	cout<<"Enter size of your array -> "; cin>>n;
	int a[n];
	
	//taking n inputs from user
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	//find max till I
	for(int i=0; i<n; i++){
			mx=max(mx,a[i]);
			cout<<"max till "<<i<<" = "<<mx<<endl;
	}
	
	//find sum of all subarrays in array
	cout<<endl<<"sum of subarrays ";
	int sum;
	for(int i=0; i<n; i++){
		sum=0;
		for(int j=i; j<n; j++){
			sum += a[j];
			cout<<sum<<" ";
		}
	}
	
	//find the length of maximum arithmetic subarray
	int currLen = 2;
	int prevDef = a[1]-a[0];
	int ans = 2;
	int j=2;
	while(j<n){
		if(a[j]-a[j-1] == prevDef){
			currLen++;
		}else{
			prevDef = a[j]-a[j-1];
			currLen=2;
		}
		ans = max(ans, currLen);
		j++;
	}
	cout<<endl<<"maximum length of arithmetic subarray is "<<ans;
	
	//find maximum visitors till now and tomorrow day
	a[n]=-1; mx=a[0];
	for(int i=1; i<=n; i++){
		if(a[i] > mx){
			mx=a[i];
			if(a[i] > a[i+1]){
				cout<<"\nrecord breaking visitors = "<<a[i];
			}
		}
	}
	
	//find index of first repeating element
	const int N = 1e5;
	int idx[N];
	for(int i=0; i<N; i++){
		idx[i] = -1;
	}
	
	int minidx = INT_MAX;
	for(int i=0; i<n; i++){
		
		if(idx[a[i]] == -1){
			idx[a[i]] = i;	
		}
		else{
			minidx = min(minidx,idx[a[i]]);
		}
	}
	if(minidx==INT_MAX){
		cout<<endl<<"minidx = "<<-1;
	}
	cout<<endl<<"minidx = "<<minidx+1;
	
	return 0;
}