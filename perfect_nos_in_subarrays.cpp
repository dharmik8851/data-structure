#include<iostream>
#include<cmath>
using namespace std;

bool isNoPerfect(int n){
	int sum=1;

	for(int i=2; i<sqrt(n); i++){
		if(n%i == 0){
			if(i == n/i){
				sum = sum + i;
			}else{
				sum = sum + i + n/i;
			}
		}
	}

	if(n == sum && n!=1) return true;
	return false;
}

int maxsum(int arr[],int n, int k){

	if(n<k){
		cout<<"invalid elemets";
		return -1;
	}
	int sum=0,res=0;

	for(int i=0; i<k; i++) sum+=arr[i];
	res=sum;

	for(int i=k; i<n; i++){
		sum = sum + arr[i] - arr[i-k];
		res = max(res,sum);
	}

	return res;
}

int maxNoOfPerfects(int arr[], int n, int k){

	for(int i=0; i<n; i++){
		if(isNoPerfect(arr[i])) arr[i]=1;
		else arr[i]=0;
	}

	return maxsum(arr,n,k);
}

int main(){
	int arr[] = {28,2,3,6,496,99,8128,24};
	int n = 8, k = 4;

	cout<<maxNoOfPerfects(arr,n,k);
	return 0;
}