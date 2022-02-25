#include<iostream>
using namespace std;

void printPrimeSieve(int n){
	bool arr[n+1] = {0};
	for(int i=2; i<=n; i++){
		if(arr[i] == false){
			for(int j=i*i; j<=n; j+=i){
			arr[j]=true;
			}	
		}	
	}
	
	cout<<endl<<"prime numbers -> ";
	for(int i=2; i<=n; i++){
		if(arr[i] == false){
			cout<<" "<<i;
		}
	}
}

void primeFactors(int n){
	int spf[n+1];
	
	//initializing smallest prime factors
	for(int i=2; i<=n; i++){
		spf[i] = i;
	}
	
	//this for loop will found smallest prime factor for 2-n numbers
	for(int i=2; i<=n; i++){
		if(spf[i] == i){
			for(int j=i*i; j<=n; j+=i){
				spf[j] = i;
			}
		}
	}
	
	//this while loop will print all prime factors of given no
	cout<<endl<<"prime factors of "<<n<<" is -> ";
	while(n!=1){
		cout<<spf[n]<<" ";
		n = n/spf[n];
	}
}
int main(){
	int n;
	cout<<"Enter no -> ";
	cin>>n;
	printPrimeSieve(n);
	primeFactors(n);
	return 0;
}