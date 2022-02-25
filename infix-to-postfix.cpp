#include<iostream>
#include<stack>
using namespace std;

int prec(char op){
	if(op=='^') return 3;
	else if(op=='/' || op=='*') return 2;
	else if(op=='+' || op=='-') return 1;
	else return -1;
}

string infix_to_postfix(string s){
	stack<char> st;
	string res;
	for(int i=0; i<s.length(); i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			res+=s[i];
		}
		else if(s[i]=='('){
			st.push('(');
		}
		else if(s[i]==')'){
			while(st.top()!='('){
				res+=st.top();
				st.pop();
				
			}
			st.pop();
		}
		else{
			while(!st.empty() && prec(st.top()) > prec(s[i]) ){
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}

int main(){
	cout<<"(a-b/c)*(a/k-l)"<<endl;
	cout<<infix_to_postfix("(a-b/c)*(a/k-l)");
}