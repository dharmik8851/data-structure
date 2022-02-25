#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int l, int r){
	int pivat = arr[r];
	int i=l-1;
	
	for(int j=l; j<r; j++){
		if(arr[j] < pivat){
			i++;
			swap(arr, i, j);
		}
	}
	
	swap(arr, i+1, r);
	return i+1;
}

void quickSort(int arr[], int l, int r){
	if(l < r){	
		int pi = partition(arr,l,r);
	
		quickSort(arr, l, pi-1);
		quickSort(arr, pi+1, r);
	
	}
}

int main() {
	int arr[] = {5,4,3,2,1};

	
	cout<<"before sorting -> ";
	for(auto val : arr){
		cout<<val<<" ";
	}
	
		quickSort(arr, 0, 4);
		
		
	cout<<endl<<"after sorting -> ";
	for(auto val : arr){
		cout<<val<<" ";
	}
	
	return 0;
}