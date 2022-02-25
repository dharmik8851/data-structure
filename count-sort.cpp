#include<iostream>
using namespace std;

void countSort(int arr[], int n){
	int mx = arr[0];
	
	//max element in array is mx
	for(int i=1; i<n; i++) {
		mx = max(arr[i],mx);
	}
	
	mx=mx+1;
	int tempArr[mx] = {0}; //array of size mx
	
	//calculating the count of every distinct element in the array
	for(int i=0; i<n; i++) tempArr[arr[i]]++;
	
	//calculation the position of each element in sorted array
	for(int i=1; i<mx; i++){
		tempArr[i] = tempArr[i]+tempArr[i-1];
	}
	
	int output[n];
	for(int i=0; i<n; i++){
		output[--tempArr[arr[i]]] = arr[i];
	}
	for(int i=0; i<n; i++){
		arr[i] = output[i];
	}
}

int main(){
	int arr[] = {1,3,5,3,2,3,2,3,5,4};
	cout<<"before sorting -> ";
	for(auto val : arr) cout<<val<<' ';
	
	countSort(arr,10);
	
	cout<<endl<<endl<<"after sorting -> ";
	for(auto val : arr) cout<<val<<' ';
	
	return 0;
}