#include<iostream>
using namespace std;

int main(){
	int r,c;
	cout<<"Enter row size of your matrix -> "; cin>>r;
	cout<<"Enter column size of your matrix -> "; cin>>c;
	
	int arr[r][c];
	cout<<"Enter your matrix->"<<endl;
	for(int i=0; i<r*c; i++){
		cin>>arr[i/c][i%c];
	}
	
	int ele;
	cout<<"Which element do you want to search -> "; cin>>ele;
	int i=0,j=c-1;
	bool found=false;
	while(i<r && j<c){
		if(arr[i][j] == ele){
			found = true; break;
		}else if(arr[i][j] > ele) j--;
		else i++;
	}
	if(found){
		cout<<endl<<"Element found";
	}else cout<<endl<<"Element not found";
}