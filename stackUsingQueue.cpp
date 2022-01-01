#include<iostream>
#include<queue>
using namespace std;

class Stack{
	queue<int> q1;
	queue<int> q2;
	int N;
	
	public:
		Stack(){
			N=0;	
		}
		
		void push(int x){
			N++;
			q2.push(x);
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
			queue<int> temp = q1;
			q1 = q2;
			q2 = temp;
		}
		
		void pop(){
			if(q1.empty()){
				cout<<"queue underflow";
				return;
			}
			q1.pop();
			N--;
		}
		
		int size(){
			return N;
		}
		
		int top(){
			if(q1.empty()){
				cout<<"queue underflow";
				return -1;
			}
			return q1.front();
		}
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	
	cout<<s.size()<<endl;
	
	cout<<s.top()<<endl;
	s.pop();
	
	return 0;
}