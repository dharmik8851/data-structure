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
	
	int tc=0;//time complexity 
	//sort all elements using insertion sort method
	for(int i=1; i<n; i++){
		int current = arr[i];
		int j = i-1;
		while(arr[j] > current && j>=0){
			tc++;
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = current;
	}
	
	//print sorted elements
	cout<<endl<<"sorted elements -> ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl<<endl<<"how many times code inside the while loop executes -> "<<tc;
}