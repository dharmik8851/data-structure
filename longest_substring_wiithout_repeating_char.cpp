#include<iostream>
#include "bits/stdc++.h"
#include<vector>
using namespace std;

/*
Given a string s, find the length of the 
longest substring without repeating characters.
*/

int main(){
	string s;
	cout<<"enter string -> ";
	cin>>s;	
	
	vector<int> dict(256,-1);
	int maxlen=0,start=-1;
	
	for(int i=0; i<s.size(); i++){
		if(dict[s[i]] > start){
			start = dict[s[i]];
		}
		dict[s[i]] = i;
		maxlen=max(maxlen,i-start);
	}
	
	cout<<endl<<maxlen;
	return 0;
}