#include<stdio.h>
#include<stdlib.h>

void asort(int *a,int size){
	int temp;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
	 		if(a[i] > a[j]){
	 			temp = a[j];
	 			a[j] = a[i];
	 			a[i] = temp;
			 }	
		}
	}
}

int binarySearch(int *a,int n,int ele){
	int low,mid,high;
	low=0;high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]<ele){
			low=mid+1;
		}
		else if(a[mid]>ele){
			high=mid-1;
		}else{
			return mid;
		}
	}
	return -1;
}
void show(int *a,int n){
	for(int i=0; i<n; i++){
		printf("\nElement %d is %d ",i+1,a[i]);
	}
}
	
int main(){
	int n,ele;
	printf("how many element do you want to enter -> ");
	scanf("%d",&n);
	int *p = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		printf("Enter element %d -> ",i+1);
		scanf("%d",&p[i]);
	}
	
	asort(p,n);
	printf("enter element to search -> ");
	scanf("%d",&ele);
	if(binarySearch(p,n,ele) == -1){
		printf("Element not found...");
	}else{
		printf("Element found at position %d", binarySearch(p,n,ele));
	}
	
	show(p,n);
	return 0;
}