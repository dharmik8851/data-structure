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
	
	int tc=0,tc2=0;
	//sort all elements using bubble sort method
	for(int k=1; k<n; k++){
		for(int i=0; i<n-k; i++){
			tc++;
			if(arr[i] > arr[i+1]){
				tc2++;
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	
	
	//print sorted elements
	cout<<endl<<"sorted elements -> ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl<<endl<<"how many times the loop executes -> "<<tc;
	cout<<endl<<endl<<"how many times code inside the loop executes -> "<<tc2;
}