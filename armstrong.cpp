#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n,origin,sum;
	cout<<"enter no -> "; cin>>n;
	origin = n;
	while(n>0){
		sum = sum + pow(n%10,3);
		n/=10;
	}
	cout<<sum<<endl;
	if(origin == sum){
		cout<<"no is armstrong...";
	}else{
		cout<<"no is not armstrong...";
	}
}