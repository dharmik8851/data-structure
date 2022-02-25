#include<iostream>
#include<math.h>
using namespace std;

int main(){

	int i,j;
	int n;
	cout<<"Enter value of n -> "; cin>>n;
	
	//butterflay pattern
	
	for(i=1; i<=n; i++){
		for(j=1; j<=(n*2); j++){
			if(j<=i || j>(n*2)-i){
				cout<<"*";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	for(i=n; i>0; i--){
		for(j=1; j<=(n*2); j++){
			if(j<=i || j>(n*2)-i){
				cout<<"*";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	cout<<" \n";
	
	//inverted pattern
	for(i=1; i<=n; i++){
		for(j=1; j<=n-i+1; j++){
			cout<<j;
		}
		cout<<endl;
	}
	cout<<" \n";
	
	//0-1 pattern
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++){
			if((i+j) % 2 == 0){
				cout<<"1";
			}else {
				cout<<"0";
			}
		}
		cout<<endl;
	}
	cout<<" \n";
	
	//rhombus pattern
	for(i=1; i<=n; i++){
		for(j=1; j<=n+(n-i); j++){
			if(j>n-i){cout<<"*";
			}else{
				cout<<" ";
			}
			
		}
		cout<<endl;
	}
	
	
	cout<<endl;
	//Number patern
	for(i=1; i<=n; i++){
		for(j=1; j<=n-i; j++){
			cout<<" ";
		}
		for(j=1; j<=i; j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	//palindromic pattern
	int k;
	for(i=1; i<=n; i++){
		for(j=1; j<=n-i; j++){
			cout<<"  ";
		}
		int k=i;
		for(;j<n;j++){
			cout<<" "<<k--;
		}
		for(k=1;k<=i;k++){
			cout<<" "<<k;
		}
		cout<<endl;
	}
	
	cout<<endl;
	//1,2,3... pyramind pattern
	short count=1;
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++){
			cout<<count<<"\t";
			count++;
		}cout<<endl;
	}
	
	cout<<endl;
	//star pattern half triagle 
	for(short int i=1; i<=n; i++){
		for(short int j=1; j<=n; j++){
			if(j<=n-i) cout<<" ";
			else cout<<"*";
		}cout<<endl;
	}
	
	cout<<endl;
	//inverted star pattern half triagle 
	for(short int i=n; i>0; i--){
		short int temp=i;
		while(temp>0){
			cout<<"*";
			temp--;
		}
		cout<<endl;
	}
	
	cout<<endl;
	//empty rectangle patter of star
		int r=5,c=10;
		for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			if(i==1 || i==r || j==1 || j==c){ 
				cout<<"*";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}

	cout<<endl;
	//filled rectangle patter of star
	for(int i=0; i<r*c; i++) 	{
		cout<<"* \t";
		if(i%c==c-1) cout<<endl;
	}
	
	cout<<endl;
	//start pattern
	for(i=1; i<=n; i++){
		for(j=1; j<=n-i; j++){
			cout<<" ";
		}
		for(j=1; j<=i*2-1; j++){
			cout<<"*";
		}
		cout<<endl;
	}
	for(i=n; i>=1; i--){
		for(j=1; j<=n-i; j++){
			cout<<" ";
		}
		for(j=1; j<=i*2-1; j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
	cout<<endl;
	//zigzag pattern
	for(i=1; i<=3; i++){
		for(j=1; j<=n; j++)		{
			if((i+j)%4 == 0 || (i==2 && j%4==0)){
				cout<<"* ";
			}else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	return 0;
}

