#include<iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
	for(int row=0; row<x; row++){
		if(arr[row][y] == 1) 
			return false;
	}
	for(int row=x-1,col=y-1; row>=0 && col>=0; row-- && col--){
			if(arr[row][col] == 1)
				return false;
	}
	for(int row=x-1,col=y+1; row>=0 && col<n; row-- && col++){
			if(arr[row][col] == 1)
				return false;
	}
	return true;
}

bool nQueen(int **arr, int x, int n){
	//base condition
	if(x==n) return true;
	
	for(int col=0; col<n; col++){
		if(isSafe(arr,x,col,n)){
			arr[x][col] = 1;
			if(nQueen(arr,x+1,n))
				return true;
			arr[x][col] = 0;
		}
	}
	return false;
}

int main(){
	int n;
	cout<<"enter your board size -> ";
	cin>>n;
	
	int **arr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i] = new int[n];
		for(int j=0; j<n; j++)
			arr[i][j]=0;
	}
	
	if(nQueen(arr,0,n)){
		cout<<"your "<<n<<" queen can be placed on following position -> ";
		for(int i=0; i<n*n; i++){
			if(i%n == 0) cout<<endl;
			cout<<arr[i/n][i%n]<<" ";
		}
			
	}
	return 0;
}