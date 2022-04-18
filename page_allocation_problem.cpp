#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int min){
	int studentsRequired = 1, sum = 0;

	for(int i=0; i<n; i++){
		if(arr[i] > min){
			return false;
		}

		if(sum + arr[i] > min){
			studentsRequired++;
			sum = arr[i];

			if(studentsRequired > m){
				return false;
			}
		}
		else {
			sum += arr[i];
		}
	}

	return true;
}

int allocateMinimumPages(int arr[], int n, int m){
	int left = 0, right=0, ans = INT_MAX;

	if(n < m) return -1;

	for(int i=0; i<n; i++) right+=arr[i];

	while(left<right){
		int mid = (left+right)/2;
		if(isPossible(arr,n,m,mid)){
			ans = min(ans, mid);
			right = mid-1;
		}else{
			left = mid+1;
		}
	}
	return ans;
}

int main(){
	int arr[] = {10, 20, 30, 40};
	int n = 4;
	int m = 2; //number of students

	cout<<"minimum pages allocated -> "<<allocateMinimumPages(arr,n,m);
	return 0;
}