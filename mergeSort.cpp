#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
	int n1 = mid-l+1;
	int n2 = r-mid;
	int arr1[n1];
	int arr2[n2];
	
	//initialize both array
	for(int i=0; i<n1; i++){
		arr1[i] = arr[l+i];
	}
	for(int i=0; i<n2; i++){
		arr2[i] = arr[i+mid+1];
	}
	
	int a1=0; //pointer in first arr
	int a2=0; //pointer in second arr
	int k=l;
	
	while(a1<n1 && a2<n2){
		if(arr1[a1] > arr2[a2]){
			arr[k] = arr2[a2];
			k++; a2++;
		}
		else{
			arr[k] = arr1[a1];
			k++; a1++;
		}
	}
	
	while(a1<n1){
		arr[k] = arr1[a1];
		k++; a1++;
	}
	
	while(a2<n2){
		arr[k] = arr2[a2];
		k++; a2++;
	}
}


void mergeSort(int arr[], int l, int r){
	if(l<r){
		int mid = (l+r)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		
		merge(arr,l,mid,r);
	}
}


int main(){
	int arr[] = {90,80,70,60,1,2,3,4};
	
	cout<<endl<<"before sorting -> ";
	for(auto val : arr){
		cout<<val<<" ";
	}
	
	mergeSort(arr, 0, 7);
	
	cout<<endl<<"after sorting -> ";
	for(auto val : arr){
		cout<<val<<" ";
	}
	
	return 0;
}