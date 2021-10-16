#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	bool p=true;
	cout<<"Enter no ->";cin>>n;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0){
			cout<<"No is not prime...";
			p=false;
			break;
		}else{
			p=true;
		}
	}
	if(p){
		cout<<"No is prime no....";
	}
	return 0;
}
