#include<iostream>
//#include<string>
//#include<stack>
#include "bits/stdc++.h"
using namespace std;

/*
redundant parentheses : given a valid mathematical expression,
find wheather it have redundant parentheses or not. it contain the
following operator +,-,*,/
*/

int main(){
	string s; cin>>s;
	stack<char> st;
	bool ans = false;
	
	for(int i=0; i<s.size(); i++){
		if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
			st.push(s[i]);
		}
		else if(s[i] == '('){
			st.push(s[i]);
		}
		else if(s[i] == ')'){
			if(st.top() == '(') ans=true;
			
			while(st.top() != '('){
				st.pop();
			}
			st.pop();
		}
	}
	
	cout<<endl<<ans;
	return 0;
}