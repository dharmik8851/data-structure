#include<iostream>
using namespace std;

int possiblePartition(int boards[], int n, int limit){
	int painters=1, sum=0;

	for(int i=0; i<n; i++){
		sum += boards[i];
		if(sum>limit){
			sum=boards[i];
			painters++;
		}
	}

	return painters;
}

int partitionPainter(int boards[], int n, int m){
	int totalLength=0, maxBoard=0;

	for(int i=0; i<n; i++){
		totalLength+=boards[i];
		maxBoard = max(maxBoard, boards[i]);
	}

	int high=totalLength, low=maxBoard;

	while(low<high){
		int mid=(low+high)/2;
		int painters = possiblePartition(boards, n, mid);
		if(painters<=m){
			high = mid;
		}
		else{
			low = mid+1;
		}
	}

	return low;
}

int main(){
	int boards[] = {12,34,67,90};
	int n=4;
	int m=2; //no of painter


	cout<<"no of painters -> "<<partitionPainter(boards, n, m);
	return 0;
}