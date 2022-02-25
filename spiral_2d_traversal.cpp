#include<iostream>
using namespace std;
int main(){
	int c,r;
	cout<<"Enter the size of row and column of your 2d array->"; cin>>r>>c;
	int a[r][c];
	//taking input of 2d array from user
	for(int i=0; i<r*c; i++){
		cin>>a[i/c][i%c];
	}
	
	//printing 2d array in spiral 
	int r_start=0,r_end=r-1,c_start=0,c_end=c-1;
	while(r_start <= r_end && c_start <= c_end){
		
		//for printing from c_start to c_end
		for(int col=c_start; col<=c_end; col++){
			cout<<a[r_start][col]<<" ";
		}
		r_start++;
		
		//for printing from r_start to r_end
		for(int row=r_start; row<=r_end; row++){
			cout<<a[row][c_end]<<" ";
		}
		c_end--;
		
		//for printing from c_end to c_start
		for(int col=c_end; col>=c_start; col--){
			//cout<<a[r_end][col]<<" ";
			cout<<a[r_end][col]<<" ";
		}
		r_end--;
		
		//for printing from r_end to r_start
		for(int row=r_end; row>=r_start; row--){
			cout<<a[row][c_start]<<" ";
		}
		c_start++;
	}
	
	return 0;
}