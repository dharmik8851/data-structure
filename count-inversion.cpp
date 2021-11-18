#include<iostream>
using namespace std;

//problem
/* count the inversions in the given array
   two elements a[i] and a[j] form an inversion if
   a[i] > a[j] and i<j*/

int merge(int arr[], int l, int mid, int r){
	int n1 = mid-l+1;
	int n2 = r-mid;
	int a[n1],b[n2];
	int i=0,j=0,k=l,inv=0;
	
	for(int i=0; i<n1; i++){
		a[i] = arr[i+l];
	}
	for(int i=0; i<n2; i++){
		b[i] = arr[i+mid+1];
	}
	
	while(i<n1 && j<n2){
		if(a[i] <= b[j]){
			arr[k] = a[i];
			k++; i++;
		}
		else{
			arr[k] = b[j];
			inv++;
			k++; j++;
		}
	}
	
	while(i<n1){
		arr[k] = a[i];
		k++;i++;
	}
	
	while(j<n2){
		arr[k] = b[j];
		k++;j++;
	}
	
	return inv;
}

int mergeSort(int arr[], int l, int r){
	int inv=0;
	if(l < r){
		int mid = (l+r)/2;

		inv += mergeSort(arr,l,mid);
		inv += mergeSort(arr,mid+1,r);
		inv += merge(arr,l,mid,r);
	}
	
	return inv;
}

int main(){
	int arr[] = {6,3,9,5,2,8,7,1};
	cout<<endl<<"before sorting -> ";
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl<<"inversions -> "<<mergeSort(arr,0,7);	
	cout<<endl<<"after sorting -> ";
	for(auto val : arr){
		cout<<val<<" ";
	}
	
	return 0; 
}