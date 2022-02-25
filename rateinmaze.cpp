#include<iostream>
using namespace std;

//checking is the block is safe or not
bool isSafe(int **arr, int x, int y, int n){
	if(arr[x][y] == 1 && x<n && y<n)
		return true;
	return false;
}

bool rateInMaze(int **arr, int x, int y, int n, int **solArr){
	
	if(y==n-1 && x==n-1) {
		solArr[x][y] = 1;
		return true;
	}//<- base case
	
	/*if current block is safe than 
	check solution by moving rate rightside and downside
	if solution found in any side than return true
	and set solArr.*/
	if(isSafe(arr,x,y,n)){
		solArr[x][y]=1;
		if(rateInMaze(arr,x,y+1,n,solArr)){
			return true;
		}
		if(rateInMaze(arr,x+1,y,n,solArr)){
			return true;
		}
		solArr[x][y]=0;
		return false;
	}
	return false;
}

int main(){
	int n;
	cout<<"Enter size of your square matrix -> ";
	cin>>n;
	cout<<endl<<"Enter elements -> "<<endl;
	
	//pointer to pointer
	//here each arr element is pointer and pointing to new Array
	int **arr = new int*[n];
	int **solArr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i] = new int [n];
		solArr[i] = new int [n];
	}
	
	//getting elements form user and setting solArr to 0
	for(int i=0; i<n*n; i++){
		cin>>arr[i/n][i%n];
		solArr[i/n][i%n] = 0;
	}
	
	
	//if solution found than solArr matrix is printed
	if(rateInMaze(arr,0,0,n,solArr)){
		for(int i=0; i<n*n; i++){
			if(i%n == 0) cout<<endl;
			cout<<solArr[i/n][i%n]<<" ";
		}			
	}
	else{
		cout<<endl<<"solution not found...";
	}

	return 0;
}