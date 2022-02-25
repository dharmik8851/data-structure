#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int random(int a){
	int num=(rand() % (a+1));
	return num;
}

int function(int n){
	//cout<<" function call \n";
	int i;
	if(n<=0){return 0;
	}else{
		i=random(n-1);
		cout<<" this\n";
		return function(i)+function(n-1-i);
	}
}

int main(){
	cout<<function(3);
	return 0;
}