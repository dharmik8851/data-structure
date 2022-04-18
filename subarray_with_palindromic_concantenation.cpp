#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPalindrom(int n){
	int temp=n,number=0;

	while(temp>0){
		number = number*10 + temp%10;
		temp = temp / 10;
	}

	if(number==n) return true;
	return false;
}

int palindromicSubarray(vector<int> v, int k){
	int ans=-1,no=0;
	for(int i=0; i<k; i++){
		no = no*10 + v[i];
	}

	if(isPalindrom(no)) return 0;

	for(int i=k; i<v.size(); i++){
		no = (no%(int)pow(10,k-1))*10 + v[i];

		if(isPalindrom(no)){
			return i-k+1;
		}
	}

	return -1;
}

int main(){
	vector<int> v = {2,3,5,1,1,5};
	int k=4;

	int idx = palindromicSubarray(v,k);

	if(idx==-1){
		cout<<"palindromic Subarray doesn't exist";
	}else{
		for(int i=idx; i<idx+k; i++){
			cout<<v[i]<<" ";
		}
	}
	return 0;
}