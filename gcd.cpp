#include<iostream>
using namespace std;
void printGCD(int a,int b){
	int rem;
	while(b!=0){
		rem = a%b;
		a=b;
		b=rem;
	}
	cout<<"greatest comman divisor is "<<a;
}
int main(){
	cout<<"enter first no -> ";
	int a; cin>>a;
	cout<<endl<<"enter first no -> ";
	int b; cin>>b;
	printGCD(a,b);
	return 0;
}