#include<iostream>
#include<vector>
using namespace std;
int setbit(int no,int pos){
	return (no | (1<<pos));
}

int getbit(int no,int pos){
	return (no & (1<<pos));
}
int main(){
	vector<int> arr = {1,2,3,3,3,1,2,1,2,6};
	int sum=0,result=0;
	//checking all 64 bits of every elements
	for(int i=0; i<64; i++){
		sum=0;
		for(int j=0; j<arr.size(); j++){
			if(getbit(arr[j],i)){
				sum++;
			}
		}
		if(sum%3 != 0){
			result = setbit(result,i);
		}
	}
	cout<<"unique no in triplet -> "<<result;
	return 0;
}