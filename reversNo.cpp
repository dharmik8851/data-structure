#include<iostream>
using namespace std;

int main(){
	int n,origin,rev;
	cout<<"enter no->";cin>>n;
	origin=n;
	while(n>0){
		rev=rev*10 + (n%10);
		n/=10;
	}
	cout<<"rev is "<<rev;
	if(origin == rev){
		cout<<endl<<"no is palindrome";
	}
	return 0;
}