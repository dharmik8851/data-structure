#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
	stack<char> st;
	for(int i=0; i<s.length(); i++){
		if(s[i] == ')' && st.top() != '('){
			return false;
		}
		else if(s[i] == '}' && st.top() != '{'){
			return false;
		}
		else if(s[i] == ']' && st.top() != '['){
			return false;
		}
		else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
			st.pop();
		}
		else{
			st.push(s[i]);
		}
	}
	if(!st.empty()) return false;
	return true;
}

int main(){
	string s = "[{()}]";
	cout<<isValid(s);
}