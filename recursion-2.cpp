#include<iostream>
using namespace std;

//find all possible permutation of given string
void permutation(string s, string ans){
	if(s.length() == 0){
		cout<<endl<<ans;
		return;
	}
	for(int i=0; i<s.length(); i++){
		char ch = s[i];
		string ros = s.substr(0,i) + s.substr(i+1);
		permutation(ros,ans+ch);
	}
}

//count the number of paths possible from start point to end point in gamebaord(dice)
int countPath(int s, int e){
	if(s == e) return 1;
	if(s > e) return 0;
	int count=0;
	for(int i=1; i<=6; i++){
		count+=countPath(s+i,e);
	}
	return count;
}

//count no of paths in maze
int countPathMaze(int n, int i, int j){
	if(i>=n || j>=n) return 0;
	if(i==n-1 || j==n-1) return 1;
	return countPathMaze(n, i+1, j) + countPathMaze(n, i, j+1);
}

//knapsack problem
int knapsack(int wt[], int val[], int n, int W){
	if(n==0 || W==0) return 0;
	if(wt[n-1]>W) return knapsack(wt,val,n-1,W);
	return max(knapsack(wt,val,n-1,W),knapsack(wt,val,n-1,W-wt[n-1])+val[n-1]);
}

int main(){
	
	//permutation
	cout<<"all possible permutation of \"ABC\" -> ";
	permutation("ABC","");
	
	//count path 
	cout<<endl<<endl<<"possible ways to go from 0 to 3 in board using dice is -> "<<countPath(0,3);
	
	//count no of paths in maze
	cout<<endl<<endl<<"no of paths in 3 by 3 maze is -> "<<countPathMaze(3,0,0);
	
	//kanpsack problem
	cout<<endl<<endl;
	int wt[] = {10,20,30};
	int val[] = {100,50,150};
	cout<<"knapsack problem -> "<<knapsack(wt,val,3,20);
	
	return 0;
}