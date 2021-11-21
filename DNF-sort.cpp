#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void dnfsort(int arr[],int n){
	int low=0,mid=0,high=n-1;
	
	while(mid<=high){
		if(arr[mid] == 0){
			swap(arr,mid,low);
			low++; mid++;
		}
		else if(arr[mid] == 1) {
			mid++;
		}
		else{
			swap(arr,mid,high);
			high--;
		}
	}
}

int main(){
	int arr[] ={1,2,0,0,2,0,2,1,2,2};
	
	cout<<"before sorting -> ";
	for(auto val : arr) cout<<val<<' ';
	
	dnfsort(arr,10);
	
	cout<<endl<<endl<<"after sorting -> ";
	for(auto val : arr) cout<<val<<' ';
	return 0;
}