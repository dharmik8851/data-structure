#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"how many chars -> ";
	cin>>n;
	cin.ignore(); //clear one or more characters from the input buffer
	cout<<endl<<"Enter your sentance ->";
	char arr[n+1];
	cin.getline(arr,n+1);
	cin.ignore(); //clear one or more characters from the input buffer
	
	int i=0,j=0,currLen=0,maxLen=0;
	
	while(1){
		cout<<arr[i];
		if(arr[i] == ' ' or arr[i] == '\0'){
			if(currLen>maxLen){
				maxLen=currLen;
				j=i-maxLen;
			}
			currLen=0;
		}
		else currLen++;
		if(arr[i] == '\0') break;
		i++;
	}
	
	
	cout<<endl<<j<<" "<<maxLen<<endl;
	
	while(maxLen--){
		cout<<arr[j];
		j++;
	}
	return 0;
}