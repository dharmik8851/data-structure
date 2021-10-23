#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the size of n->"; cin>>n;
	int a[n][n];
	//taking input of 2d array from user
	for(int i=0; i<n*n; i++){
		cin>>a[i/n][i%n];
	}
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(j != i){
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
	}
	
	cout<<endl<<"transpose of matrix is -> "<<endl;
	for(int i=0; i<n*n; i++){
		cout<<a[i/n][i%n]<<" ";
		if(i%n == n-1){
			cout<<endl;
		}
	}
	
}