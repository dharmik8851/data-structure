#include<iostream>
using namespace std;

int findPeakElement(int arr[], int left, int right, int n){
	int mid = left+(right-left)/2;

	if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
		return mid;
	}
	else if(mid>0 && arr[mid-1]>arr[mid]){
		return findPeakElement(arr,left,mid-1,n);
	}
	else{
		return findPeakElement(arr,mid+1,right,n);
	}
}

int main(){
	int arr[] = {10,20,15,2,23,90,67};
	int n=7;

	cout<<"index of peak element is "<<findPeakElement(arr,0,n-1,n);


}