#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void wavesort(int arr[],int n){
	int i=1;
	while(i<n-1){
		if(arr[i] > arr[i-1]) swap(arr,i,i-1);
		if(arr[i] > arr[i+1] && i<=n-2) swap(arr,i,i+1);
		i+=2;
	}
}

int main(){
	int arr[] = {1,3,4,7,5,6,2};
	
	cout<<"before sorting -> ";
	for(auto val : arr) cout<<val<<' ';
	
	wavesort(arr,7);
	
	cout<<endl<<endl<<"after sorting -> ";
	for(auto val : arr) cout<<val<<' ';
	
	return 0;
}