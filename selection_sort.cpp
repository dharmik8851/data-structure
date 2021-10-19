#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"How many elements do you want to enter -> "; cin>>n;
	cout<<"\nEnter "<<n<<" elements -> ";
	int arr[n];
	
	//take elemetns from users
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	int tc=0,tc1=0;//time complexity 
	//sorting using selection sort method
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			tc++;
			if(arr[i] > arr[j]){
				tc1++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	//print sorted elements
	cout<<endl<<"sorted elements -> ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl<<endl<<"how many times the loop executes -> "<<tc;
	cout<<endl<<endl<<"how many times code inside the loop executes -> "<<tc1;
	
}