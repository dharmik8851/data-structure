#include<iostream>
#include<climits>
using namespace std;

int kadane(int a[],int n){
	int currentSum=0,maxSum=INT_MIN;
	for(int i=0; i<n; i++){
		currentSum += a[i];
		if(currentSum < 0) {
			currentSum = 0;
		}
		maxSum=max(currentSum,maxSum);
	}
	return maxSum;
}

int main(){
	
	int n;
	cout<<"Enter size of your array -> "; cin>>n;
	int a[n];
	
	//taking n inputs from user
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	//'Maximum circular subarray sum'
	int nonWrapMax = kadane(a,n);
	int totalSum=0;
	for(int i=0; i<n; i++){
		totalSum += a[i];
		a[i] = -a[i];
	}
	int sumNonContributors = kadane(a,n);
	int wrapMax = totalSum - (-sumNonContributors);
	cout<<endl<<"maximum circular subarray sum is -> "<<max(nonWrapMax,wrapMax);
	
	//pair sum problem in which find pair in array which sum is = k;
	//first perform array sorting;
	int arr[10] = {1,22,33,44,55,66,77,100,101,102},k=101;
	cout<<endl<<"pair sum which may be founded is -> "<<k;
	cout<<endl<<"sorted array -> "; 
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	int low=0, high=9;
	while(low<high){
		if(arr[low]+arr[high] < k){
			low++;
		}else if(arr[low]+arr[high] > k){
			high--;
		}else{
			cout<<endl<<"pair found at index -> "<<low+1<<" and "<<high+1;
			break;
		}
	}
}