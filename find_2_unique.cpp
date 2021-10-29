#include<iostream>
#include<vector>
using namespace std;

int main(){
	//find two unique no in an array
	vector<int> arr =  {1,2,3,4,5,6,5,4,3,2,1,7};
	int xorsum = 0;
	//this for loop give you xor sum of all elements 
	//which is the xor addition of two unique no.
	//e.g here xorsum = 1 becaues two unique no are 6 and 7
	for(int i=0; i<arr.size(); i++){
		xorsum = xorsum ^ arr[i];
	}
	cout<<endl<<"xorsum -> "<<xorsum;
	int temp = xorsum;
	int setbit = 0,pos=0;
	//take position of first bit which is set from xorsum
	while(setbit != 1){
		if(xorsum & 1){
			setbit = 1;
		}
		xorsum>>1;
		pos++;
	}
	cout<<endl<<"position of first bit which is set from xorsum -> "<<pos-1;
	int tempSum=0;
	//for first unique number
	//perform xor addition of elements which have set bit at pos.
	for(int i=0; i<arr.size(); i++){
		if(arr[i] & (1<<pos-1)){
			tempSum = tempSum ^ arr[i];
		}
	}
	
	cout<<endl<<"first unique number -> "<<tempSum;
	//for second unique number perform xor addition of total-xor-sum and first-unique-number
	cout<<endl<<"second unique number -> "<<(tempSum^temp);
	return 0;
}