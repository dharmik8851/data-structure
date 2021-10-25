#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of your string you want to enter->";
	cin>>n;
	char arr[n+1];
	cout<<"Enter word -> "; cin>>arr;
	
	short int i=0;
	bool check=true;
	while(arr[i] != '\0'){
		if(arr[i] != arr[n-1-i]) {
			check = false;
			break;
		}
		i++;
	}
	if(check){
		cout<<endl<<"word is palindrom";
	}else cout<<endl<<"word is not palindrom";
	
	return 0;
}