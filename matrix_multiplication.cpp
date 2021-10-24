#include<iostream>
using namespace std;

int main(){
	int n1,n2,n3;
	cout<<endl<<"Enter the row size of first matrix -> ";
	cin>>n1;
	cout<<endl<<"Enter the column size of first matrix and row size of second matrix-> ";
	cin>>n2;
	cout<<endl<<"Enter the column size of second matrix -> ";
	cin>>n3;
	
	//taking inputs from user
	int m1[n1][n2], m2[n2][n3];
	cout<<endl<<"Enter first matrix"<<endl;
	for(int i=0; i<n1*n2; i++){
		cin>>m1[i/n2][i%n2];
	}
	
	cout<<endl<<"Enter second matrix"<<endl;
	for(int i=0; i<n2*n3; i++){
		cin>>m2[i/n3][i%n3];
	}
	
	//declaring answer matrix which store multiplication answer
	int ans[n1][n3];
	//initializing answer with 0
	for(int i=0; i<n1*n3; i++){
		ans[i/n3][i%n3]=0;
	}
	
	//calculating maltiplication and storeing it into answer
	for(int i=0; i<n1; i++){
		for(int j=0; j<n3; j++){
			for(int k=0; k<n2; k++){
				ans[i][j] += m1[i][k]*m2[k][j];				
			}
		}
	}
	
	//printing answer
	cout<<"your answer ->"<<endl;
	for(int i=0; i<n1*n3; i++){
		cout<<ans[i/n3][i%n3]<<" ";
		if(i%n3 == n3-1) cout<<endl;
	}
	
	return 0;
}